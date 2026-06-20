#include "Hash.h"
#include <iostream>

int HashFunction ( int key, int size, int p )
{
	double key2 = 5 * ((0.6180339887499 * key) - int ( (0.6180339887499 * key) ));
	return (p + key) % size;
}

// Формула: h(key, i) = (h'(key) + i) mod size
// Реализация: каждый следующий индекс вычисляется как (текущий + 1) % size
int Next_hash ( int hash, int size, int p )
{
	return (hash + 1) % size; // Линейное пробирование: сдвигаемся на 1 позицию
}

// -------------------------------
Object create ( int size, int (*getkey)(void*) )
{
	return *(new Object ( size, getkey ));
}

// -------------------------------
Object::Object ( int size, int (*getkey)(void*) )
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for ( int i = 0; i < size; ++i )
		data[i] = NULL;
}

// -------------------------------
bool Object::insert ( void* d )
{
	bool b = false;
	if ( N != size ) {
		int t = getKey ( d );
		int initial_hash = HashFunction ( t, size, 0 ); // h'(key)

		// Линейное пробирование: перебираем индексы (h' + i) % size
		for ( int i = 0; i != size && !b; i++ ) {
			int j = (initial_hash + i) % size;
			if ( data[j] == NULL || data[j] == DEL ) {
				data[j] = d;
				N++;
				b = true;
			}
		}
	}
	return b;
}

// -------------------------------
int Object::searchInd ( int key )
{
	int t = -1;
	bool b = false;
	if ( N != 0 ) {
		int initial_hash = HashFunction ( key, size, 0 );

		// Линейное пробирование при поиске
		for ( int i = 0; i != size && !b; i++ ) {
			int j = (initial_hash + i) % size;
			if ( data[j] != NULL ) {
				if ( data[j] != DEL ) {
					if ( getKey ( data[j] ) == key ) {
						t = j; b = true;
					}
				}
			}
			else {
				break; // Пустая ячейка -> элемента точно нет
			}
		}
	}
	return t;
}

// -------------------------------
void* Object::search ( int key )
{
	int t = searchInd ( key );
	return (t >= 0) ? (data[t]) : (NULL);
}

// -------------------------------
void* Object::deleteByKey ( int key )
{
	int i = searchInd ( key );
	void* t = data[i];
	if ( t != NULL ) {
		data[i] = DEL; // Метка удаления для открытой адресации
		N--;
	}
	return t;
}

// -------------------------------
bool Object::deleteByValue ( void* d )
{
	return (deleteByKey ( getKey ( d ) ) != NULL);
}

// -------------------------------
void Object::scan ( void (*f)(void*) )
{
	for ( int i = 0; i < this->size; i++ ) {
		std::cout << " Элемент " << i;
		if ( (this->data)[i] == NULL )
			std::cout << "   пусто " << std::endl;
		else if ( (this->data)[i] == DEL )
			std::cout << "   удален " << std::endl;
		else
			f ( (this->data)[i] );
	}
}