#include <stdio.h>

struct{
	unsigned int age:3;
}Age;

int main(){
	Age.age = 4;
	printf("Size of age: %lu\n",sizeof(Age));
	printf("value: %d\n",Age.age);
	Age.age = 13;
	printf("value: %d\n",Age.age);
	Age.age = 7;
	printf("value: %d\n",Age.age);
	return 0;
}
