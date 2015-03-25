#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <getopt.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include "http_parser.h"
#include <htmlstreamparser.h>
#include "zlib.h"

#if defined(__APPLE__)
# undef strlcat
# undef strlncpy
# undef strlcpy
#endif  /* defined(__APPLE__) */

typedef struct
{
        unsigned char *data;
        size_t data_len;
        char *path;
//        http_parser * parser;
} peer_info_t , *ppeer_info_t;

typedef struct 
{
  http_parser parser[2];
} stream_parser_t;

typedef struct 
{
  char hfield[1024];
  char hvalue[16 * 1024];
  int content_type;
  int content_encoding;
  int pre_processor_type;
  int processor_type;
  void * pre_processor;
  void * processor;
} stream_processor_t;

typedef struct 
{
  char tag[64];
  char attr[64];
  char val[2048 + 1];
  HTMLSTREAMPARSER * hsp;
} html_parser_t;

#define CHUNK 16384

typedef struct 
{
  int ret;
  unsigned char out[CHUNK];
  z_stream strm;
} gzip_processor_t;

/* Client to Server and Server to Client */
#define C2S 0
#define S2C 1

#undef TRUE
#define TRUE 1
#undef FALSE
#define FALSE 0

#define MAX_HEADERS 13
#define MAX_ELEMENT_SIZE 2048

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int parser_execute(http_parser *parser,
  const http_parser_settings *settings,
  const char *data,
  size_t len);

http_parser_settings * get_settings();

inline static void * init_html_parser() {
  html_parser_t * hp = (html_parser_t *) calloc( 1, sizeof(html_parser_t));
  hp->hsp = html_parser_init();

  html_parser_set_tag_to_lower(hp->hsp, 1);
  html_parser_set_attr_to_lower(hp->hsp, 1);
  html_parser_set_tag_buffer(hp->hsp, hp->tag, sizeof(hp->tag));
  html_parser_set_attr_buffer(hp->hsp, hp->attr, sizeof(hp->attr));
  html_parser_set_val_buffer(hp->hsp, hp->val, sizeof(hp->val)-1);

  return (void *) hp;
}

inline static void reset_html_parser(html_parser_t * hp) {
  html_parser_reset(hp->hsp);
}

void html_parse(const char * chunck, size_t len, html_parser_t * hp, http_parser *p);

inline static void * clean_html_parser(html_parser_t * hp) {
  if( hp == NULL) return NULL;
  html_parser_cleanup(hp->hsp);
  free (hp);
  return NULL;
}

inline static void * init_gzip_processor() {
  gzip_processor_t * gzp = (gzip_processor_t *) calloc( 1, sizeof( gzip_processor_t ) );
  gzp->strm.zalloc = Z_NULL;
  gzp->strm.zfree = Z_NULL;
  gzp->strm.opaque = Z_NULL;
  gzp->strm.avail_in = 0;
  gzp->strm.next_in = Z_NULL;
  gzp->ret = inflateInit2(& gzp->strm, 16+MAX_WBITS);
  if (gzp->ret != Z_OK) {
    free( gzp );
    return NULL;
  }
  return gzp;
}

void gzip_process( const char * chunck, size_t len, gzip_processor_t * hp, http_parser *p );

inline static void * clean_gzip_processor( gzip_processor_t * gzp ) {
  if( gzp == NULL ) return NULL;
  (void)inflateEnd(& gzp->strm);
  free( gzp );
  return NULL;
}

inline static void * init_stream_processor()
{
  stream_processor_t * sp = (stream_processor_t *) calloc( 1, sizeof( stream_processor_t ) );
  return (void *) sp;
}

void * start_stream_processor();
void * clean_stream_processor();

inline static void * close_stream_processor(stream_processor_t * sp) {
  if( sp->processor ) sp->processor = clean_html_parser( (html_parser_t *) sp->processor );
  free( sp );
  return NULL;
}


inline static stream_parser_t * init_stream_parser() {
  stream_parser_t * parser = (stream_parser_t *) malloc(sizeof(stream_parser_t));
  http_parser_init(& parser->parser[0], HTTP_BOTH);
  http_parser_init(& parser->parser[1], HTTP_BOTH);
  parser->parser[0].data = init_stream_processor();
  parser->parser[1].data = init_stream_processor();
  return parser;
}

inline static void * close_stream_parser(stream_parser_t * sp) {
  if( sp->parser[0].data ) sp->parser[0].data = close_stream_processor(sp->parser[0].data);
  if( sp->parser[1].data ) sp->parser[1].data = close_stream_processor(sp->parser[1].data);
  free( sp );
  return NULL;
}

