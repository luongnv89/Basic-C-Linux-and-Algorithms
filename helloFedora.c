#include <stdio.h>
void main()
{
	printf("Hello Fedora \n");
	int i,j=0;
	printf("Input n: ");
	scanf("%d",&i);
	for(j=2;j<10;j++)
	{
		printf("%d is %s a multiple of %d \n", i, (i%j?"not":""),j);
	}
}
