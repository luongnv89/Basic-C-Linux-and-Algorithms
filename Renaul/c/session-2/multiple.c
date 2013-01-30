# include <stdio.h>

int main ( int argc, char * argv [ ] )
{
	int i ;

	printf ( "Give me an integer : " ) ;
	scanf ( "%d", & i ) ;
	printf ( "%d is %s a multiple of 2\n", i, ( i & 1 ? "not" : "" ) ) ;
	printf ( "%d is %s a multiple of 3\n", i, ( i % 3 ? "not" : "" ) ) ;
	printf ( "%d is %s a multiple of 4\n", i, ( i & 3 ? "not" : "" ) ) ;
	printf ( "%d is %s a multiple of 5\n", i, ( i % 5 ? "not" : "" ) ) ;
	printf ( "%d is %s a multiple of 6\n", i, ( i % 6 ? "not" : "" ) ) ;
	printf ( "%d is %s a multiple of 7\n", i, ( i % 7 ? "not" : "" ) ) ;
	printf ( "%d is %s a multiple of 8\n", i, ( i & 7 ? "not" : "" ) ) ;
	printf ( "%d is %s a multiple of 9\n", i, ( i % 9 ? "not" : "" ) ) ;
	return 0 ;
}
