#include <stdio.h>

extern int a=10;;

void showGlobal(){
	printf("in showGlobal(): %d & %p \n",a,&a);
}
void myfunc(){
	int a=15;
	printf("in myfunc(): %d & %p\n",a,&a);
}

int main(){
	int a=12;
	printf("in main(): %d & %p\n",a,&a);
	myfunc();
	showGlobal();
	return 0;
}
