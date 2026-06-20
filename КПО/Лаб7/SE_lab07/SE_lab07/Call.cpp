#include <iostream>
#include "Call.h"

using namespace std;

namespace call
{
	int _cdecl cdevl ( int x, int y, int z )
	{
		return x + y + z;
	}
	int _stdcall cstd ( int& x, int y, int z )
	{
		return x * y * z;
	}
	int _fastcall cfst ( int x, int y, int z, int d )
	{
		return x + y + z + d;
	}
}

int main ( )
{
	int a = 5;
	int& b = a;
	int rc_cdecl = call::cdevl ( 2, 3, 4 );
	int rc_stdcall = call::cstd ( b, 3, 4 );
	int rc_fastcall = call::cfst ( 2, 3, 4, 5 );
	cout << rc_cdecl << endl;
	cout << rc_stdcall << endl;
	cout << rc_fastcall << endl;
	return 0;
}