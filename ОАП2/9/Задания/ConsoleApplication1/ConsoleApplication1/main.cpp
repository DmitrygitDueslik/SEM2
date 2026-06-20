#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "mainstack.h"
using namespace std;
int main ( )
{
	srand ( time ( 0 ) );

	Stack* stack1 = nullptr;
	Stack* stack2 = nullptr;
	Stack* result = nullptr;
	int choice;
	char ch;

	do {
		cout << "\n--- МЕНЮ ---\n";
		cout << "1. Push в Stack1  |  2. Pop из Stack1  |  3. Show Stack1\n";
		cout << "4. Push в Stack2  |  5. Pop из Stack2  |  6. Show Stack2\n";
		cout << "7. Различие (вариант 5)  |  8. Show результат\n";
		cout << "9. ToFile Stack1  | 10. FromFile Stack1\n";
		cout << "11. Clear Stack1  | 12. Clear Stack2  |  0. Выход\n";
		cout << "Выбор: ";

		cin >> choice;

		switch ( choice ) {
			case 1:
				cout << "Символ: ";
				cin >> ch;
				cin.ignore ( );
				push ( ch, stack1 );
				break;
			case 2:
				cout << "Pop: " << pop ( stack1 ) << endl;
				break;
			case 3:
				show ( stack1 );
				break;
			case 4:
				cout << "Символ: ";
				cin >> ch;
				cin.ignore ( );
				push ( ch, stack2 );
				break;
			case 5:
				cout << "Pop: " << pop ( stack2 ) << endl;
				break;
			case 6:
				show ( stack2 );
				break;
			case 7:
				difference ( result, stack1, stack2 );
				break;
			case 8:
				show ( result );
				break;
			case 9:
				toFile ( stack1 );
				break;
			case 10:
				fromFile ( stack1 );
				break;
			case 11:
				clear ( stack1 );
				break;
			case 12:
				clear ( stack2 );
				break;
			case 0:
				clear ( stack1 );
				clear ( stack2 );
				clear ( result );
				cout << "Выход.\n";
				break;
			default:
				cout << "Неверный выбор!\n";
		}
	} while ( choice != 0 );

	return 0;
}