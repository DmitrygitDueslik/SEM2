#include <iostream>
#include <fstream>
using namespace std;

struct list
{
	int number;
	list* next;
};
void insert ( list*& p, int value );
int del ( list*& p, int value );
void printList ( list* p );
int IsEmpty ( list* );
void menu ( void );
void toFile ( list*& p );
void FromFile ( list*& p );
int sumDigital ( list* p );
int findelement ( list* p, int value );
int main ( )
{
	list* first = NULL;
	int choice;
	menu ( );
	cin >> choice;
	int value;
	while ( choice != 8 ) {
		switch ( choice ) {
			case 1:cout << "Введите число "; // добавить число в список
				cin >> value;
				insert ( first, value );
				printList ( first );
				cout << endl;
				break;
			case 2:   if ( !IsEmpty ( first ) ) // удалить число из списка
			{
				cout << "Введите удаляемое число ";
				cin >> value;
				if ( del ( first, value ) ) {
					cout << "Удалено число " << value << endl;
					printList ( first );
				}
				else
					cout << "Число не найдено" << endl;
			}
				  else
				cout << "Список пуст" << endl;
				cout << endl;
				break;
			case 3: {
					toFile ( first );
					cout << endl;
					break;
				}
			case 4: {
					FromFile ( first );
					cout << endl;
					break;
				}
			case 5: {
					printList ( first );
					cout << endl;
					break;
				}
			case 6: {
					sumDigital ( first );
					cout << endl;
					break;
				}
			case 7: {
					if ( !IsEmpty ( first ) ) {
						cout << "Введите число для поиска ";
						cin >> value;
						int pos = findelement ( first, value );
						if ( pos != -1 )
							cout << "Число " << value << " найдено на позиции " << pos << endl;
						else
							cout << "Число " << value << " не найдено" << endl;
					}
					else
						cout << "Список пуст" << endl;
					break;
				}
			default:  cout << "Неправильный выбор" << endl;
				menu ( ); break;
		}
		menu ( );
		cout << "?  ";
		cin >> choice;
	}
	return 0;
}

void menu ( void )     //Вывод меню
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод символа" << endl;
	cout << " 2 - Удаление символа" << endl;
	cout << " 3 - Запись списка в файл" << endl;
	cout << " 4 - Чтение списка из файла" << endl;
	cout << " 5 - Вывод списка" << endl;
	cout << " 6 - Сумма положительных двухзначных чисел" << endl;
	cout << " 7 - Поиск элемента" << endl;
	cout << " 8 - Выход" << endl;
}

void insert ( list*& p, int value )
{
	list* newP = new list;
	if ( newP != NULL ) {
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}
int del ( list*& p, int value )
{
	list* previous, * current, * temp;
	if ( value == p->number ) {
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else {
		previous = p;
		current = p->next;
		while ( current != NULL && current->number != value ) {
			previous = current;
			current = current->next; // перейти к следующему
		}
		if ( current != NULL ) {
			temp = current;
			previous->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;
}
int IsEmpty ( list* p )
{
	return p == NULL;
}

void printList ( list* p )

{
	if ( p == NULL ) {
		cout << "Список пуст" << endl;
	}
	else {
		cout << "Список:" << endl;
		while ( p != NULL ) {
			cout << " | " << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}
void toFile ( list*& p )
{
	list* temp = p;
	list buf;
	ofstream frm ( "mList.txt" );
	if ( frm.fail ( ) ) {
		cout << "\n Ошибка открытия файла";
		exit ( 1 );
	}
	while ( temp ) {
		frm << temp->number << endl;
		temp = temp->next;
	}
	frm.close ( );
	cout << "Список записан в файл mList.txt\n";
}
void FromFile ( list*& p )
{
	ifstream frm ( "mList.txt" );
	if ( frm.fail ( ) ) {
		cout << "\n Ошибка открытия файла";
		exit ( 1 );
	}
	p = nullptr;
	int number;
	while ( frm >> number ) {
		insert ( p, number );
	}
	cout << "-->NULL" << endl;
	frm.close ( );
	printList ( p );
	cout << "\nСписок считан из файла mList.txt\n";
}
int sumDigital ( list* p )
{
	int sum = 0;
	bool found = false;
	while ( p != nullptr ) {
		if ( p->number > 0 && p->number > 10 && p->number < 99 ) {
			sum += p->number;
			found = true;
		}
		p = p->next;
	}
	if ( found )
		cout << "Сумма: " << sum << endl;
	else
		cout << "Положительных двухзначных элементов нет" << endl;

	return sum;
}
int findelement ( list* p, int value )
{
	int position = 1;
	while ( p != NULL ) {
		if ( p->number == value )
			return position;
		p = p->next;
		position++;
	}
	return -1;
}