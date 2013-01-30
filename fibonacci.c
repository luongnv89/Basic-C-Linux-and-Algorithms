# include <stdio.h>
# include <unistd.h>

int main ( int argc, char * argv [ ] )
{
	int F, Fm1, Fm2, i, n ;

	do {
		printf ( "How many elements do you want : " ) ;
		scanf ( "%d", & n ) ;
	} while ( n < 1 ) ;
	F = Fm1 = Fm2 = 1 ;
	printf ( "F ( 0 ) = 1\n" ) ;
	printf ( "F ( 1 ) = 1\n" ) ;
	for ( i = 2 ; i < n ; i ++ ) {
		Fm2 = Fm1 ; Fm1 = F ; F = Fm1 + Fm2 ;
		printf ( "F ( %d ) = %d\n", i, F ) ;
	}
	return 0 ;
}
