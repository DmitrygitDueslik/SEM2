#include <iostream>
#include "MathLibrary.h"

int main ( )
{
	double a = 10.0, b = 5.0;
	std::cout << "Add: " << add ( a, b ) << std::endl;
	std::cout << "Subtract: " << subtract ( a, b ) << std::endl;
	std::cout << "Multiply: " << multiply ( a, b ) << std::endl;
	std::cout << "Divide: " << divide ( a, b ) << std::endl;
	return 0;
}