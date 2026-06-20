#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mainstack.h"
using namespace std;

int main ( )
{
	srand ( time ( 0 ) );

	Stack* source = nullptr;
	Stack* stack1 = nullptr;
	Stack* stack2 = nullptr;

	int choice;

	do {
		cout << "\n--- МЕНЮ ---\n";
		cout << "1. Push в источник  |  2. Pop из источника  |  3. Show источник\n";
		cout << "4.  Разделить на чётные/нечётные \n";
		cout << "5. Show Stack1 (чётные)  |  6. Show Stack2 (нечётные)\n";
		cout << "7. ToFile  |  8. FromFile  |  9-11. Clear  |  0. Exit\n";
		cout << "Выбор: ";
		cin >> choice;

		switch ( choice ) {
			case 1: {
					int num;
					cout << "Число : ";
					cin >> num;
					push ( num, source );
					cout << "Добавлено: " << num << endl;
					break;
				}
			case 2:
				cout << "Pop: " << pop ( source ) << endl;
				break;
			case 3:
				show ( source );
				break;
			case 4:
				splitStack ( stack1, stack2, source );
				break;
			case 5:
				cout << "Stack1 (+): "; show ( stack1 );
				break;
			case 6:
				cout << "Stack2 (-): "; show ( stack2 );
				break;
			case 7:
				toFile ( source );
				break;
			case 8:
				fromFile ( source );
				break;
			case 9: clear ( source ); break;
			case 10: clear ( stack1 ); break;
			case 11: clear ( stack2 ); break;
			case 0:
				clear ( source ); clear ( stack1 ); clear ( stack2 );
				cout << "Выход.\n";
				break;
			default:
				cout << "Неверный выбор!\n";
		}
	} while ( choice != 0 );

	return 0;
}