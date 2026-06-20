#include <iostream>
#include <stack>

using namespace std;

bool skobochki ( string s )
{
	stack <char> stack; // созд стeка
	for ( char symbol : s ) {
		switch ( symbol ) {
			case '(': stack.push ( ')' ); break;
			case '[': stack.push ( ']' ); break;
			case '{': stack.push ( '}' ); break;
			case ')':
			case ']':
			case '}':
				if ( stack.empty ( ) || stack.top ( ) != symbol ) {
					return false;
				}
				stack.pop ( );
				break;
			default:
				break;
		}
	}
	return stack.empty ( );
}

bool trueorflase ( string s )
{
	for ( int i = 0; i < s.length ( ); i++ ) {
		if ( s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}' ) {
			return true;
		}
	}
	return false;
}

int main ( )
{
	string s;
	cout << "Введите строку: ";
	cin >> s;
	if ( trueorflase ( s ) == true ) {
		if ( skobochki ( s ) == true ) {
			cout << "\n скобки расставлены верно";
		}
		else {
			cout << "\nскобки расставлены не верно";
		}
	}
	else {
		cout << "\nскобки расставлены не верно";
	}
}