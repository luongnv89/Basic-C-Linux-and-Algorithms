#include "http_integration.h"
#include <assert.h>

static inline int
check_str_eq (const char *expected,
              const char *found) {
  if ((expected == NULL) != (found == NULL)) {
    return 0;
  }
  if (expected != NULL && 0 != strncmp(expected, found, strlen(expected))) {
    return 0;
  }
  return 1;
}

int
message_begin_cb (http_parser *p)
{
  fprintf(stdout, "Message Begin CB called\n");
  return 0;
}

int
header_field_cb (http_parser *p, const char *buf, size_t len)
{
  stream_processor_t * sp = (stream_processor_t *) p->data; 
  //char temp[20048 + 1];
  strncpy(sp->hfield, buf, len);
  sp->hfield[len] = '\0';
  fprintf(stdout, "Header: %s : ", sp->hfield);
  return 0;
}

int
header_value_cb (http_parser *p, const char *buf, size_t len)
{
  stream_processor_t * sp = (stream_processor_t *) p->data;
  //char temp[20048 + 1];
  strncpy(sp->hvalue, buf, len);
  sp->hvalue[len] = '\0';
  if( check_str_eq( "Content-Type", sp->hfield) && check_str_eq( "text/html", sp->hvalue) ) sp->content_type = 1; //TODO: define
  if( check_str_eq( "Content-Encoding", sp->hfield) && check_str_eq( "gzip", sp->hvalue) ) sp->content_encoding = 1; //TODO: define
  fprintf(stdout, "%s\n", sp->hvalue);
  return 0;
}


int
request_url_cb (http_parser *p, const char *buf, size_t len)
{
  char temp[20408 + 1];
  strncpy(temp, buf, len);
  temp[len] = '\0';
  fprintf(stdout, "URL: %s\n", temp);
  return 0;
}

int
response_status_cb (http_parser *p, const char *buf, size_t len)
{
  char temp[20480 + 1];
  strncpy(temp, buf, len);
  temp[len] = '\0';
  fprintf(stdout, "Status: %s\n", temp);
  return 0;
}

int
count_body_cb (http_parser *p, const char *buf, size_t len)
{
  stream_processor_t * sp = (stream_processor_t *) p->data;

  fprintf(stdout, "Body CB called --- %u\n", len);
  //check_body_is_final(p);
  
  //Process body
  if( sp->content_encoding ) {
    if( sp->pre_processor ) {
      gzip_processor_t * gzp = (gzip_processor_t *) sp->pre_processor;
      gzip_process(buf, len, gzp, p);
    }
  } else if( sp->content_type && sp->processor ) {
    html_parser_t * hp = (html_parser_t *) sp->processor;
    html_parse(buf, len, hp, p);
  }
  
  return 0;
}

int
headers_complete_cb (http_parser *p)
{
  stream_processor_t * sp = (stream_processor_t *) p->data;

  fprintf(stdout, "Headers complete CB calledi\n");
  //http_should_keep_alive(parser);

  if( sp->content_encoding == 1 ) sp->pre_processor = (void *) init_gzip_processor();

  if( sp->content_type == 1 ) sp->processor = (void *) init_html_parser();

  return 0;
}

int
message_complete_cb (http_parser *p)
{
  stream_processor_t * sp = (stream_processor_t *) p->data;
  fprintf(stdout, "Message Complete CB calledi\n");

  if( sp->content_encoding == 1 ) sp->pre_processor = clean_gzip_processor(sp->pre_processor);

  if( sp->content_type == 1 ) sp->processor = clean_html_parser(sp->processor);

  return 0;
}

int parser_execute(http_parser *parser,
  const http_parser_settings *settings,
  const char *data,
  size_t len) {
  
  size_t nparsed = http_parser_execute(parser, settings, data, len);

  if (parser->upgrade) {
    /* handle new protocol */
  } else if (nparsed != len) {
    /* Handle error. Usually just close the connection. */
    fprintf(stdout, "Error while parsing this ghul -Error %s - ya mama\n", http_errno_description(HTTP_PARSER_ERRNO(parser)));
  }
  return nparsed;

}

