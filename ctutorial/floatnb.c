#include <stdio.h>
#include <float.h>
int main(){
	printf("Size of float: %d \n",sizeof(float));
	printf("Minimum float possitive value: %E\n",FLT_MIN);
	printf("Maximum float possitive value: %E\n",FLT_MAX);
	printf("Precision value: %d\n",FLT_DIG);
	return 0;
}
