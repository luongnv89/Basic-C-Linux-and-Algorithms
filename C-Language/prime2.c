#include<stdio.h>

int main(){

	int i,j,k;
	int prime[50];

	for(k = 0; k < 50; k++){
		prime[k] = 1;
	}

	for(i=2;i<=25;i++){
		if(prime[i] == 1){
		for(j= i*2;j <= 50; j++){
			if(prime[j] == 1){
			if(j%i == 0)
				prime[j] = 0;
			
			}
		}
		}
	}

	int l;
	for(l=0; l < 50; l++){
		printf("%d : %d\n",l,prime[l]);
	}
return 0;
}
