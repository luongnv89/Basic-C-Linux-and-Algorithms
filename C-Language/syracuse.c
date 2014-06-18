# include <stdio.h>
# include <unistd.h>

int main ( int argc, char * argv [ ] )
{
	int c, k, i, n, r ;

	do {
		printf ( "\t\tMenu\n" ) ;
		printf ( "1. Display the n-th element\n" ) ;
		printf ( "2. Display the number of steps before reaching 1\n" );
		printf ( "3. Display the flying value\n" ) ;
		printf ( "4. Display the highest value\n" ) ;
		printf ( "5. Quit\n" ) ;
		printf ( "\n" ) ;
		printf ( "Make your choice :\n" ) ; scanf ( "%d", & c ) ;
		switch ( c ) {
		case 1 :
			printf ( "Gimme the number : " ) ; scanf ( "%d", & n ) ;
			printf ( "Gimme the rank : " ) ; scanf ( "%d", & r ) ;
			for ( i = 0 ; i < r ; i ++ )
				n = ( n & 1 ? 3 * n + 1 : n >> 1 ) ;
			printf ( "The result is %d\n", n ) ;
			break ;
		case 2 :
			printf ( "Gimme the number : " ) ; scanf ( "%d", & n ) ;
			for ( i = 0 ; n != 1 ; i ++ )
				n = ( n & 1 ? 3 * n + 1 : n >> 1 ) ;
			printf ( "The result is %d\n", i ) ;
			break ;
		case 3 :
			printf ( "Gimme the number : " ) ; scanf ( "%d", & n ) ;
			for ( i = 0, k = n ; k >= n ; i ++ )
				k = ( k & 1 ? 3 * k + 1 : k >> 1 ) ;
			printf ( "The result is %d\n", i ) ;
			break ;
		case 4 :
			printf ( "Gimme the number : " ) ; scanf ( "%d", & n ) ;
			k = n;
			do {
				n = ( n & 1 ? 3 * n + 1 : n >> 1 ) ;
				if ( n > k )
					k = n ;
			} while ( n != 1 ) ;
			printf ( "The result is %d\n", k ) ;
			break ;
		case 5 :
			break ;
		default :
			printf ( "This is not a correct choice !\n" ) ;
		}
	} while ( c != 5 ) ;
	return 0 ;
}
