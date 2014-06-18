# include <stdio.h>

void swap ( int * x, int * y )
{
	int temp ;

	temp = * x ;
	* x = * y ;
	* y = temp ;
}

int main ( int argc, char * argv [ ] )
{
	int a = 3, b = 5 ;

	printf ( "a = %d ; b = %d\n", a, b ) ;
	swap ( & a, & b ) ;
	printf ( "a = %d ; b = %d\n", a, b ) ;
	return 0 ;
}
