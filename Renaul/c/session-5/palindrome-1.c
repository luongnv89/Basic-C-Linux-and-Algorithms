# include <stdio.h>
# include <string.h>

int is_palindrome ( char * s )
{
	int i, j ;

	for ( i = 0, j = strlen ( s ) - 1 ; i < j ; i ++, j -- )
		if ( s [ i ] != s [ j ] )
			break ;
	return i >= j ;
}

int main ( int argc, char * argv [ ] )
{
	char string [ 256 ] ;

	printf ( "Give a string : " ) ;
	scanf ( "%s", string ) ;
	printf (
		"\"%s\" is%s a palindrome\n",
		string,
		is_palindrome ( string ) ? "" : " not"
	) ;
	return 0 ;
}
