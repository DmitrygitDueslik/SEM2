#include <iostream>
#include <fstream>
#include "mainstack.h"
using namespace std;

void push ( char x, Stack*& myStk )
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk;
	myStk = e;
}
char pop ( Stack*& myStk )
{
	if ( myStk == nullptr ) {
		cout << "Стек пуст" << endl;
		return -1;
	}
	else {
		Stack* e = myStk;
		char x = myStk->data;
		if ( myStk )
			myStk = myStk->next;
		delete e;
		return x;
	}
}
void clear ( Stack*& myStk )
{
	Stack* e = myStk;
	if ( e == nullptr )
		cout << "Стек пуст" << endl;
	while ( e != nullptr ) {
		cout << pop ( e ) << " ";
	}
	cout << "Стек очищен\n";
}
void show ( Stack*& myStk )
{
	Stack* e = myStk;
	if ( e == nullptr ) {
		cout << "Стек пуст!" << endl;
		return;
	}
	cout << "Вершина ->";
	while ( e != nullptr ) {
		cout << e->data << " ";
		e = e->next;
	}
	cout << "<-Низ" << endl;
}
void toFile ( Stack*& myStk )
{
	Stack* e = myStk;
	Stack buf;
	ofstream frm ( "mStack.dat" );
	if ( frm.fail ( ) ) {
		cout << "\nОшибка открытия файла";
		exit ( 1 );
	}
	while ( e ) {
		buf = *e;
		frm.write ( (char*)&buf, sizeof ( Stack ) );
		e = e->next;
	}
	frm.close ( );
	cout << "Стек записан в файл mStack.dat\n";
}
void fromFile ( Stack*& myStk )
{
	Stack buf, * p = nullptr, * e = nullptr;
	ifstream frm ( "mStack.dat" );
	if ( frm.fail ( ) ) {
		cout << "\nОшибка открытия файла";
		exit ( 1 );
	}
	frm.seekg ( 0 );
	frm.read ( (char*)&buf, sizeof ( Stack ) );
	while ( !frm.eof ( ) ) {
		push ( buf.data, e );
		frm.read ( (char*)&buf, sizeof ( Stack ) );
	}
	frm.close ( );
	while ( e != NULL ) {
		buf.data = pop ( e );
		push ( buf.data, p );
		myStk = p;
	}
	cout << "\nСтек считан из файла mStack.dat\n\n";
}
// Проверка: есть ли элемент в стеке
bool contains ( Stack* st, char value )
{
	while ( st != nullptr ) {
		if ( st->data == value ) return true;
		st = st->next;
	}
	return false;
}

void difference ( Stack*& result, Stack* stack1, Stack* stack2 )
{
	Stack* current = stack1;

	while ( current != nullptr ) {
		char val = current->data;

		// Добавляем, если:
		// 1. Элемента НЕТ в Stack2
		// 2. Элемента ещё НЕТ в result (избегаем дубликатов)
		if ( !contains ( stack2, val ) && !contains ( result, val ) ) {
			push ( val, result );
		}
		current = current->next;
	}

	cout << " Разность сформирована\n";
}