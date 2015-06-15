#include <stdio.h>

int main(){
	
	unsigned int a = 60; /* 60 = 0011 1100 */
	unsigned int b = 13; /* 13 = 0000 1101 */
	int c = 0;

	printf("a = %d; b = %d\n",a,b);
		
	c = a & b; /* 0000 1100 = 12 */
	printf("a & b = %d\n",c);
	
	c = a | b; /* 0011 1101 = 61 */
	printf("a | b = %d\n",c);
	
	c = a ^ b; /* 0011 0001 = 49 */	
	printf("a ^ b = %d\n",c);
	
	c = ~a; /* 11000011 = -61 */
	printf("~a = %d\n",c);

	c = a << 2; /* 1111 0000 = 240 */
	printf("a << 2 = %d\n",c);
	
	c = a >> 2; /* 0000 1111 */
	printf("a >> 2 = %d\n",c);
	
	return 0;
}
