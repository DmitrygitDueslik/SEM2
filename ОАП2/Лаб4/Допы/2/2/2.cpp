#include <iostream>
#include <cstring>

using namespace std;

// макросы
#define IS_OPEN(c)  ((c) == '(')
#define IS_CLOSE(c) ((c) == ')')

int main ( )
{
	char s[100];

	cout << "Введите строку: ";
	cin.getline ( s, 100 );

	int balance = 0;

	for ( int i = 0; i < strlen ( s ); i++ ) {
		if ( IS_OPEN ( s[i] ) ) balance++;
		else if ( IS_CLOSE ( s[i] ) ) balance--;

		if ( balance < 0 ) break;
	}

	if ( balance == 0 )
		cout << "ПРАВИЛЬНО" << endl;
	else
		cout << "НЕПРАВИЛЬНО" << endl;

	return 0;
}