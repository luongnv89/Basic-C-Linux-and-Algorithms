# include <stdio.h>

int total = 0 ;

int sum ( int n )
{
	return total += n ;
}

int main ( int argc, char * argv [ ] )
{
	int value ;

	do {
		printf ( "Value to sum ? " ) ;
		scanf ( "%d", & value ) ;
		printf ( "The total sum is %d\n", sum ( value ) ) ;
	} while ( value ) ;
	return 0 ;
}
