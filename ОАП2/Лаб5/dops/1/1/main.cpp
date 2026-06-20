#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;
using namespace MatrixLib;

void printLine ( )
{
	cout << "================================================" << endl;
}

void printTitle ( const string& title )
{
	cout << "\n" << title << endl;
	printLine ( );
}

int main ( )
{
	printTitle ( "Матрица целых чисел (int) 2x2" );

	Matrix<int> m1 ( 2, 2 );
	m1.set ( 0, 0, 5 );
	m1.set ( 0, 1, 3 );
	m1.set ( 1, 0, 2 );
	m1.set ( 1, 1, 4 );
	cout << "Матрица m1:" << endl;
	m1.print ( );

	Matrix<int> m2 ( 2, 2 );
	m2.set ( 0, 0, 1 );
	m2.set ( 0, 1, 2 );
	m2.set ( 1, 0, 3 );
	m2.set ( 1, 1, 1 );
	cout << "\nМатрица m2:" << endl;
	m2.print ( );

	Matrix<int> m3 = m1 + m2;
	cout << "\nm1 + m2:" << endl;
	m3.print ( );

	Matrix<int> m4 = m1 * 2;
	cout << "\nm1 * 2:" << endl;
	m4.print ( );

	printTitle ( " Умножение матриц (int)" );

	Matrix<int> m5 ( 2, 3 );
	m5.set ( 0, 0, 1 ); m5.set ( 0, 1, 2 ); m5.set ( 0, 2, 3 );
	m5.set ( 1, 0, 4 ); m5.set ( 1, 1, 5 ); m5.set ( 1, 2, 6 );
	cout << "Матрица m5 (2x3):" << endl;
	m5.print ( );

	Matrix<int> m6 ( 3, 2 );
	m6.set ( 0, 0, 7 ); m6.set ( 0, 1, 8 );
	m6.set ( 1, 0, 9 ); m6.set ( 1, 1, 10 );
	m6.set ( 2, 0, 11 ); m6.set ( 2, 1, 12 );
	cout << "\nМатрица m6 (3x2):" << endl;
	m6.print ( );

	Matrix<int> m7 = m5 * m6;
	cout << "\nm5 * m6 (результат 2x2):" << endl;
	m7.print ( );

	printTitle ( " Матрица вещественных чисел (double) 3x3" );

	Matrix<double> d1 ( 3, 3 );
	d1.set ( 0, 0, 1.5 ); d1.set ( 0, 1, 2.3 ); d1.set ( 0, 2, 3.1 );
	d1.set ( 1, 0, 4.2 ); d1.set ( 1, 1, 5.5 ); d1.set ( 1, 2, 6.8 );
	d1.set ( 2, 0, 7.1 ); d1.set ( 2, 1, 8.9 ); d1.set ( 2, 2, 9.4 );
	cout << "Матрица d1:" << endl;
	d1.print ( );

	Matrix<double> d2 ( 3, 3 );
	d2.fill ( 2.0 );
	cout << "\nМатрица d2 (заполнена 2.0):" << endl;
	d2.print ( );

	Matrix<double> d3 = d1 + d2;
	cout << "\nd1 + d2:" << endl;
	d3.print ( );

	Matrix<double> d4 = d1 * 0.5;
	cout << "\nd1 * 0.5:" << endl;
	d4.print ( );

	printTitle ( " Проверка методов get() и set()" );

	Matrix<int> test ( 3, 3 );
	int num = 1;
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 3; j++ ) {
			test.set ( i, j, num++ );
		}
	}
	cout << "Матрица 3x3 с числами от 1 до 9:" << endl;
	test.print ( );

	cout << "\nЭлемент [0,0] = " << test.get ( 0, 0 ) << endl;
	cout << "Элемент [1,1] = " << test.get ( 1, 1 ) << endl;
	cout << "Элемент [2,2] = " << test.get ( 2, 2 ) << endl;

	test.set ( 1, 1, 99 );
	cout << "\nПосле set(1, 1, 99):" << endl;
	test.print ( );

	return 0;
}