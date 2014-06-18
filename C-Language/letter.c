# include <ctype.h>
# include <stdio.h>

int main ( int argc, char * argv [ ] )
{
	char c ;

	printf ( "Give me a letter : " ) ;
	scanf ( "%c", & c ) ;

	if ( isalpha ( c ) )
		switch ( tolower ( c ) ) {
		case 'a' : case 'e' : case 'i' : case 'o' : case 'u' :
			printf ( "This is a vowel.\n" ) ;
			break ;
		default :
			printf ( "This is a consonant.\n" ) ;
		}
	else
		printf ( "Unfortunately, this is not a letter.\n" ) ;

	return 0 ;
}
