#include <iostream>
#include <fstream>
using namespace std;
struct list
{
	char symbol;
	list* next;
};
void insert ( list*& p, char value ); //Добавление символа в начало списка
void printList ( list* p );       //Вывод списка
void toFile ( list*& p );         //Запись в файл
void fromFile ( list*& p );       //Считывание из файла
void menu ( void );               //Вывод меню

int main ( )
{
	list* first = nullptr;
	int choice; char value;
	menu ( );    // вывести меню
	cout << " ? ";
	cin >> choice;
	while ( choice != 4 ) {
		switch ( choice ) {
			case 1:  	cout << "Введите символ ";
				cin >> value;
				insert ( first, value );
				printList ( first );
				break;
			case 2:   toFile ( first );
				break;
			case 3:   fromFile ( first );
				break;
			default:  cout << "Неправильный выбор" << endl;
				menu ( ); break;
		}
		cout << "?  ";
		cin >> choice;
	}
	return 0;
}

void insert ( list*& p, char value ) //Добавление символа в начало списка
{
	list* newP = new list;
	if ( newP != NULL )     //есть ли место?
	{
		newP->symbol = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

void printList ( list* p )  //Вывод списка
{
	if ( p == NULL )
		cout << "Список пуст" << endl;
	else {
		cout << "Список:" << endl;
		while ( p != NULL ) {
			cout << "-->" << p->symbol;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile ( list*& p )
{
	list* temp = p;
	list buf;
	ofstream frm ( "mList.dat" );
	if ( frm.fail ( ) ) {
		cout << "\n Ошибка открытия файла";
		exit ( 1 );
	}
	while ( temp ) {
		buf = *temp;
		frm.write ( (char*)&buf, sizeof ( list ) );
		temp = temp->next;
	}
	frm.close ( );
	cout << "Список записан в файл mList.dat\n";
}

void fromFile ( list*& p )          //Считывание из файла
{
	list buf, * first = nullptr;
	ifstream frm ( "mList.dat" );
	if ( frm.fail ( ) ) {
		cout << "\n Ошибка открытия файла";
		exit ( 1 );
	}
	frm.read ( (char*)&buf, sizeof ( list ) );
	while ( !frm.eof ( ) ) {
		insert ( first, buf.symbol );
		cout << "-->" << buf.symbol;
		frm.read ( (char*)&buf, sizeof ( list ) );
	}
	cout << "-->NULL" << endl;
	frm.close ( );
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}

void menu ( void )     //Вывод меню
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод символа" << endl;
	cout << " 2 - Запись списка в файл" << endl;
	cout << " 3 - Чтение списка из файла" << endl;
	cout << " 4 - Выход" << endl;
}