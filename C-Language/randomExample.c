#include <stdio.h>
#include <stdlib.h>
void main()
{
	int i=0,j=0;
	int yournumber;
	printf("Enter your number: ");scanf("%d",&yournumber);
	srand(getpid());
	do{
		i=random()%100;
		printf("%d ",i);
		j++;
	}
	while(i != yournumber);
	printf("\n The number of loops is %d \n",j);
}
