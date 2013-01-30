# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
 
void count ( FILE * fd, int * c, int * w, int * l )
{
	int g, i ;
 
	* c = i = * l = * w = 0 ;
	while ( ! feof ( fd ) ) {
		g = fgetc ( fd ) ;
		( * c ) ++ ;
		if ( g == '\n' )
			( * l ) ++ ;
		if ( isalpha ( g ) && ! i )
			( * w ) ++, i = 1 ;
		if ( ! isalpha ( g ) )
			i = 0 ;
	}
}

void display ( int c, int tc, int w, int tw, int l, int tl, char * file )
{
	if ( tc )
		printf ( "%8d ", c ) ;
	if ( tw )
		printf ( "%8d ", w ) ;
	if ( tl )
		printf ( "%8d ", l ) ;
	printf ( "%s\n", file ) ;
}
 
extern int optind ;

int main ( int argc, char * argv [ ] )
{
	FILE * fd ;
	int c, i, l, nb, opt, sc, sl, sw, tc, tl, tw, w ;

	tc = tl = tw = 0 ;
	while ( ( opt = getopt ( argc, argv, "clw" ) ) != -1 )
		switch ( opt ) {
		case 'c' :
			tc = 1 ;
			break ;
		case 'l' :
			tl = 1 ;
			break ;
		case 'w' :
			tw = 1 ;
			break ;
		}
	if ( ! tc && ! tl && ! tw )
		tc = tl = tw = 1 ;
 
	if ( optind == argc ) {
		argv [ argc ++ ] = "-" ;
		argv [ argc ] = NULL ;
	}

	nb = sc = sl = sw = 0 ;
	for ( i = optind ; i < argc ; i ++ )
		if ( strcmp ( argv [ i ], "-" ) == 0 ) {
			count ( stdin, & c, & w, & l ) ;
			display ( c, tc, w, tw, l, tl, "-" ) ;
			nb ++ ; sc += c ; sl += l ; sw += w ;
		} else {
			fd = fopen ( argv [ i ], "r" ) ;
			if ( fd ) {
				count ( fd, & c, & w, & l ) ;
				fclose ( fd ) ;
				display ( c, tc, w, tw, l, tl, argv [ i ] ) ;
				nb ++ ; sc += c ; sl += l ; sw += w ;
			} else
				perror ( argv [ i ] ) ;
		}
	if ( nb > 1 )
		display ( sc, tc, sw, tw, sl, tl, "total" ) ;

	return 0 ;
}
