#include <iostream>
#include <ctime>
using namespace std;
// 1. Пузырьковая сортировка
void massivB ( int* arr, int N )
{
	for ( int i = 0; i < N - 1; i++ ) {
		for ( int j = 0; j < N - i - 1; j++ ) {
			if ( arr[j] > arr[j + 1] ) {
				swap ( arr[j], arr[j + 1] );
			}
		}
	}
}
// 2. Сортировка вставками
void massivC ( int* arr, int N )
{
	for ( int i = 1; i < N; i++ ) {
		int buff = arr[i];
		int j;
		for ( j = i - 1; j >= 0 && arr[j] > buff; j-- )
			arr[j + 1] = arr[j];
		arr[j + 1] = buff;
	}
}
// 3. Сортировка выбором
void massivD ( int* arr, int N )
{
	for ( int i = 0; i < N; i++ ) {
		int min = i;

		for ( int j = i + 1; j < N; j++ )
			min = (arr[j] < arr[min]) ? j : min;

		if ( i != min ) {
			int buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
}
//4.Быстрая сортировка
void massivE ( int* arr, int first, int last )
{
	int mid, count;
	int f = first, l = last;
	mid = arr[(f + l) / 2]; 				//вычисление опорного элемента
	do {
		while ( arr[f] < mid ) f++;
		while ( arr[l] > mid ) l--;
		if ( f <= l ) {
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while ( f < l );
	if ( first < l ) massivE ( arr, first, l );
	if ( f < last ) massivE ( arr, f, last );
}

void printArray ( int* arr, int N )
{
	for ( int i = 0; i < N; i++ ) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main ( )
{
	srand ( time ( 0 ) );
	int N;
	cout << "Введите число N\n";
	cin >> N;
	if ( N < 0 ) {
		cout << "N не может быть меньше нуля";
		return 0;
	}
	int* A = new int[N];
	for ( int i = 0; i < N; i++ ) {
		A[i] = rand ( ) % 999 + 1;
	}
	cout << "Массив A" << endl;
	for ( int i = 0; i < N; i++ ) {
		cout << A[i] << " ";
	}
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	int* E = new int[N];
	for ( int i = 0; i < N; i++ ) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}
	double timeB = 0, timeC = 0, timeD = 0, timeE = 0;
	cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout << "\nОтсортированный массив B пузырьковской сортировкой\n";
	clock_t startB = clock ( );
	massivB ( B, N );
	clock_t endB = clock ( );
	timeB = (double)(endB - startB) * 1000.0 / CLOCKS_PER_SEC;
	printArray ( B, N );
	cout << "Время сортировки B: " << (double)(endB - startB) * 1000.0 / CLOCKS_PER_SEC << " мс\n";
	cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	cout << "\nОтсортированный массив С сортировкой вставкой \n";
	system ( "pause" );
	clock_t startC = clock ( );
	massivC ( C, N );
	clock_t endC = clock ( );
	timeC = (double)(endC - startC) * 1000.0 / CLOCKS_PER_SEC;
	printArray ( C, N );
	cout << "Время сортировки C: " << (double)(endC - startC) * 1000.0 / CLOCKS_PER_SEC << " мс\n";
	cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	cout << "\nОтсортированный массив D сортировкой выбора\n";
	system ( "pause" );
	clock_t startD = clock ( );
	massivD ( D, N );
	clock_t endD = clock ( );
	timeD = (double)(endD - startD) * 1000.0 / CLOCKS_PER_SEC;
	printArray ( D, N );
	cout << "Время сортировки D: " << (double)(endD - startD) * 1000.0 / CLOCKS_PER_SEC << " мс\n";
	cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout << "\nОтсортированный массив Е быстрой сортировкой.\n";
	system ( "pause" );
	clock_t startE = clock ( );
	massivE ( E, 0, N - 1 );
	clock_t endE = clock ( );
	timeE = (double)(endE - startE) * 1000.0 / CLOCKS_PER_SEC;
	printArray ( E, N );
	cout << "Время сортировки E: " << (double)(endE - startE) * 1000.0 / CLOCKS_PER_SEC << " мс\n";
	system ( "pause" );
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
	cout << "B - Пузырьковая" << " | " << timeB << endl;
	cout << "C - Вставками" << " | " << timeC << endl;
	cout << "D - Выбором" << " | " << timeD << endl;
	cout << "E - Быстрая" << " | " << timeE << endl;

	return 0;
}