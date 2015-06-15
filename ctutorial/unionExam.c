#include <stdio.h>

union MyData
{
	char name[30];
	float height;
	int year;
};

int main()
{
	printf("size of MyData: %d\n",sizeof(union MyData));
	union MyData dt;
	strcpy(dt.name,"Nguyen");
	dt.height = 1.0f;
	dt.year = 1993;
	printf("dt.name: %s",dt.name);
	printf("dt.height: %f",dt.height);
	printf("dt.year: %d",dt.year);

	union MyData dt2;
	strcpy(dt2.name,"Luong");
	printf("dt2.name: %s",dt2.name);;
	dt2.height = 1.65f;
	printf("dt2.height: %s",dt2.height);;
	dt2.year = 2015;
	printf("dt2.year: %s",dt2.year);;
	return 0;
}
