#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

int main ( )
{
	char text[500];
	char link[500];

	cout << "Введите текст: ";
	cin.getline ( text, 500 );

	regex pattern ( R"(https?://[^\s]+)" );

	string str ( text );
	smatch match;

	cout << "\n=== Ссылки ===" << endl;

	int count = 0;

	while ( regex_search ( str, match, pattern ) ) {
		strcpy ( link, match.str ( ).c_str ( ) );

		cout << ++count << ". " << link << endl;

		str = match.suffix ( ).str ( );
	}

	if ( count == 0 )
		cout << "Не найдено" << endl;

	cout << "\nВсего: " << count << endl;

	return 0;
}