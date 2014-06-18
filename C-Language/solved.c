#include <stdio.h>
#include <math.h>
void main()
{
	int a,b,c;
	float x1,x2,delta;
	printf("Input parameters for the equation: ax^2 + bx +c \n");
	printf("a = ");scanf("%d",&a);
	printf("\n b = ");scanf("%d",&b);
	printf("\n c = ");scanf("%d",&c);
	delta = b*b - 4*a*c;
	if(delta<0)
		printf("x1,x2 aren't the real number!");
	else if(delta==0)
	{
		x1=x2=-b/(2.0*a);
		printf("\n x1=x2=%4.2f",x1);
	}
	else{
		x1 = (-b-sqrt(delta))/(2.0*a);
		x2 = (-b+sqrt(delta))/(2.0*a);
		printf("\n x1 = %4.2f", x1);
		printf("\n x2 = %4.2f", x2);
	}
}
