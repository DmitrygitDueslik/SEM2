#include <iostream>
#define MAX 100
int* p;
int* tos, * bos;
void push ( int i );
int pop ( void );
void main ( void )
{
	int a, b;
	char s[80];
	p = new int[MAX * sizeof ( int )];
	if ( !p ) {
		printf ( "Ошибка при выделении памяти\n" );
		exit ( 1 );
	}
	tos = p; bos = p + MAX - 1;
	printf ( "Калькулятор \n Для выхода нажать 'q'\n" );
	do {
		printf ( ": " );  gets_s ( s ); //ввод первого числа, второго и знака операции
		switch ( *s ) {
			case '+': a = pop ( ); b = pop ( );
				printf ( "%d\n", a + b );
				push ( a + b ); break;
			case '-':  a = pop ( ); b = pop ( );   //вычитание
				printf ( "%d\n", b - a );
				push ( b - a );  break;
			case '*': 	a = pop ( ); b = pop ( );   //умножение
				printf ( "%d\n", b * a );
				push ( b * a );  break;
			case '/': 	a = pop ( ); b = pop ( );   //деление
				if ( a == 0 ) { printf ( "Деление на 0\n" ); break; }
				printf ( "%d\n", b / a );
				push ( b / a );  break;
			case '.': 	a = pop ( ); push ( a ); //вывод вершины стека
				printf ( "Текущее значение на вершине стека: %d\n", a );
				break;
			default:  	push ( atoi ( s ) ); //конвертация из символа в число
		}
	} while ( *s != 'q' );
}
void push ( int i )
{
	if ( p > bos ) {
		printf ( "Cтек полон\n" );
		return;
	}
	*p = i;
	p++;
}
int pop ( void )
{
	p--;
	if ( p < tos ) {
		printf ( "Стек пуст\n" );
		return 0;
	}
	return *p;
}