#include <iostream>
namespace Varparm
{
	int ivarparm ( int n, ... )
	{
		if ( n == 0 ) {
			return 0;
		}
		int multiply = 1;
		int* p = &n;
		p++;//со второго параметра

		for ( int i = 0; i < n; i++ ) {
			multiply *= (*(p + i));
		}

		return multiply;
	}
	int svarparm ( short n, ... )
	{
		if ( n == 0 ) {
			return 0;
		}
		int* p = (int*)&n + 1;
		int max = p[0];
		for ( int i = 0; i < n; i++ ) {
			if ( *(p + i) > max ) {
				max = *(p + i);
			}
		}
		return max;
	}
	double fvarparm ( float n, ... )
	{
		if ( n == FLT_MAX ) {
			return 0;
		}
		double sum = (double)n;
		double* p = (double*)((int*)&n + 1);
		int k = 0;
		while ( p[k] != (double)FLT_MAX ) {
			sum += p[k];
			k++;
		}
		return sum;
	}

	double dvarparm ( double n, ... )
	{
		if ( n == DBL_MAX ) {
			return 0;
		}
		double sum = n;
		double* p = &n + 1;
		for ( int i = 0; *(p + i) != DBL_MAX; i++ ) {
			sum += *(p + i);
		}
		return sum;
	}
}