#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct{
	char id[10];
	char nom[32];
	unsigned int age;
	unsigned int is_married:1;
}person_t;

int main(){
	person_t p1;
	strcpy(p1.id,"NGUYEN123");
	strcpy(p1.nom,"NGUYEN LUONG");
	p1.age=27;
	p1.is_married=TRUE;
	printf("Detail p1:\n");
	printf("Id: %s\n",p1.id);
	printf("Nom: %s\n",p1.nom);
	printf("Age: %d\n",p1.age);
	printf("Is married: %d\n",p1.is_married);
	return 0;
}
