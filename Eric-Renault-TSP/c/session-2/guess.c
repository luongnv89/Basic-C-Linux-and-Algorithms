# include <stdio.h>
# include <stdlib.h>

int main ( int argc, char * argv [ ] )
{
	int c, n ;

	srandom ( getpid ( ) ) ;
	n = random ( ) % 101 ;
	do {
		printf ( "Can you find my number ? " ) ;
		scanf ( "%d", & c ) ;
		if ( c < n )
			printf ( "Mine is bigger !\n" ) ;
		if ( c > n )
			printf ( "Mine is smaller !\n" ) ;
	} while ( c != n ) ;
	printf ( "Congratulations, you've got it !!!\n" ) ;
	return 0 ;
}
