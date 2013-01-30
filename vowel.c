#include <stdio.h>
void main()
{
	char ch;
	printf("Give me a letter: "); scanf("%c",&ch);
	if (isalpha(ch)){
	if(isupper(ch)){
		ch=tolower(ch);
	}
	switch(ch){
		case 'u': case 'e': case 'o': case 'a': case 'i':
			printf("%c is vowel\n",ch);
			break;
		default:
			printf("%c is consonant\n",ch); 
		}
	}
	else printf("%c isn't the alpha letter \n",ch);
}
