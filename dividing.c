# include <stdio.h>

int dividing ( int n )
{
	int i, ret ;

	for ( i = 1, ret = 0 ; i < 32 ; i ++ )
		ret |= ( ( ! ( n % i ) ) << i ) ;
	return ret ;
}

int main ( int argc, char * argv [ ] )
{
	int number ;

	printf ( "Give me a number : " ) ;
	scanf ( "%d", & number ) ;
	printf ( "F ( %d ) = %d\n", number, dividing ( number ) ) ;
	return 0 ;
}
