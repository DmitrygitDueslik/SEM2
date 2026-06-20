#include <iostream>
#include "mathlib.h"

int main ( )
{
	double a = 10.0, b = 5.0;
	try {
		std::cout << "Sum: " << MathLib::add ( a, b ) << std::endl;
		std::cout << "Difference: " << MathLib::subtract ( a, b ) << std::endl;
		std::cout << "Product: " << MathLib::multiply ( a, b ) << std::endl;
		std::cout << "Quotient: " << MathLib::divide ( a, b ) << std::endl;
	}
	catch ( const char* msg ) {
		std::cerr << msg << std::endl;
	}
	return 0;
}