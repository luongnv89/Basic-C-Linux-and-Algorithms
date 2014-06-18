#include<stdio.h>
void main(){
	int s0,sMax,n1,n2,n,i=0,s;
	printf("Enter s0 = ");scanf("%d",&s0);
	s = s0;
	printf("\n Enter n = "); scanf("%d",&n);
	printf("\n s(%d) = %d",0,s0);
	printf("\n n-th element of the sn series");
	for (i=1;i<n;i++){
		if(s%2==0) s = s/2;
		else s = 3*s +1;
		printf("\n s(%d) = %d",i,s);
	}
	printf("\n*********************************");
	s = s0;
	n1=1;
	n2=0;
	sMax=s0;
	while(s>1){
		if(s%2==0) s = s/2;
		else s=3*s + 1;
		if (s>sMax) sMax = s;
		printf("\n s(%d) = %d",n1,s);
		n1++;
		if(s<s0) n2++;
	}
	
	printf("\n The number of interation before reaching 1 is : %d \n",n1);
	printf("\n The number of interation before reaching 1 value which is less then %d : %d \n",s0,n2);
	printf("sMax = %d \n",sMax);
	
}
