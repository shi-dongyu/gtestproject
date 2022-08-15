
#include "sumpow.hpp"
#include "MathFunctions.hpp"

// int main(int argc, char *argv[])
// {
// 	if (argc < 3){
// 		printf("Usage: %s base exponent \n", argv[0]);
// 		return 1;
// 	}
// 	double base = atof(argv[1]);
// 	int exponent = atoi(argv[2]);
// 	double result = power(base, exponent);
// 	printf("%g ^ %d is %g\n", base, exponent, result);
// 	return 0;
// }

double sum_and_power(double x, double base, int exponent)
{
	double result = power(base, exponent);
	return (x + result);
}