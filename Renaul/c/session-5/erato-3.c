# include <stdio.h>
# include <stdlib.h>

int main ( int argc, char * argv [ ] )
{
	char * prime ;
	int n, i, j ; 

	printf ( "Gimme the size of the sieve : " ) ;
	scanf ( "%d", & n ) ;

	prime = ( char * ) malloc ( n * sizeof ( char ) ) ;

	for ( i = 0 ; i < n ; i ++ )
		prime [ i ] = 1 ;

	for ( i = 2 ; i * i < n ; i ++ )
		if ( prime [ i ] )
			for ( j = i * i ; j < n ; j += i )
				prime [ j ] = 0 ;

	printf ( "Prime numbers are" ) ; 
	for ( i = 2 ; i < n ; i ++ )
		if ( prime [ i ] )
			printf ( " %d", i ) ;
	printf ( "\n" ) ;

	free ( prime ) ;

	return 0 ;
}
