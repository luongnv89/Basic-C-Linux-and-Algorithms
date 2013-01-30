# include <stdio.h>

char prime [ 1000 ] ;

int main ( int argc, char * argv [ ] )
{
	int i, j ; 

	for ( i = 0 ; i < 1000 ; i ++ )
		prime [ i ] = 1 ;

	for ( i = 2 ; i < 1000 ; i ++ )
		for ( j = 2 ; i * j < 1000 ; j ++ )
			prime [ i * j ] = 0 ;

	printf ( "Prime numbers are" ) ; 
	for ( i = 2 ; i < 1000 ; i ++ )
		if ( prime [ i ] )
			printf ( " %d", i ) ;
	printf ( "\n" ) ;

	return 0 ;
}
