    #include <stdio.h>
    int main(int argc, char **argv){
   	 int i=0;
   	 char strings[256];
   	 printf("Give me a string: ");scanf("%s",strings);
   	 printf("argc=%d\n",argc);
   	 while(argv[i]){
   		 printf("argv[%d]=\"%s\"\n",i,argv[i]);
   		 i++;
   		 }
    printf("argv[%d]=NULL\n",i);
   	return 0;
   }
