#include <iostream>
#include <cstdlib>
using namespace std;

struct Tree
{
	int key;
	char text[5];
	Tree* Left, * Right;
};

Tree* makeTree ( Tree* Root );
Tree* list ( int i, char* s );
Tree* insertElem ( Tree* Root, int key, char* s );
Tree* search ( Tree* n, int key );
Tree* delet ( Tree* Root, int key );
int sumAllKeys ( Tree* node );
int view ( Tree* t, int level );
int count ( Tree* t, char letter );
bool delAll ( Tree* t );

int c = 0;
Tree* Root = NULL;

int main ( )
{
	int key, choice, n;
	Tree* rc;
	char s[5];
	char letter;

	for ( ;;) {
		cout << "1 - создание дерева\n";
		cout << "2 - добавление элемента\n";
		cout << "3 - поиск по ключу\n";
		cout << "4 - удаление элемента\n";
		cout << "5 - вывод дерева\n";
		cout << "6 - подсчет количества букв\n";
		cout << "7 - очистка дерева\n";
		cout << "8 - Сумма значений всех вершин: \n";
		cout << "9 - выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";

		switch ( choice ) {
			case 1:
				Root = makeTree ( Root );
				break;
			case 2:
				cout << "\nВведите ключ: ";
				cin >> key;
				cout << "Введите слово: ";
				cin >> s;
				insertElem ( Root, key, s );
				break;
			case 3:
				cout << "\nВведите ключ: ";
				cin >> key;
				rc = search ( Root, key );
				if ( rc != NULL ) {
					cout << "Найденное слово= ";
					puts ( rc->text );
				}
				break;
			case 4:
				cout << "\nВведите удаляемый ключ: ";
				cin >> key;
				Root = delet ( Root, key );
				break;
			case 5:
				if ( Root != NULL ) {
					cout << "Дерево повернуто на 90 град. влево" << endl;
					view ( Root, 0 );
				}
				else
					cout << "Дерево пустое\n";
				break;
			case 6:
				cout << "\nВведите букву: ";
				cin >> letter;
				c = 0;
				n = count ( Root, letter );
				cout << "Количество слов, начинающихся с буквы " << letter;
				cout << " равно " << n << endl;
				break;
			case 7:
				delAll ( Root );
				Root = NULL;
				cout << "Дерево очищено\n";
				break;
			case 8:
				if ( Root == NULL ) {
					cout << "Дерево пустое\n";
				}
				else {
					cout << "Сумма значений всех вершин: " << sumAllKeys ( Root ) << endl;
				}
				break;
			case 9:
				exit ( 0 );
			default:
				cout << "Неверный выбор!\n";
		}
	}
	return 0;
}

Tree* makeTree ( Tree* Root )    //Создание дерева
{
	int key; char s[5];
	cout << "Конец ввода - отрицательное число\n\n";
	if ( Root == NULL )	// если дерево не создано
	{
		cout << "Введите ключ корня: ";
		cin >> key;
		cout << "Введите слово корня: ";
		cin >> s;
		Root = list ( key, s );	// установка указателя на корень
	}
	while ( 1 )                //добавление элементов
	{
		cout << "\nВведите ключ: ";
		cin >> key;
		if ( key < 0 ) break;       //признак выхода (ключ < 0)
		cout << "Введите слово: ";
		cin >> s;
		insertElem ( Root, key, s );
	}
	return Root;
}

Tree* list ( int i, char* s )     //Создание нового элемента
{
	Tree* t = new Tree[sizeof ( Tree )];
	t->key = i;
	for ( i = 0; i < 5; i++ )
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem ( Tree* t, int key, char* s )  //Добавление нового элемента
{
	Tree* Prev = NULL;	      // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while ( t && !find ) {
		Prev = t;
		if ( key == t->key )
			find = 1;	   //ключи должны быть уникальны
		else
			if ( key < t->key )
				t = t->Left;
			else
				t = t->Right;
	}
	if ( !find )              //найдено место с адресом Prev
	{
		t = list ( key, s );           //создается новый узел
		if ( key < Prev->key )     // и присоединяется либо
			Prev->Left = t;     //переход на левую ветвь,
		else
			Prev->Right = t;    // либо на правую
	}
	return t;
}

Tree* delet ( Tree* Root, int key )
{
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while ( Del != NULL && Del->key != key ) {
		Prev_Del = Del;
		if ( Del->key > key )
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if ( Del == NULL ) {
		puts ( "\nНет такого ключа" );
		return Root;
	}
	if ( Del->Right == NULL )
		R = Del->Left;
	else
		if ( Del->Left == NULL )
			R = Del->Right;
		else {
			Prev_R = Del;
			R = Del->Left;
			while ( R->Right != NULL ) {
				Prev_R = R;
				R = R->Right;
			}
			if ( Prev_R == Del )
				R->Right = Del->Right;
			else {
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if ( Del == Root ) Root = R;
	else

		if ( Del->key < Prev_Del->key )
			Prev_Del->Left = R;
		else
			Prev_Del->Right = R;
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search ( Tree* n, int key )
{
	Tree* rc = n;
	if ( rc != NULL ) {
		if ( key < (key, n->key) )
			rc = search ( n->Left, key );
		else
			if ( key > (key, n->key) )
				rc = search ( n->Right, key );
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}

int count ( Tree* t, char letter )
{
	if ( t ) {
		count ( t->Right, letter );
		if ( *(t->text) == letter )
			c++;
		count ( t->Left, letter );
	}
	return c;
}

int view ( Tree* t, int level )
{
	if ( t ) {
		view ( t->Right, level + 1 );
		for ( int i = 0; i < level; i++ )
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts ( t->text );
		view ( t->Left, level + 1 );
		return 0;
	}
	return 1;
}

int sumAllKeys ( Tree* node )
{
	if ( node == NULL ) return 0;

	return node->key + sumAllKeys ( node->Left ) + sumAllKeys ( node->Right );
}

bool delAll ( Tree* t )
{
	if ( t != NULL ) {
		delAll ( t->Left );
		delAll ( t->Right );
		delete t;
	}
	return true;
}