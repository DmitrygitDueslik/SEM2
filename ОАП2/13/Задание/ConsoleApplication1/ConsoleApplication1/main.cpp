#include "Heap.h"
#include <iostream>
#include <cstdlib>
using namespace std;

heap::CMP cmpAAA ( void* a1, void* a2 )
{
	AAA* A1 = (AAA*)a1;
	AAA* A2 = (AAA*)a2;

	if ( A1->x > A2->x )
		return heap::GREAT;
	else if ( A2->x > A1->x )
		return heap::LESS;
	else
		return heap::EQUAL;
}

int main ( )
{
	int k, choice;

	heap::Heap* h1 = heap::create ( 30, cmpAAA );

	cout << "Куча создана успешно!" << endl;

	for ( ;;) {
		cout << "\n=== МЕНЮ ===" << endl;
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - удалить минимальный элемент" << endl;
		cout << "5 - удалить элемент по индексу" << endl;
		cout << "6 - объединить с другой кучей" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор: ";
		cin >> choice;

		switch ( choice ) {
			case 0:
				delete h1;
				cout << "Выход из программы..." << endl;
				exit ( 0 );

			case 1:
				h1->scan ( 0 );
				break;

			case 2: {
					AAA* a = new AAA;
					cout << "введите ключ: ";
					cin >> k;
					a->x = k;
					h1->insert ( a );
					cout << "Элемент " << k << " добавлен." << endl;
					break;
				}

			case 3: {
					AAA* maxElem = (AAA*)h1->extractMax ( );
					if ( maxElem != nullptr ) {
						cout << "Удалён максимальный элемент: ";
						maxElem->print ( );
						cout << endl;
						delete maxElem;
					}
					else {
						cout << "Куча пуста, нечего удалять!" << endl;
					}
					break;
				}
			case 4: {
					AAA* minElem = (AAA*)h1->extractMin ( );
					if ( minElem ) {
						cout << "Удалён минимальный элемент: ";
						minElem->print ( );
						cout << endl;
						delete minElem;
					}
					else cout << "Куча пуста!" << endl;
					break;
				}
			case 5: {
					int idx;
					cout << "Введите индекс для удаления: ";
					cin >> idx;
					AAA* elem = (AAA*)h1->extractI ( idx );
					if ( elem ) {
						cout << "Удалён элемент с индексом " << idx << " (значение: ";
						elem->print ( );
						cout << ")" << endl;
						delete elem;
					}
					else cout << "Неверный индекс!" << endl;
					break;
				}
			case 6: {
					heap::Heap* h2 = heap::create ( 10, cmpAAA );
					AAA* t1 = new AAA; t1->x = 99; h2->insert ( t1 );
					AAA* t2 = new AAA; t2->x = 88; h2->insert ( t2 );

					cout << "Объединяем с тестовой кучей (99, 88)..." << endl;
					h1->unionHeap ( *h2 );

					delete h2;
					break;
				}

			default:
				cout << "Введена неверная команда!" << endl;
		}
	}

	return 0;
}