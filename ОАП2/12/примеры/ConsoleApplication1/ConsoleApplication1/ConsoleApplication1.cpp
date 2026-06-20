#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int data;
	Node* left, * right;
};

Node* tree = nullptr;
void insert ( int a, Node** t )
{
	if ( (*t) == NULL ) {
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if ( a > (*t)->data )
		insert ( a, &(*t)->right );
	else insert ( a, &(*t)->left );
}

void print ( Node* t, int u )
{
	if ( t == NULL ) return;
	else {
		print ( t->left, u++ );
		for ( int i = 0; i < u; i++ )
			cout << "|";
		cout << t->data << endl;
		u--;
	}
	print ( t->right, ++u );
}
void main ( )
{
	int count, temp;
	cout << "Введите количество элементов  "; cin >> count;
	for ( int i = 0; i < count; i++ ) {
		cout << "Введите число  ";	cin >> temp;
		insert ( temp, &tree );
	}
	cout << "ваше дерево\n";
	print ( tree, 0 );
	_getch ( );
}