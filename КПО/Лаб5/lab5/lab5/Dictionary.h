#pragma once
#include <cstring>
#include "stdafx.h"
#define DICTNAMEMAXSIZE 20 // максимальный размер имени словаря
#define DICTMAXSIZE 100 // максимальная емкость словаря
#define ENTRYNAMEMAXSIZE 30 // максимальная длина имени в словаре
#define THROW01 "Create: превышен размер имени словаря\n"
#define THROW02 "Create: превышен размер максимальной емкости словаря\n"
#define THROW03 "AddEntry: переполнение словаря\n"
#define THROW04 "AddEntry: дублирование идентификатора\n"
#define THROW05 "GetEntry: не найден элемент\n"
#define THROW06 "DelEntry: не найден элемент\n"
#define THROW07 "UpdEntry: не найден элемент\n"
#define THROW08 "UpdEntry: дублирование идентификатора\n"

namespace Dictionary
{
	struct Entry
	{
		int id; // идентификатор(уникальный)
		char name[ENTRYNAMEMAXSIZE]; // символьная информация
	};
	struct Instance // экземпляр словаря
	{
		char name[DICTNAMEMAXSIZE]; // наименование словаря
		int maxsize; // максимальная емкость словаря
		int size; // текущий размер словаря
		Entry* dictionary; // массив элемнтов словаря
	};
	Instance Create ( // создать словарь
		const char name[DICTNAMEMAXSIZE], // имя словаря
		int size // емкость словаря < DICTNAMEMAXSIZE
	);
	void AddEntry ( // добавить элемент словаря
		Instance& inst, // экземпляр словаря
		Entry ed // элемент словаря
	);
	void DelEntry ( // удалить элемент словаря
		Instance& inst, // экземпляр словаря
		int id // идентификатор удаляемого элемента (уникальный)
	);
	void UpdEntry ( // изменить элемент словаря
		Instance& inst, // экземпляр словаря
		int id, // идентификатор удаляемого элемента (уникальный)
		Entry new_ed // новый элемент словаря
	);
	Entry GetEntry (
		Instance& inst, // экземпляр словаря
		int id // идентификатор удаляемого элемента (уникальный)
	);
	void Print ( Instance d ); // печать словаря
	void Delete ( Instance& d ); // удалить словарь
}