#include <iostream>
#include "Varparm.h"
using namespace Varparm;

void main ( )
{
	int iv1 = ivarparm ( 0 );
	int iv2 = ivarparm ( 1, 2 );
	int iv3 = ivarparm ( 2, 2, 3 );
	int iv4 = ivarparm ( 6, 2, 3, 4, 5, 6, 7 );
	cout << "Результаты выполнения функции ivarparm: " << endl;
	cout << "iv1 = " << iv1 << endl;
	cout << "iv2 = " << iv2 << endl;
	cout << "iv3 = " << iv3 << endl;
	cout << "iv4 = " << iv4 << endl;

	cout << endl;

	int sv1 = svarparm ( 0 );
	int sv2 = svarparm ( 1, 2 );
	int sv3 = svarparm ( 2, 2, 3 );
	int sv4 = svarparm ( 6, 2, 3, 4, 5, 6, 7 );
	cout << "Результаты выполнения функции svarparm: " << endl;
	cout << "sv1 = " << sv1 << endl;
	cout << "sv2 = " << sv2 << endl;
	cout << "sv3 = " << sv3 << endl;
	cout << "sv4 = " << sv4 << endl;

	cout << endl;

	double fv1 = fvarparm ( FLT_MAX );
	double fv2 = fvarparm ( 1.5, FLT_MAX );
	double fv3 = fvarparm ( 1.5, 2.75, FLT_MAX );
	double fv4 = fvarparm ( 1.5, 2.75, 3.62, 4.71, 5.83, 6.12, FLT_MAX );
	cout << "Результаты выполнения функции fvarparm: " << endl;
	cout << "fv1 = " << fv1 << endl;
	cout << "fv2 = " << fv2 << endl;
	cout << "fv3 = " << fv3 << endl;
	cout << "fv4 = " << fv4 << endl;

	cout << endl;

	double dv1 = dvarparm ( DBL_MAX );
	double dv2 = dvarparm ( 1.5, DBL_MAX );
	double dv3 = dvarparm ( 1.5, 2.75, DBL_MAX );
	double dv4 = dvarparm ( 1.5, 2.75, 3.62, 4.71, 5.83, 6.12, DBL_MAX );
	cout << "Результаты выполнения функции dvarparm: " << endl;
	cout << "dv1 = " << dv1 << endl;
	cout << "dv2 = " << dv2 << endl;
	cout << "dv3 = " << dv3 << endl;
	cout << "dv4 = " << dv4 << endl;
}