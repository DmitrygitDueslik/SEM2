#include <iostream>
using namespace std;
struct list
{
	float number;
	list* next;
};
void insert ( list*&, float ); //функция добавления элемента, передается адрес списка и символ, который добавляется
float del ( list*&, float );   //функция удаления, передается адрес списка и символ, который удаляется
int IsEmpty ( list* );         //функция, которая проверяет, пуст ли список
void printList ( list* );      //функция вывода
void menu ( void );     //функция, показывающая меню
void sum7 ( list* );  //функция подсчета суммы чисел, больших 7

int main ( )
{
	list* first = NULL;
	int choice;
	float value;
	menu ( );    // вывести меню
	cout << " ? ";
	cin >> choice;
	while ( choice != 4 ) {
		switch ( choice ) {
			case 1:  	cout << "Введите число "; // добавить число в список
				cin >> value;
				insert ( first, value );
				printList ( first );
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
				break;
			case 3:   sum7 ( first );	// вычисление суммы
				break;
			default:  cout << "Неправильный выбор" << endl;
				menu ( );
				break;
		}
		cout << "?  ";
		cin >> choice;
	}
	cout << "Конец" << endl;
	return 0;
}
void menu ( void )
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа" << endl;
	cout << " 3 - Вычисление суммы чисел, больших 7" << endl;
	cout << " 4 - Выход" << endl;
}
void insert ( list*& p, float value ) //Добавление числа value в список
{
	list* newP = new list;
	if ( newP != NULL )     //есть ли место?
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

float del ( list*& p, float value )
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
			current = current->next;
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
	if ( p == NULL )
		cout << "Cписок пуст" << endl;
	else {
		cout << "Список:" << endl;
		while ( p != NULL ) {
			cout << "-->>" << p->number;
			p = p->next;
		}
		cout << "-->>NULL" << endl;
	}
}
void sum7 ( list* p )  // Подсчет суммы чисел, больших 7
{
	float sm = 0;
	if ( p == NULL )
		cout << "Список пуст" << endl;
	else {
		while ( p != NULL ) {
			if ( p->number > 7 )
				sm = sm + (p->number);
			p = p->next;
		}
		cout << "Сумма = " << sm << endl;
	}
}