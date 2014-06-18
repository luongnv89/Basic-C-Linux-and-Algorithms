# include <stdio.h>
# include <unistd.h>
 
int main ( int argc, char * argv [ ] )
{
	int i ;
	union {
		double value ;
		unsigned char byte [ sizeof ( double ) ] ;
	} number ;
 
	printf ( "Gimme a double : " ) ;
	scanf ( "%lf", & ( number . value ) ) ;
	printf ( "Values for each bytes are :" ) ;
	for ( i = sizeof ( double ) - 1 ; i >= 0 ; i -- )
		printf ( " 0x%02x", number . byte [ i ] ) ;
	printf ( "\n" ) ;
	return 0 ;
}
