# include <stdio.h>

extern int x ;

void function1 ( ) ;

void function2 ( )
{
	x += 10 ;

	printf ( "x = %d\n", x ) ;
}

int main ( int argc, char * argv [ ] )
{
	x = 0 ;

	function1 ( ) ;
	function2 ( ) ;

	return 0 ;
}
