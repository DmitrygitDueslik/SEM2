#pragma once

struct AAA
{
	int x;
	void print ( );
};

namespace heap
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};

	struct Heap
	{
		int size;
		int maxSize;
		void** storage;
		CMP ( *compare )(void*, void*);
		void siftUp ( int i );             //  Просеивание вверх
		void* extractMin ( );             //  Удаление минимального
		void* extractI ( int i );          // Удаление i-го элемента
		void unionHeap ( Heap& other );

		Heap ( int maxSize, CMP ( *f )(void*, void*) )
		{
			this->size = 0;
			this->maxSize = maxSize;
			storage = new void* [maxSize];
			compare = f;

			for ( int i = 0; i < maxSize; i++ ) {
				storage[i] = nullptr;
			}
		}

		~Heap ( )
		{
			delete[] storage;
		}

		Heap ( const Heap& ) = delete;
		Heap& operator=( const Heap& ) = delete;

		int left ( int ix );
		int right ( int ix );
		int parent ( int ix );

		bool isFull ( ) const { return size >= maxSize; }
		bool isEmpty ( ) const { return size <= 0; }

		bool isLess ( void* x1, void* x2 ) const { return compare ( x1, x2 ) == LESS; }
		bool isGreat ( void* x1, void* x2 ) const { return compare ( x1, x2 ) == GREAT; }
		bool isEqual ( void* x1, void* x2 ) const { return compare ( x1, x2 ) == EQUAL; }

		void swap ( int i, int j );
		void heapify ( int ix );
		void insert ( void* x );
		void* extractMax ( );
		void scan ( int i ) const;
	};

	Heap* create ( int maxSize, CMP ( *f )(void*, void*) );
}