#include<iostream>
using namespace std;
struct Number
{
	int info;
	Number* next;
};
void create ( Number** begin, Number** end, int p ); //формирование элементов очереди
void view ( Number* begin );                        //вывод элементов очереди
Number* minElem ( Number* begin );               //определение минимального элемента
void DeltoMin ( Number** begin, Number** p );    //удаление до минимального элемента
int main ( )
{
	Number* begin = NULL, * end, * t;
	t = new Number;
	int p, size;
	cout << "\nEnter size queue=";  cin >> size;
	cout << "Enter number= ";       cin >> p;
	t->info = p;        //первый элемент
	t->next = NULL;
	begin = end = t;
	for ( int i = 1; i < size; i++ ) //создание очереди
	{
		cout << "Enter number= ";    cin >> p;
		create ( &begin, &end, p );
	}
	cout << "\nelements of queue: \n";
	if ( begin == NULL )   //вывод на экран
		cout << "No elements" << endl;
	else
		view ( begin );
	t = minElem ( begin );    //определение минимального
	cout << "minimum=" << t->info << endl;
	DeltoMin ( &begin, &t );   //удаление до минимального
	cout << "\nnew Queue:\n";
	view ( begin );
	return 0;
}
void create ( Number** begin, Number** end, int p ) //Формирование элементов очереди
{
	Number* t = new Number;
	t->next = NULL;
	if ( *begin == NULL )
		*begin = *end = t;
	else {
		t->info = p;
		(*end)->next = t;
		*end = t;
	}
}
void view ( Number* begin ) //Вывод элементов очереди
{
	Number* t = begin;
	if ( t == NULL ) {
		cout << "Number is empty\n";
		return;
	}
	else
		while ( t != NULL ) {
			cout << t->info << endl;
			t = t->next;
		}
}
Number* minElem ( Number* begin ) //Определение минимального элемента
{
	Number* t = begin, * mn = nullptr;
	int min;
	if ( t == NULL ) {
		cout << "Number is empty\n"; return 0;
	}
	else {
		min = t->info;
		while ( t != NULL ) {
			if ( t->info <= min ) {
				min = t->info;
				mn = t;
			}
			t = t->next;
		}
	}
	return mn;
}
void DeltoMin ( Number** begin, Number** p ) //Удаление до минимального элемента
{
	Number* t;
	t = new Number;
	while ( *begin != *p ) {
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
}