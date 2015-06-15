#include <stdio.h>
#include <limits.h>
int main(){
	printf("Size of char: %d\n",sizeof(char));
	printf("Size of unsigned char: %d\n",sizeof(unsigned char));
	printf("Size of signed char: %d\n",sizeof(signed char));
	printf("Size of int: %d\n",sizeof(int));
	printf("Size of unsigned int: %d\n",sizeof(unsigned int));
	printf("Size of short: %d\n",sizeof(short));
	printf("Size of unsigned short: %d\n",sizeof(unsigned short));
	printf("Size of long: %d\n",sizeof(long));
	printf("Size of unsigned long: %d\n",sizeof(unsigned long));
	printf("Size of float: %d\n",sizeof(float));
	printf("Size of double: %d\n",sizeof(double));
	printf("Size of long double: %d\n",sizeof(long double));
	return 0;
}

