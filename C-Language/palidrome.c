#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int arg,char *argv[]){
	char *strings;
	int i=0;
	int result=1;
	printf("Give me a string: "); scanf("%s",strings);
	int length=strlen(strings);
	printf("The input strings: %s  - Length: %d \n",strings,length);
	for(i=0;i<length;i++){
		if(strings[i]!=strings[length-i-1]){
			printf("The input strings isn't palidrome! \n");
			exit(0);
		} 
	}
	printf("The input strings is palidrome! \n");
	return 0;
}
