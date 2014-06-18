/*
 *
 *
 *
 *
 * */

#include<stdio.h>

int main()
{
	int prime[50];
	
//add element into array
	int i;
	for(i = 0; i < 50; i++)
	{
		prime[i] = 1;
	}

//change status 

	int j;
	int k;
	for(j = 2; j*j < 50; j++)
	{
		if(prime[j] == 1)
		{
			for(k = j*j; k < 50; k = k + j)
			{
				prime[k]  = 0;
			}
		}
	}
	
//print prime
	int l;
	for(l = 0; l < 50; l++)
		printf("%d : %d\n",l,prime[l]);
return 0;
}
