#include <iostream>
using namespace std;
int pop ( stack*& st ); // Извлечение элемента
void push ( stack*& st, int d ); // Добавление элемента
struct stack
{
	int data;
	stack* next;
};
int main ( )
{
	stack* p = nullptr;
	push ( p, 100 );    //число 100 – в стек
	push ( p, 200 );    //число 200 – в стек
	pop ( p );          //вывод текущего элемента = 200
	pop ( p );          // вывод текущего элемента = 100
	return 0;
}
int pop ( stack*& st ) // Извлечение элемента
{
	int tmp = st->data; 	stack* pv = st;
	st = st->next;       // вершиной становится предшествующий элемент
	delete pv;           // освобождается память
	cout << tmp << endl; //вывод текущего элемента
	return tmp;
}
void push ( stack*& st, int d ) // Добавление элемента
{
	stack* pv = new stack;
	pv->data = d;   // значение помещается в стек
	pv->next = st;
	st = pv;
}