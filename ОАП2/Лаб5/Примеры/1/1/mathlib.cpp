#include "mathlib.h"

namespace MathLib

{
	double add ( double a, double b )
	{
		return a + b;
	}
	double subtract ( double a, double b )
	{
		return a - b;
	}
	double multiply ( double a, double b )
	{
		return a * b;
	}
	double divide ( double a, double b )
	{
		if ( b != 0 ) {
			return a / b;
		}
		else {
			throw "Division by zero error!";
		}
	}
}