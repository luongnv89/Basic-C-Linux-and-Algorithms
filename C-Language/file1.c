# include <stdio.h>

extern int x ;

void function1 ( )
{
	x += 5 ;

	printf ( "x = %d\n", x ) ;
}
