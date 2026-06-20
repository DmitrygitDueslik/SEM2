#include <iostream>
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
int view ( Tree* t, int level );
int count ( Tree* t, char letter );
bool delAll ( Tree* t );
int c = 0;
Tree* Root = NULL;

void main ( )
{
	int key, choice, n;
	Tree* rc;
	char s[5];
	char letter;
	for ( ;; ) {
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по ключу\n";
		cout << "4 -	удаление элемента\n";
		cout << "5 -	вывод дерева\n";
		cout << "6 -	подсчет количества букв\n";
		cout << "7 -	очистка дерева\n";
		cout << "8 -	выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch ( choice ) {
			case 1: Root = makeTree ( Root );
				break;
			case 2: cout << "\nВведите ключ: ";
				cin >> key;
				cout << "Введите слово: ";
				cin >> s;
				insertElem ( Root, key, s );
				break;
			case 3:cout << "\nВведите ключ: ";
				cin >> key;
				rc = search ( Root, key );
				cout << "Найденное слово= ";
				puts ( rc->text );
				break;
			case 4:  cout << "\nВведите удаляемый ключ: ";
				cin >> key;
				Root = delet ( Root, key );
				break;
			case 5:  if ( Root->key >= 0 ) {
				cout << "Дерево повернуто на 90 град. влево" << endl;
				view ( Root, 0 );
			}
				  else cout << "Дерево пустое\n";
				break;
			case 6:  cout << "\nВведите букву: ";
				cin >> letter;
				n = count ( Root, letter );
				cout << "Количество слов, начинающихся с буквы " << letter;
				cout << " равно " << n << endl;
				break;
			case 7:  delAll ( Root );
				break;
			case 8:  exit ( 0 );
		}
	}
}
Tree* makeTree ( Tree* Root )
{
	int key;
	char s[5];
	cout << "Конец ввода - отрицательное число\n\n";
	if ( Root == NULL ) {
		cout << "Введите ключ корня: ";
		cin >> key;
		cout << "Введите слово корня: ";
		cin >> s;
		Root = list ( key, s );
	}
	while ( 1 ) {
		cout << "\nВведите ключ: ";
		cin >> key;
		if ( key < 0 ) break;
		cout << "Введите слово: ";
		cin >> s;
		insertElem ( Root, key, s );
	}
	return Root;
}
Tree* list ( int i, char* s )
{
	Tree* t = new Tree[sizeof ( Tree )];
	t->key = i;
	for ( i = 0; i < 5; i++ )
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}
Tree* insertElem ( Tree* t, int key, char* s )
{
	Tree* Prev = NULL;
	int find = 0;
	while ( t && !find ) {
		Prev = t;
		if ( key == t->key )
			find = 1;
		else
			if ( key < t->key )
				t = t->Left;
			else
				t = t->Right;
	}
	if ( !find ) {
		t = list ( key, s );
		if ( key < Prev->key )
			Prev->Left = t;
		else
			Prev->Right = t;
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
	if ( Del->Right == NULL )     // поиск элемента R для замены
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
	if ( Del == Root ) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if ( Del->key < Prev_Del->key )
			Prev_Del->Left = R;  //на левую ветвь
		else
			Prev_Del->Right = R;	//на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}
Tree* search ( Tree* n, int key )  //Поиск элемента по ключу
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

int count ( Tree* t, char letter ) //Подсчет количества слов
{
	if ( t ) {
		count ( t->Right, letter );
		if ( *(t->text) == letter )
			c++;
		count ( t->Left, letter );
	}
	return c;
}

int view ( Tree* t, int level ) //Вывод дерева
{
	if ( t ) {
		view ( t->Right, level + 1 );	//вывод правого поддерева
		for ( int i = 0; i < level; i++ )
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts ( t->text );
		view ( t->Left, level + 1 );	//вывод левого поддерева
		return 0;
	}
	return 1;
}

bool delAll ( Tree* t ) //Очистка дерева
{
	if ( t != NULL ) {
		delAll ( t->Left );
		delAll ( t->Right );
		delete t;
		return true;
	}
	return false;
}