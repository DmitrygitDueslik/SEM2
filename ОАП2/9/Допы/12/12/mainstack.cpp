#include <iostream>
#include <fstream>
#include "mainstack.h"
using namespace std;

void push ( int x, Stack*& myStk )
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk;
	myStk = e;
}
int pop ( Stack*& myStk )
{
	if ( myStk == nullptr ) {
		cout << "Стек пуст" << endl;
		return -1;
	}
	else {
		Stack* e = myStk;
		int x = myStk->data;
		if ( myStk )
			myStk = myStk->next;
		delete e;
		return x;
	}
}
void clear ( Stack*& myStk )
{
	if ( myStk == nullptr ) {
		cout << "Стек пуст" << endl;
		return;
	}
	while ( myStk != nullptr ) {
		pop ( myStk );
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
bool contains ( Stack* st, int value )
{
	while ( st != nullptr ) {
		if ( st->data == value ) return true;
		st = st->next;
	}
	return false;
}

void splitStack ( Stack*& stack1, Stack*& stack2, Stack* source )
{
	clear ( stack1 );  // Чётные
	clear ( stack2 );  // Нечётные

	Stack* current = source;

	while ( current != nullptr ) {
		if ( current->data % 2 == 0 ) {        // Чётное
			push ( current->data, stack1 );
		}
		else {                                  // Нечётное
			push ( current->data, stack2 );
		}
		current = current->next;
	}

	cout << "✓ Стеки сформированы!\n";
}