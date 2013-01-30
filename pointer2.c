#include<stdio.h>

int main(){
	int a = 3;
	int b = 4;
	void swap(int *pa,int *pb);
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	swap(&a,&b);
	printf("a = %d\n",a);
	printf("b = %d\n",b);

	return 0;
}

void swap(int *pa, int *pb){
	int c;	
	c=*pa;
	*pa=*pb;
	*pb=c;
}
