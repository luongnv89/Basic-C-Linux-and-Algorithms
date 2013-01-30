struct complex {
	double real, imaginary ;
} ;
 
struct complex addition ( struct complex a, struct complex b )
{
	struct complex c ;
 
	c . real = a . real + b . real ;
	c . imaginary = a . imaginary + b . imaginary ;
	return c ;
}
 
struct complex substraction ( struct complex a, struct complex b )
{
	struct complex c ;
 
	c . real = a . real - b . real ;
	c . imaginary = a . imaginary - b . imaginary ;
	return c ;
}
 
struct complex multiplication ( struct complex a, struct complex b )
{
	struct complex c ;
 
	c . real = a . real * b . real - a . imaginary * b . imaginary ;
	c . imaginary = a . imaginary * b . real + a . real * b . imaginary ;
	return c ;
}
