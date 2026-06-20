#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 10000;

// 1. Пузырьковая сортировка

void bubbleSort ( int arr[], int n )
{
	for ( int i = 0; i < n - 1; i++ ) {
		for ( int j = 0; j < n - i - 1; j++ ) {
			if ( arr[j] > arr[j + 1] ) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// 2. Сортировка Хоара (Quick Sort)
int partition ( int arr[], int low, int high )
{
	int pivot = arr[low]; // Опорный элемент
	int i = low - 1;
	int j = high + 1;

	while ( true ) {
		do { i++; } while ( arr[i] < pivot );
		do { j--; } while ( arr[j] > pivot );

		if ( i >= j ) return j;

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void quickSort ( int arr[], int low, int high )
{
	if ( low >= high ) return;
	if ( low < high ) {
		int p = partition ( arr, low, high );
		quickSort ( arr, low, p );
		quickSort ( arr, p + 1, high );
	}
}

int main ( )
{
	srand ( time ( 0 ) );

	cout << "Размер | Пузырек (мс) | Хоар (мс)\n";
	cout << "----------------------------------\n";

	int sizes[] = { 1000, 2000, 3000, 4000, 5000 };

	for ( int k = 0; k < 5; k++ ) {
		int n = sizes[k];

		int A[MAX_SIZE], B[MAX_SIZE];
		for ( int i = 0; i < n; i++ ) {
			A[i] = rand ( ) % 1000;
			B[i] = rand ( ) % 1000;
		}

		// 2. Формируем массив C по условию В
		// Четные из A + Нечетные из B
		int C[MAX_SIZE];
		int sizeC = 0;

		// Берем четные из A
		for ( int i = 0; i < n; i++ ) {
			if ( A[i] % 2 == 0 ) {
				C[sizeC++] = A[i];
			}
		}
		// Берем нечетные из B
		for ( int i = 0; i < n; i++ ) {
			if ( B[i] % 2 != 0 ) {
				C[sizeC++] = B[i];
			}
		}

		if ( sizeC < 2 ) continue;

		// 3. Копируем C в два отдельных массива для честного теста
		int C_bubble[MAX_SIZE];
		int C_hoare[MAX_SIZE];

		for ( int i = 0; i < sizeC; i++ ) {
			C_bubble[i] = C[i];
			C_hoare[i] = C[i];
		}

		// 4. Замер Пузырька
		auto start = chrono::high_resolution_clock::now ( );
		bubbleSort ( C_bubble, sizeC );
		auto end = chrono::high_resolution_clock::now ( );
		double timeBubble = chrono::duration<double, milli> ( end - start ).count ( );

		// 5. Замер Хоара
		start = chrono::high_resolution_clock::now ( );
		quickSort ( C_hoare, 0, sizeC - 1 );
		end = chrono::high_resolution_clock::now ( );
		double timeHoare = chrono::duration<double, milli> ( end - start ).count ( );

		cout << sizeC << "\t| "
			<< timeBubble << "\t\t| "
			<< timeHoare << endl;
	}

	return 0;
}