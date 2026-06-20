#include "Hash_Chain.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Goods
{
	int price;
	char* mas;

	Goods ( int k, char* z )
	{
		price = k;
		mas = z;
	}

	Goods ( )
	{
		price = 0;
		mas = nullptr;
	}
};

// Функция получения ключа
int hf ( void* d )
{
	Goods* f = (Goods*)d;
	return f->price;
}

// Функция вывода элемента
void Goods_print ( listx::Element* e )
{
	std::cout << ((Goods*)e->data)->price << '-' << ((Goods*)e->data)->mas << " / ";
}

int main ( )
{
	int current_size = 7;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> current_size;

	hashTC::Object H = hashTC::create ( current_size, hf );

	int choice;
	int k;

	for ( ;;) {
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;

		switch ( choice ) {
			case 0:
				exit ( 0 );

			case 2: {
					Goods* a = new Goods;
					char* str = new char[20];
					cout << "введите ключ (стоимость)" << endl;
					cin >> k;
					a->price = k;
					cout << "введите название товара" << endl;
					cin >> str;
					a->mas = str;
					H.insert ( a );
				}
				  break;

			case 1:
				H.Scan ( );
				break;

			case 3: {
					Goods* b = new Goods;
					cout << "введите ключ для удаления" << endl;
					cin >> k;
					b->price = k;
					H.deleteByData ( b );
				}
				  break;

			case 4:
				Goods * c = new Goods;
				cout << "введите ключ для поиска" << endl;
				cin >> k;
				c->price = k;
				if ( H.search ( c ) == NULL )
					cout << "Элемент не найден" << endl;
				else {
					cout << "Первый элемент с данным ключом" << endl;
					Goods_print ( H.search ( c ) );
					cout << endl;
				}
				break;
		}
	}

	return 0;
}