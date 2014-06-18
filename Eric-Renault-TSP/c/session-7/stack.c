# include <stdio.h>
# include <stdlib.h>
# include "stack.h"

stack new ( )
{
	return NULL ;
}
 
int is_empty ( stack s )
{
	return ! s ;
}
 
stack push ( stack s, int v )
{
	struct element * new ;
 
	new = ( struct element * ) malloc ( sizeof ( struct element ) ) ;
	new -> value = v ;
	new -> next = ( struct element * ) s ;
	return ( stack ) new ;
}
 
stack pop ( stack s )
{
	struct element * next ;
 
	if ( is_empty ( s ) ) {
		perror ( "stack is empty" ) ;
		exit ( 1 ) ;
	}
	next = s -> next ;
	free ( s ) ;
	return next ;
}
 
int top ( stack s )
{
	if ( is_empty ( s ) ) {
		perror ( "stack is empty" ) ;
		exit ( 1 ) ;
	}
	return s -> value ;
}
