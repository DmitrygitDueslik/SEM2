#include <iostream>
#include <fstream>

using namespace std;

struct list
{
	int number;
	list* next;
};

void toFile ( list*& p );
void fromFile ( list*& p );
void insert ( list*&, int ); //функция добавления элемента, передается адрес списка и символ, который добавляется
int del ( list*&, int );   //функция удаления, передается адрес списка и символ, который удаляется
int IsEmpty ( list* );         //функция, которая проверяет, пуст ли список
void printList ( list* );      //функция вывода
void menu ( void );     //функция, показывающая меню
void sum ( list* );
void find ( list*, int );

int main ( )
{
	list* head = nullptr;
	int choice;
	int value;
	do {
		menu ( );
		cin >> choice;
		switch ( choice ) {
			case 1: {
					cout << "Введите число "; // добавить число в список
					cin >> value;
					insert ( head, value );
					break;
				}
			case 2: if ( !IsEmpty ( head ) ) // удалить число из списка
			{
				cout << "Введите удаляемое число ";
				cin >> value;
				if ( del ( head, value ) ) {
					cout << "Удалено число " << value << endl;
					printList ( head );
				}
				else
					cout << "Число не найдено" << endl;
			}
				  else
				cout << "Список пуст" << endl;
				break;

			case 3: {
					cout << "Введите число для поиска - ";
					cin >> value;
					find ( head, value );
					break;
				}
			case 4: {
					printList ( head );
					break;
				}
			case 5: {
					toFile ( head );
					break;
				}
			case 6: {
					fromFile ( head );
					break;
				}
			case 7: {
					sum ( head );
					break;
				}
			case 0: {
					break;
				}
		}
	} while ( choice != 0 );

	return 0;
}

void menu ( )
{
	cout << "1 - добавление элемента" << endl;
	cout << "2 - удаление элемента" << endl;
	cout << "3 - поиск элемента" << endl;
	cout << "4 - вывод списка" << endl;
	cout << "5 - запись списка в файл" << endl;
	cout << "6 - считывание списка из файла" << endl;
	cout << "7 - сумма отрицательных элементов, кратных 5" << endl;
	cout << "0 - выход из программы" << endl;
	cout << "Введите вариант ответа - ";
}

void insert ( list*& p, int value ) //Добавление числа value в список
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
	if ( p == NULL ) return 0;

	list* current = p;
	list* previous = nullptr;

	while ( current != NULL && current->number != value ) {
		previous = current;
		current = current->next;
	}

	if ( current == NULL ) return 0;

	if ( previous == NULL )
		p = p->next;
	else
		previous->next = current->next;

	delete current;
	return value;
}

int IsEmpty ( list* p ) //Список  пустой? (1-да, 0-нет)
{
	return p == NULL;
}

void printList ( list* p )  //Вывод списка
{
	if ( p == NULL )
		cout << "Список пуст" << endl;
	else {
		cout << "Список:" << endl;
		while ( p != NULL ) {
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile ( list*& p )
{
	list* temp = p;
	list buf;
	ofstream frm ( "mList.dat" );
	if ( frm.fail ( ) ) {
		cout << "\n Ошибка открытия файла";
		exit ( 1 );
	}
	while ( temp ) {
		buf = *temp;
		frm.write ( (char*)&buf, sizeof ( list ) );
		temp = temp->next;
	}
	frm.close ( );
	cout << "Список записан в файл mList.dat\n";
}

void fromFile ( list*& p )          //Считывание из файла
{
	list buf, * first = nullptr;
	ifstream frm ( "mList.dat" );
	if ( frm.fail ( ) ) {
		cout << "\n Ошибка открытия файла";
		exit ( 1 );
	}
	frm.read ( (char*)&buf, sizeof ( list ) );
	while ( !frm.eof ( ) ) {
		insert ( first, buf.number );
		cout << "-->" << buf.number;
		frm.read ( (char*)&buf, sizeof ( list ) );
	}
	cout << "-->NULL" << endl;
	frm.close ( );
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}

void find ( list* p, int value )
{
	int counter = 0;
	if ( p == NULL ) {
		cout << "Список пуст" << endl;
		return;
	}

	while ( p != NULL ) {
		if ( p->number == value ) {
			cout << "Элемент найден под номером " << counter + 1 <<
				endl;
			return;
		}
		counter++;
		p = p->next;
	}

	cout << "Элемент не найден!" << endl;
}

void sum ( list* p )
{
	int sm = 0;
	if ( p == NULL )
		cout << "Список пуст" << endl;
	else {
		while ( p != NULL ) {
			if ( p->number < 0 && p->number % 5 == 0 )
				sm = sm + (p->number);
			p = p->next;
		}
		if ( sm )
			cout << "Сумма = " << sm << endl;
		else
			cout << "Отрицательных чисел, кратных 5, нет в списке " << endl;
	}
}