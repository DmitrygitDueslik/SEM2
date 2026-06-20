#include <iostream>
using namespace std;
struct Queue
{
	char symbol;
	Queue* next;
};
void	intoFIFO ( Queue* ph[], int v ); //Постановка элемента в конец очереди
void scan ( Queue* ph[] );            //Вывод элемента
char fromFIFO ( Queue* ph[] );        //Извлечение элемента

void main ( )
{
	Queue A3 = { 'a', NULL }, A2 = { 'b', &A3 }, A1 = { 'c', &A2 };
	Queue* ph[2];
	ph[0] = &A1;
	ph[1] = &A3;
	scan ( ph );
	intoFIFO ( ph, 'd' );
	intoFIFO ( ph, 't' );
	scan ( ph );
	char vv = fromFIFO ( ph );
	scan ( ph );
}
void intoFIFO ( Queue* ph[], int v ) //Постановка элемента в конец очереди
{
	Queue* p = new Queue;
	p->symbol = v;
	p->next = NULL;
	if ( ph[0] == NULL )
		ph[0] = ph[1] = p;   //включение в пустую очередь
	else {
		ph[1]->next = p;
		ph[1] = p;
	}
}

void scan ( Queue* ph[] )           //Вывод элемента
{
	for ( Queue* p = ph[0]; p != NULL; p = p->next )
		cout << p->symbol << ' ';
	cout << endl;
}

char fromFIFO ( Queue* ph[] )      //Извлечение элемента
{
	Queue* q;
	if ( ph[0] == NULL ) return -1;     // очередь пуста
	q = ph[0];                        // исключение первого элемента
	ph[0] = q->next;
	if ( ph[0] == NULL ) ph[1] = NULL;
	char v = q->symbol;
	return v;
}