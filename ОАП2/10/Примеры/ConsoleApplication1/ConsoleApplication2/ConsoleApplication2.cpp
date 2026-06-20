#include <iostream>
#include <deque>
using namespace std;

int main ( )
{
	deque<int> c1;
	c1.push_back ( 10 );
	c1.push_back ( 20 );
	c1.push_back ( 30 );
	cout << "The size of the deque initially " << c1.size ( ) << endl;
	c1.clear ( );
	cout << "The size of the deque after cleaning is " << c1.size ( ) << endl;

	return 0;
}