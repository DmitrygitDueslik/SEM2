#include "Lists.h"
#include <iostream>

struct Goods
{
	int price;      // Ключ - стоимость
	char* name;     // Название товара

	Goods ( int p, char* n )
	{
		price = p;
		name = n;
	}

	Goods ( )
	{
		price = 0;
		name = nullptr;
	}
};

namespace listx
{
	bool Object::insert ( void* data )
	{
		bool rc = NULL;
		if ( head == NULL )
			head = new Element ( NULL, data, head );
		else
			head = (head->prev = new Element ( NULL, data, head ));
		return rc;
	}

	Element* Object::search ( void* data )
	{
		Element* rc = head;
		while ( (rc != NULL) && ((((Goods*)rc->data)->price) != ((Goods*)data)->price) )
			rc = rc->next;
		return rc;
	}

	bool Object::deleteByElement ( Element* e )
	{
		bool rc = NULL;
		if ( rc = (e != NULL) ) {
			if ( e->next != NULL )
				e->next->prev = e->prev;
			if ( e->prev != NULL )
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
		}
		std::cout << " Элемент удален" << std::endl;
		return rc;
	}

	bool Object::deleteByData ( void* data )
	{
		return deleteByElement ( search ( data ) );
	}

	Element* Object::getLast ( )
	{
		listx::Element* e = this->getFirst ( ), * rc = this->getFirst ( );
		while ( e != NULL ) {
			rc = e;
			e = e->getNext ( );
		}
		return rc;
	}

	Object create ( )
	{
		return *(new Object ( ));
	}

	void Object::scan ( )
	{
		listx::Element* e = this->getFirst ( );
		while ( e != NULL ) {
			std::cout << ((Goods*)e->data)->price << '-' << ((Goods*)e->data)->name << " / ";
			e = e->getNext ( );
		}
	}
}