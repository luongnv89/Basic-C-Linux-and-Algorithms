# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "stack.h"
 
int add ( int a, int b )
{
	return a + b ;
}
 
int substitute ( int a, int b )
{
	return a - b ;
}
 
int multiply ( int a, int b )
{
	return a * b ;
}
 
int divide ( int a, int b )
{
	if ( b == 0 ) {
		perror ( "Cannot divide by 0" ) ;
		exit ( 1 ) ;
	}
	return a / b ;
}
 
int mod ( int a, int b )
{
	if ( b < 2 ) {
		perror ( "Modulo must be greater than 1" ) ;
		exit ( 1 ) ;
	}
	return a % b ;
}
int main ( int argc, char * argv [ ] )
{
	char * end, string [ 32 ] ;
	int ( * binop [ 256 ] ) ( int, int ) //# int  * binop [ 256 ]  ( int, int )
	int i, left, right, stop, value ;
	stack s ;
 
	for ( i = 0 ; i < 256 ; i ++ )
		binop [ i ] = NULL ;
	binop [ '+' ] = add ;
	binop [ '-' ] = substitute ;
	binop [ '*' ] = multiply ;
	binop [ '/' ] = divide ;
	binop [ '%' ] = mod ;
 
	s = new ( ) ;
	do {
		do
			stop = scanf ( "%s", string ) ;
		while ( ( stop != EOF ) && ! ( string [ 0 ] ) ) ;
		if ( stop == EOF )
			break ;
		value = strtol ( string, & end, 10 ) ;
		if ( ! * end )
			s = push ( s, value ) ;
		else {
			if ( string [ 1 ] != '\0' ) {
				fprintf ( stderr, "%s is not a number\n", string ) ;
				exit ( 1 ) ;
			}
			if ( binop [ string [ 0 ] ] ) {
				right = top ( s ) ; s = pop ( s ) ;
				left  = top ( s ) ; s = pop ( s ) ;
				s = push (
					s, ( * binop [ string [ 0 ] ] ) ( left, right )
				) ;
			} else
				switch ( string [ 0 ] ) {
				case 'p' :
					printf ( "%d\n", top ( s ) ) ;
					break ;
				case 'q' :
					break ;
				default :
					fprintf (
						stderr, "Unknown operation %c\n", string [ 0 ]
					) ;
					exit ( 1 ) ;
				}
		}
	} while ( string [ 0 ] != 'q' ) ;
	return 0 ;
}
