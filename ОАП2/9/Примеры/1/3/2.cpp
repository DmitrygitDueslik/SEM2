#include <iostream>
#include "myStack.h"
using namespace std;

int main ( )
{
	int choice; char x;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk = NULL;             //инициализация первого элемента
	for ( ;;) {
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Запись в файл" << endl;
		cout << "4 - Чтение из файла" << endl;
		cout << "5 - Вывод стека с очисткой" << endl;
		cout << "6 - Выход" << endl;
		cin >> choice;
		switch ( choice ) {
			case 1: cout << "Введите элемент: " << endl;
				cin >> x;
				push ( x, myStk ); break;
			case 2: x = pop ( myStk );
				if ( x != -1 )
					cout << "Извлеченный элемент: " << x << endl;
				break;
			case 3: toFile ( myStk );  break;
			case 4: fromFile ( myStk ); break;
			case 5: cout << "Весь стек: " << endl;
				show ( myStk ); break;
			case 6: return 0; break;
		}
	}
	return 0;
}