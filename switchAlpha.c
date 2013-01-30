#include <stdio.h>
#include <ctype.h>

void main()
{
	char c;
	printf("Input a letter: ");scanf("%d",&c);
	if (isalpha(c)){
		printf("You have just entered an alpha letter!\n");
		if(tolower(c))
			printf("UPPER-CASE \n");
		else
			printf("lower-case!\n");
	}
	else

		printf("You didn't enter an alpha letter\n");
	switch(isalpha(c)){
		case true:
		{	
			printf("You have just entered an alpha letter!\n");
			break;
		}
		case false:
		{
			printf("You didn't enter an alpha letter\n");
			break;
		}
		default:
			printf("Sorry, I don't know!");
	}
}
