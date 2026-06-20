#include <iostream>
int main ( )
{
	int x = 5;
	int y = -3;
	auto checkPositive = [] ( int num ) {
		return num > 0;
		};
	std::cout << x << " Положительное ? " << checkPositive ( x ) << std::endl;
	std::cout << y << " Положительное ? " << checkPositive ( y ) << std::endl;
}