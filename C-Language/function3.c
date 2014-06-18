#include<stdio.h>
int totalSum = 0;
int main()
{
	int sum(int);
	printf("%d \n",sum(3));
	printf("%d \n",sum(40));
	printf("%d \n",sum(500));
	printf("%d \n",sum(6000));
	return 0;
}
int sum(int n)
{
	totalSum +=n;
	return totalSum;
}
