#include <iostream>
#include <deque>

using namespace std;

int main ( )
{
	deque <int> c1;
	c1.push_back ( 10 );
	c1.push_back ( 20 );
	const int& i = c1.at ( 0 );
	int& j = c1.at ( 1 );
	cout << "The first element is " << i << endl;
	cout << "The second element is " << j << endl;
	j = 21;
	cout << "Updated second element is " << j << endl;
	c1.push_back ( 30 );
	cout << "Elements in c1: ";
	for ( int value : c1 )
		cout << value << " ";
	cout << endl;
	return 0;
}