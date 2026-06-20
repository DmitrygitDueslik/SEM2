#include <iostream>
#include "math_operations.h"
using namespace std;

int main ( )
{
	double a = 10.0, b = 5.0;

	cout << "Add: " << add ( a, b ) << endl;
	cout << "Subtract: " << subtract ( a, b ) << endl;
	cout << "Multiply: " << multiply ( a, b ) << endl;
	cout << "Divide: " << divide ( a, b ) << endl;

	return 0;
}