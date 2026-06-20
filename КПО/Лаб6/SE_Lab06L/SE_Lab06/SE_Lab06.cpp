#include "C:\Users\Dmitriy\Desktop\КПО\Лаб6\SE_Lab06L\SE_Lab06L\Dictionary.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <exception>
#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1
#error "Должен быть установлен только один макрос"
#endif

int menu ( void )
{
	char s[80]; int c;
	std::cout << std::endl;
	std::cout << "0. Выход" << std::endl;
	std::cout << "1. Ввод нового справочника" << std::endl;
	std::cout << "2. Ввод новой записи" << std::endl;
	std::cout << "3. Вывод всего справочника на экран" << std::endl;
	std::cout << "4. Поиск по номеру в справочнике" << std::endl;
	std::cout << "5. Обновление записи в справочнике (по id)" << std::endl;
	std::cout << "6. Удаление записи из справочника" << std::endl;
	std::cout << std::endl;
	do {
		std::cin.ignore ( std::cin.rdbuf ( )->in_avail ( ) );
		std::cout << "Ваш выбор: ";
		std::cin.sync ( );
		gets_s ( s );
		std::cout << std::endl;
		c = atoi ( s );
	} while ( c < 0 || c > 7 );
	return c;
}

int main ( )
{
	Dictionary::Instance d;
	Dictionary::Entry e;
	char dname[1000], ename[ENTRYNAMEMAXSIZE];
	int dsize, eid;

#ifdef TEST_CREATE_01
	try {
		Dictionary::Instance d1 = Dictionary::Create ( "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq", 23 );
		Dictionary::Delete ( d1 );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
	}
#endif

#ifdef TEST_CREATE_02
	try {
		Dictionary::Instance d2 = Dictionary::Create ( "q", 123 );
		Dictionary::Delete ( d2 );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
	}
#endif

#ifdef TEST_ADDENTRY_03
	try {
		Dictionary::Instance d3 = Dictionary::Create ( "q", 2 );
		Dictionary::Entry e1 = { 1, "One" };
		Dictionary::Entry e2 = { 2, "Two" };
		Dictionary::AddEntry ( d3, e1 );
		Dictionary::AddEntry ( d3, e2 );
		Dictionary::Delete ( d3 );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
	}
#endif

#ifdef TEST_ADDENTRY_04
	try {
		Dictionary::Instance d4 = Dictionary::Create ( "q", 2 );
		Dictionary::Entry e3 = { 1, "One" };
		Dictionary::Entry e4 = { 1, "Duplicate" };
		Dictionary::AddEntry ( d4, e3 );
		Dictionary::AddEntry ( d4, e4 );
		Dictionary::Delete ( d4 );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
	}
#endif

#ifdef TEST_GETENTRY_05
	try {
		Dictionary::Instance d5 = Dictionary::Create ( "q", 2 );
		Dictionary::Entry e5 = { 1, "One" };
		Dictionary::Entry e6 = { 2, "Two" };
		Dictionary::AddEntry ( d5, e5 );
		Dictionary::AddEntry ( d5, e6 );
		Dictionary::GetEntry ( d5, 3 );
		Dictionary::Delete ( d5 );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
	}
#endif

#ifdef TEST_GETENTRY_06
	try {
		Dictionary::Instance d7 = Dictionary::Create ( "q", 2 );
		Dictionary::Entry e7 = { 1, "One" };
		Dictionary::Entry e8 = { 2, "Two" };
		Dictionary::AddEntry ( d7, e7 );
		Dictionary::AddEntry ( d7, e8 );
		Dictionary::DelEntry ( d7, 3 );
		Dictionary::Delete ( d7 );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
	}
#endif

#ifdef TEST_UPDENTRY_07
	try {
		Dictionary::Instance d8 = Dictionary::Create ( "q", 2 );
		Dictionary::Entry e9 = { 1, "One" };
		Dictionary::Entry e10 = { 2, "Two" };
		Dictionary::AddEntry ( d8, e9 );
		Dictionary::AddEntry ( d8, e10 );
		Dictionary::Entry newE = { 99, "New" };
		Dictionary::UpdEntry ( d8, 3, newE );
		Dictionary::Delete ( d8 );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
	}
#endif

#ifdef TEST_UPDENTRY_08
	try {
		Dictionary::Instance d9 = Dictionary::Create ( "q", 2 );
		Dictionary::Entry e11 = { 1, "One" };
		Dictionary::Entry e12 = { 2, "Two" };
		Dictionary::AddEntry ( d9, e11 );
		Dictionary::AddEntry ( d9, e12 );
		Dictionary::Entry newE = { 2, "Updated" };
		Dictionary::UpdEntry ( d9, 2, newE );
		Dictionary::Print ( d9 );
		Dictionary::Delete ( d9 );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
	}
#endif

#ifdef TEST_DICTIONARY
	try {
		while ( true ) {
			switch ( menu ( ) ) {
				case 0: exit ( 0 );
				case 1: {
						std::cout << "Введите имя справочника: "; std::cin >> dname;
						std::cout << "Введите размер справочника: "; std::cin >> dsize;
						d = Dictionary::Create ( dname, dsize );
						std::cin.ignore ( std::cin.rdbuf ( )->in_avail ( ) );
						break;
					}
				case 2: {
						std::cout << "Введите имя человека: "; std::cin >> ename;
						std::cout << "Введите его id: "; std::cin >> eid;
						e.id = eid;
						strcpy_s ( e.name, ename );
						Dictionary::AddEntry ( d, e );
						std::cin.ignore ( std::cin.rdbuf ( )->in_avail ( ) );
						break;
					}
				case 3: Dictionary::Print ( d ); break;
				case 4: {
						std::cout << "Введите id человека которого хотите найти: "; std::cin >> eid;
						Dictionary::Entry element = Dictionary::GetEntry ( d, eid );
						std::cout << element.id << " " << element.name << std::endl;
						std::cin.ignore ( std::cin.rdbuf ( )->in_avail ( ) );
						break;
					}
				case 5: {
						std::cout << "Введите id записи которую хотите обновить: "; std::cin >> eid;
						std::cout << "Введите новое имя человека: "; std::cin >> ename;
						e.id = eid;
						strcpy_s ( e.name, ename );
						Dictionary::UpdEntry ( d, eid, e );
						std::cout << "Запись успешно изменена\n";
						std::cin.ignore ( std::cin.rdbuf ( )->in_avail ( ) );
						break;
					}
				case 6: {
						std::cout << "Введите id человека которого хотите удалить из справочника: "; std::cin >> eid;
						Dictionary::DelEntry ( d, eid );
						std::cout << "Запись успешно удалена\n";
						std::cin.ignore ( std::cin.rdbuf ( )->in_avail ( ) );//Для чтения 1 символа и игнорирование последующих
						break;
					}
				default: exit ( 1 );
			}
		}
		Dictionary::Delete ( d );
	}
	catch ( const std::exception& e ) {
		std::cout << e.what ( ) << std::endl;
		Dictionary::Delete ( d );
	}
#endif
	return 0;
}