static http_parser_settings settings =
{
  .on_header_field = header_field_cb
  ,.on_message_begin = message_begin_cb
  ,.on_header_value = header_value_cb
  ,.on_url = request_url_cb
  ,.on_status = response_status_cb
  ,.on_body = count_body_cb
  ,.on_headers_complete = headers_complete_cb
  ,.on_message_complete = message_complete_cb
};

http_parser_settings * get_settings() {
  return & settings;
}

void html_parse(const char * chunck, size_t len, html_parser_t * hp, http_parser *p) {
  stream_processor_t * sp = (stream_processor_t *) p->data;
  HTMLSTREAMPARSER * hsp = hp->hsp;

  fprintf(stdout, "FROM HTML PROCESS TEST 1\n");
  size_t i;
  for (i = 0; i < len; i++) {
    html_parser_char_parse(hsp, ((char *)chunck)[i]);
    if (html_parser_cmp_tag(hsp, "a", 1))
      if (html_parser_cmp_attr(hsp, "href", 4))
        if (html_parser_is_in(hsp, HTML_VALUE_ENDED)) {
          html_parser_val(hsp)[html_parser_val_length(hsp)] = '\0';
          printf("%s\n", html_parser_val(hsp));
        }
  }
  return;
}

/* report a zlib or i/o error */
void zerr(int ret)
{
    fputs("zpipe: ", stderr);
    switch (ret) {
    case Z_ERRNO:
        if (ferror(stdin))
            fputs("error reading stdin\n", stderr);
        if (ferror(stdout))
            fputs("error writing stdout\n", stderr);
        break;
    case Z_STREAM_ERROR:
        fputs("invalid compression level\n", stderr);
        break;
    case Z_DATA_ERROR:
        fputs("invalid or incomplete deflate data\n", stderr);
        break;
    case Z_MEM_ERROR:
        fputs("out of memory\n", stderr);
        break;
    case Z_VERSION_ERROR:
        fputs("zlib version mismatch!\n", stderr);
    }
}

/* Decompress from file source to file dest until stream ends or EOF.
   inf() returns Z_OK on success, Z_MEM_ERROR if memory could not be
   allocated for processing, Z_DATA_ERROR if the deflate data is
   invalid or incomplete, Z_VERSION_ERROR if the version of zlib.h and
   the version of the library linked do not match, or Z_ERRNO if there
   is an error reading or writing the files. */
void gzip_process( const char * chunck, size_t len, gzip_processor_t * gzp, http_parser *p )
{

  fprintf(stdout, "FROM GZIP PROCESS TEST 1\n");
  stream_processor_t * sp = (stream_processor_t *) p->data;
  unsigned have;

  gzp->strm.avail_in = len;
  if (gzp->strm.avail_in == 0) {
    fprintf(stdout, "Processing empty gzip chunck! check why the hell we got here\n");
    return;
  }
  gzp->strm.next_in = chunck;

  /* run inflate() on input until output buffer not full */
  do {
  fprintf(stdout, "FROM GZIP PROCESS TEST 2\n");
    gzp->strm.avail_out = CHUNK;
    gzp->strm.next_out = gzp->out;
    gzp->ret = inflate(& gzp->strm, Z_NO_FLUSH);
    assert(gzp->ret != Z_STREAM_ERROR);  /* state not clobbered */
    switch (gzp->ret) {
      case Z_NEED_DICT:
        gzp->ret = Z_DATA_ERROR;     /* and fall through */
      case Z_DATA_ERROR:
      case Z_MEM_ERROR:
        fprintf(stdout, "FROM GZIP PROCESS TEST 3\n");
        sp->pre_processor = clean_gzip_processor( gzp );
        zerr(gzp->ret);
        return;
    }
    have = CHUNK - gzp->strm.avail_out;
    fprintf(stdout, "FROM GZIP PROCESS TEST 4 --- have = %u --- content type %i\n", have, sp->content_type);
    if( sp->content_type && sp->processor ) {
      fprintf(stdout, "FROM GZIP PROCESS TEST 5\n");
      html_parser_t * hp = (html_parser_t *) sp->processor;
      html_parse(gzp->out, have, hp, p);
    }
  } while (gzp->strm.avail_out == 0);
}


