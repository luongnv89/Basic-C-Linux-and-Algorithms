# include <stdio.h>

int main ( int argc, char * argv [ ] )
{
	int toto = 100 ;
	int * ptr ;

	ptr = & toto ;
	printf ( "toto = %d\n", toto ) ;
	printf ( "* ptr = %d\n", * ptr ) ;
	printf ( "& toto = 0x%x\n", & toto ) ;
	printf ( "ptr = 0x%x\n", ptr ) ;
	return 0 ;
}
