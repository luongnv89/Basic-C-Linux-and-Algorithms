#include <stdio.h>
int main(){
	char strings[256];
	int i=0,j;
	int result=1;
	printf("Give me a string: "); scanf("%s",strings);
	int length=0;
	char ch;
	ch=strings[0];
	do{
		ch=strings[length++];
	}while(ch!='\0');
	length=length-1;
	printf("The input strings: %s  - Length: %d \n",strings,length);
	for(i=0;i<length;i++){
		if(strings[i]!=strings[length-i-1]) result=0;
	}
	
	if(result==0) printf("The input strings isn't palidrome! \n");
	else printf("The input strings is palidrome! \n");
	return 0;
}
