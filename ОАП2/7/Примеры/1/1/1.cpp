#include <iostream>
using namespace std;
struct Item
{
	int info;
	Item* next;
};
void main ( )
{
	Item* plist = nullptr;   //указатель на начало списка
	Item* p;  	int number;
	for ( ;;)                 // создание списка
	{
		cout << "Input number ";
		cin >> number;	   //ввод чисел, пока не введен 0
		if ( !number )  break;
		p = new Item;
		p->info = number;
		p->next = plist;
		plist = p;
	}
	p = plist;
	while ( p )                  // перебор списка c выводом элементов
	{
		cout << p->info << ' ';
		p = p->next;
	}
	while ( plist )              // перебор списка и удаление элементов
	{
		p = plist;
		plist = plist->next;
		delete p;
	}
}