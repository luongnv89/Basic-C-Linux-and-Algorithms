#include<stdio.h>
void main()
{
	int n,i;
	int F1,F2,F;
	F1=F2=1;
	printf("n= ");scanf("%d",&n);
	printf("\n F(%d) = 1",0);
	printf("\n F(%d) = 1",1);
	for(i=2;i<n;i++){
		F = F1+F2;
		printf("\n F(%d) = %d",i,F);
		F1=F2;
		F2=F;
	}
	printf("\n");
}
