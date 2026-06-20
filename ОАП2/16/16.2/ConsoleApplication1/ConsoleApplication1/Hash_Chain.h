#pragma once            //Заголовочный файл Hash_Chain.h
#include "Lists.h"
namespace hashTC
{
	struct Object
	{
		int size;
		int(*FunKey)(void*);
		listx::Object* Hash;
		Object ( int siz, int(*f)(void*) )
		{
			size = siz;
			FunKey = f;
			Hash = new listx::Object[size];
		};
		int hashFunction ( void* data );
		bool insert ( void* data );
		listx::Element* search ( void* data );
		bool deleteByData ( void* data );
		void Scan ( );
	};
	Object create ( int size, int(*f)(void*) );
}
