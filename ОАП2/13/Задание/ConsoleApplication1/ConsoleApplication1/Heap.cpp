#include "Heap.h"
#include <iostream>
#include <iomanip>

void AAA::print ( )
{
	std::cout << x;
}

namespace heap
{
	Heap* create ( int maxsize, CMP ( *f )(void*, void*) )
	{
		return new Heap ( maxsize, f );
	}

	int Heap::left ( int ix )
	{
		int idx = 2 * ix + 1;
		return (idx >= size) ? -1 : idx;
	}

	int Heap::right ( int ix )
	{
		int idx = 2 * ix + 2;
		return (idx >= size) ? -1 : idx;
	}

	int Heap::parent ( int ix )
	{
		return (ix <= 0) ? 0 : (ix - 1) / 2;
	}

	void Heap::swap ( int i, int j )
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}

	void Heap::heapify ( int ix )
	{
		int l = left ( ix );
		int r = right ( ix );
		int largest = ix;

		if ( l != -1 && isGreat ( storage[l], storage[largest] ) )
			largest = l;

		if ( r != -1 && isGreat ( storage[r], storage[largest] ) )
			largest = r;

		if ( largest != ix ) {
			swap ( ix, largest );
			heapify ( largest );
		}
	}

	void Heap::insert ( void* x )
	{
		if ( isFull ( ) ) {
			std::cout << "Куча заполнена!\n";
			return;
		}

		storage[size] = x;
		int i = size;
		size++;

		while ( i > 0 && isLess ( storage[parent ( i )], storage[i] ) ) {
			swap ( parent ( i ), i );
			i = parent ( i );
		}
	}

	void* Heap::extractMax ( )
	{
		if ( isEmpty ( ) ) {
			return nullptr;
		}

		void* rc = storage[0];
		storage[0] = storage[size - 1];
		size--;

		if ( !isEmpty ( ) ) {
			heapify ( 0 );
		}

		return rc;
	}

	void Heap::scan ( int i ) const
	{
		if ( isEmpty ( ) ) {
			std::cout << "\nКуча пуста\n";
			return;
		}

		std::cout << "\n=== КУЧА (размер=" << size << ") ===" << std::endl;
		for ( int u = 0; u < size; u++ ) {
			std::cout << "[" << u << "] = ";
			((AAA*)storage[u])->print ( );
			std::cout << std::endl;
		}
		std::cout << "==========================\n";
	}
	// Просеивание вверх (нужно для extractI)
	void Heap::siftUp ( int i )
	{
		while ( i > 0 && isLess ( storage[parent ( i )], storage[i] ) ) {
			swap ( parent ( i ), i );
			i = parent ( i );
		}
	}

	// Удаление минимального элемента
	void* Heap::extractMin ( )
	{
		if ( isEmpty ( ) ) return nullptr;

		int minIdx = size / 2;

		for ( int k = minIdx + 1; k < size; k++ ) {
			if ( isLess ( storage[k], storage[minIdx] ) ) {
				minIdx = k;
			}
		}

		return extractI ( minIdx );
	}

	// Удаление элемента по индексу i
	void* Heap::extractI ( int i )
	{
		if ( i < 0 || i >= size ) return nullptr;

		void* result = storage[i];

		storage[i] = storage[size - 1];
		size--;

		if ( size > 0 && i < size ) {
			if ( i > 0 && isLess ( storage[parent ( i )], storage[i] ) ) {
				siftUp ( i );
			}
			else {
				heapify ( i );
			}
		}
		return result;
	}

	// Объединение двух куч
	void Heap::unionHeap ( Heap& other )
	{
		if ( size + other.size > maxSize ) {
			std::cout << "Ошибка: Недостаточно места для объединения!" << std::endl;
			return;
		}

		for ( int k = 0; k < other.size; k++ ) {
			insert ( other.storage[k] );
		}
	}
}