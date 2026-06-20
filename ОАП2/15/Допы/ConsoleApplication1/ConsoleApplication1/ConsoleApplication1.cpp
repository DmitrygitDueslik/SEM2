#include <iostream>
#include <chrono> // Для замера времени
#include <cstdlib> // Для rand()
#include <ctime>   // Для srand()
#include <iomanip> // Для красивого вывода таблицы

using namespace std;

const int MAX_SIZE = 10000; // Максимальный размер массива

// Доп. задание 2: Сортировка выбором (Selection Sort)

void selectionSort ( int arr[], int n )
{
	for ( int i = 0; i < n - 1; i++ ) {
		int minIndex = i;
		// Ищем индекс минимального элемента в остатке массива
		for ( int j = i + 1; j < n; j++ ) {
			if ( arr[j] < arr[minIndex] ) {
				minIndex = j;
			}
		}

		if ( minIndex != i ) {
			swap ( arr[i], arr[minIndex] );
		}
	}
}

// Доп. задание 3: Сортировка вставками (Insertion Sort)

void insertionSort ( int arr[], int n )
{
	for ( int i = 1; i < n; i++ ) {
		int key = arr[i]; // Элемент, который нужно вставить
		int j = i - 1;

		// Сдвигаем элементы больше key вправо
		while ( j >= 0 && arr[j] > key ) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key; // Вставляем key на освободившееся место
	}
}

// Доп. задание 4: Сортировка Шелла (Shell Sort)
void shellSort ( int arr[], int n )
{
	// Начинаем с большого шага, делим пополам на каждой итерации
	for ( int gap = n / 2; gap > 0; gap /= 2 ) {
		// Применяем сортировку вставками для элементов с шагом gap
		for ( int i = gap; i < n; i++ ) {
			int temp = arr[i];
			int j;
			// Сравниваем и сдвигаем элементы с учетом шага
			for ( j = i; j >= gap && arr[j - gap] > temp; j -= gap ) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

int main ( )
{
	srand ( time ( 0 ) );
	cout << "=== Дополнительные задания 2, 3, 4 ===\n";
	cout << "Сравнение скорости сортировок: Выбором, Вставками, Шелла\n";
	cout << "Размеры массивов: 1000, 2000, 3000, 4000, 5000\n\n";

	// Заголовок таблицы
	cout << left << setw ( 10 ) << "Размер"
		<< setw ( 20 ) << "Выбором (мс)"
		<< setw ( 20 ) << "Вставками (мс)"
		<< setw ( 20 ) << "Шелла (мс)" << endl;
	cout << string ( 70, '-' ) << endl;

	int sizes[] = { 1000, 2000, 3000, 4000, 5000 };

	for ( int k = 0; k < 5; k++ ) {
		int n = sizes[k]; // Текущий размер массива

		int Source[MAX_SIZE];
		for ( int i = 0; i < n; i++ ) {
			Source[i] = rand ( ) % 10000;
		}

		int C_select[MAX_SIZE];
		int C_insert[MAX_SIZE];
		int C_shell[MAX_SIZE];

		for ( int i = 0; i < n; i++ ) {
			C_select[i] = Source[i];
			C_insert[i] = Source[i];
			C_shell[i] = Source[i];
		}

		double t1, t2, t3;
		auto start = chrono::high_resolution_clock::now ( );
		auto end = chrono::high_resolution_clock::now ( );

		start = chrono::high_resolution_clock::now ( );
		selectionSort ( C_select, n );
		end = chrono::high_resolution_clock::now ( );
		t1 = chrono::duration<double, milli> ( end - start ).count ( );

		start = chrono::high_resolution_clock::now ( );
		insertionSort ( C_insert, n );
		end = chrono::high_resolution_clock::now ( );
		t2 = chrono::duration<double, milli> ( end - start ).count ( );

		start = chrono::high_resolution_clock::now ( );
		shellSort ( C_shell, n );
		end = chrono::high_resolution_clock::now ( );
		t3 = chrono::duration<double, milli> ( end - start ).count ( );

		cout << left << setw ( 10 ) << n
			<< setw ( 20 ) << fixed << setprecision ( 2 ) << t1
			<< setw ( 20 ) << t2
			<< setw ( 20 ) << t3 << endl;
	}

	return 0;
}