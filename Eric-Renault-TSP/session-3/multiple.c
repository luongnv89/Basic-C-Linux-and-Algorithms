# include <stdio.h>

void multiple ( int n )
{
	int i ;

	printf ( "Here is the multiplication table of %d :\n", n ) ;
	for ( i = 1 ; i <= 10 ; i ++ )
		printf ( "%d x %d = %d\n", i, n, n * i ) ;
}

int main ( int argc, char * argv [ ] )
{
	int number ;

	printf ( "Which number : " ) ;
	scanf ( "%d", & number ) ;
	multiple ( number ) ;
	return 0 ;
}
