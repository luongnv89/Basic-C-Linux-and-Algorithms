#include<stdio.h>
#include<math.h>
int main(){
int multiple(int);
int n;
printf("Give me an interger: "); scanf("%d",&n);
printf("\n The result: %d \n",multiple(n));
return 0;
}
int multiple(int n)
{
	int i=0,sum=0;
	for(i=1;i<=n;i++)
	{
		if(n%i==0) 
			{		
				sum = sum + pow(2,i);
			}
	}
	return sum;
}
