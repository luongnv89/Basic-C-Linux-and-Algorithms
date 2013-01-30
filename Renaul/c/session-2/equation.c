# include <math.h>
# include <stdio.h>

int main ( int argc, char * argv [ ] )
{
	double a, b, c, d ;

	printf ( "Give me the coefficients for equation ax² + bx + c = 0 :\n" ) ;
	printf ( "a = " ) ; scanf ( "%lf", & a ) ;
	printf ( "b = " ) ; scanf ( "%lf", & b ) ;
	printf ( "c = " ) ; scanf ( "%lf", & c ) ;

	d = b * b - 4 * a * c ;

	if ( d < 0 )
		printf ( "There is no solution in IR.\n" ) ;
	else
		if ( d > 0 )
			printf (
				"There are two solutions to this equation : %lf and %lf.\n",
				( - b - sqrt ( d ) ) / ( 2 * a ),
				( - b + sqrt ( d ) ) / ( 2 * a )
			) ;
		else
			printf (
				"There is one solution to this equation : %lf.\n",
				- b / ( 2 * a )
			) ;

	return 0 ;
}
