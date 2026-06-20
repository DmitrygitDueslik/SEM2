#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};

//-----------------------------------------------------------
int menu ( void )
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Сохранить в файл" << endl;    // Новый пункт
	cout << "6. Загрузить из файла" << endl;  // Новый пункт
	cout << "7. Выход" << endl;               // Выход теперь пункт 7
	cout << endl;

	do {
		cout << "Ваш выбор: ";
		cin.sync ( );
		gets_s ( s );
		c = atoi ( s );
	} while ( c < 1 || c > 7 );
	return c;
}

//-----------------------------------------------------------
void insert ( Address* e, Address** phead, Address** plast )
{
	Address* p = *plast;
	if ( *plast == NULL ) {
		e->next = NULL; e->prev = NULL;
		*plast = e; *phead = e;
		return;
	}
	else {
		p->next = e; e->next = NULL; e->prev = p;
		*plast = e;
	}
}

//-----------------------------------------------------------
Address* setElement ( )
{
	Address* temp = new Address ( );
	if ( !temp ) { cerr << "Ошибка выделения памяти"; return NULL; }

	cout << "Введите имя: ";
	cin.getline ( temp->name, NAME_SIZE - 1, '\n' );
	cin.ignore ( cin.rdbuf ( )->in_avail ( ) );

	cout << "Введите город: ";
	cin.getline ( temp->city, CITY_SIZE - 1, '\n' );
	cin.ignore ( cin.rdbuf ( )->in_avail ( ) );

	temp->next = NULL; temp->prev = NULL;
	return temp;
}

//-----------------------------------------------------------
void outputList ( Address** phead, Address** plast )
{
	Address* t = *phead;
	while ( t ) {
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << endl;
}

//-----------------------------------------------------------
void find ( char name[NAME_SIZE], Address** phead )
{
	Address* t = *phead;
	while ( t ) {
		if ( !strcmp ( name, t->name ) ) break;
		t = t->next;
	}
	if ( !t ) cerr << "Имя не найдено" << endl;
	else cout << t->name << ' ' << t->city << endl;
}

//-----------------------------------------------------------
void delet ( char name[NAME_SIZE], Address** phead, Address** plast )
{
	Address* t = *phead;
	while ( t ) {
		if ( !strcmp ( name, t->name ) ) break;
		t = t->next;
	}
	if ( !t ) { cerr << "Имя не найдено" << endl; }
	else {
		if ( *phead == t ) {
			*phead = t->next;
			if ( *phead ) (*phead)->prev = NULL;
			else *plast = NULL;
		}
		else {
			t->prev->next = t->next;
			if ( t != *plast ) t->next->prev = t->prev;
			else *plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}

//-----------------------------------------------------------
// Запись списка в файл (бинарный режим)
void writeToFile ( Address** phead )
{
	Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s ( &fp, "mlist", "wb" );
	if ( err ) {
		cerr << "Файл не открывается" << endl;
		exit ( 1 );
	}
	cout << "Сохранение в файл" << endl;
	while ( t ) {
		fwrite ( t, sizeof ( struct Address ), 1, fp );
		t = t->next;
	}
	fclose ( fp );
}

//-----------------------------------------------------------
// Считывание списка из файла (бинарный режим)
void readFromFile ( Address** phead, Address** plast )
{
	Address* t;
	FILE* fp;
	errno_t err = fopen_s ( &fp, "mlist", "rb" );
	if ( err ) {
		cerr << "Файл не открывается" << endl;
		exit ( 1 );
	}
	// Очистка текущего списка перед загрузкой
	while ( *phead ) {
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;

	cout << "Загрузка из файла" << endl;
	while ( !feof ( fp ) ) {
		t = new Address ( );
		if ( !t ) { cerr << "Ошибка выделения памяти" << endl; return; }
		if ( 1 != fread ( t, sizeof ( struct Address ), 1, fp ) ) break;
		insert ( t, phead, plast );
	}
	fclose ( fp );
}

//-----------------------------------------------------------
int main ( void )
{
	Address* head = NULL;
	Address* last = NULL;

	while ( true ) {
		switch ( menu ( ) ) {
			case 1:  // Добавить
				insert ( setElement ( ), &head, &last );
				break;
			case 2:  // Удалить
				{
					char dname[NAME_SIZE];
					cout << "Введите имя: ";
					cin.getline ( dname, NAME_SIZE - 1, '\n' );
					cin.ignore ( cin.rdbuf ( )->in_avail ( ) );
					delet ( dname, &head, &last );
				}
				break;
			case 3:  // Вывести
				outputList ( &head, &last );
				break;
			case 4:  // Поиск
				{
					char fname[NAME_SIZE];
					cout << "Введите имя: ";
					cin.getline ( fname, NAME_SIZE - 1, '\n' );
					cin.ignore ( cin.rdbuf ( )->in_avail ( ) );
					find ( fname, &head );
				}
				break;
			case 5:  // Сохранить в файл (НОВОЕ)
				writeToFile ( &head );
				break;
			case 6:  // Загрузить из файла (НОВОЕ)
				readFromFile ( &head, &last );
				break;
			case 7:  // Выход
				exit ( 0 );
			default:
				exit ( 1 );
		}
	}
	return 0;
}