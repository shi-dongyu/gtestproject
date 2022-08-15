#include <iostream>
#include "sumpow.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 3){
		cout << "Usage:" << argv[0] << " base exponent \n";
		return 1;
	}
	double base = atof(argv[1]);
	int exponent = atoi(argv[2]);
	double result = sum_and_power(1, base, exponent);
	cout <<"1 + "<< base << "^" << exponent << " = " << result;

	return 0;
}
