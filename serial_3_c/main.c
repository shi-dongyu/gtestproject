#include <stdio.h>
#include <stdlib.h>
#include "sumpow.h"

int main(int argc, char *argv[])
{
	if (argc < 3){
		printf("Usage: %s base exponent \n", argv[0]);
		return 1;
	}
	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
	double result = sum_and_power(1, base, exponent);
	printf("1 + %g ^ %d is %g\n", base, exponent, result);
	return 0;
}
