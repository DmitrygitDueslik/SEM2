#include <iostream>
#include <ctime>

using namespace std;

int* bubble_sort ( int* arr, int n_arr )
{
	int temp = 0;
	for ( int i = 0; i < n_arr - 1; i++ ) {
		for ( int j = i + 1; j < n_arr; j++ ) {
			if ( arr[i] > arr[j] ) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}

void main ( )
{
	srand ( time ( 0 ) );

	int size;
	cout << "Введите количество товаров: ";
	cin >> size;

	int* arrA = new int[size];
	cout << "\nЦены товаров: ";
	for ( int i = 0; i < size; i++ ) {
		arrA[i] = rand ( ) % 100 + 1;
		cout << arrA[i] << " ";
	}
	cout << endl;

	bubble_sort ( arrA, size );

	cout << "\nОтсортировано: ";
	for ( int i = 0; i < size; i++ ) {
		cout << arrA[i] << " ";
	}
	cout << endl;

	// массив порядка пробивания
	int* arrB = new int[size];
	int max_sum = 0;

	int left = 0;           // индекс для дешёвых товаров
	int right = size - 1;   // индекс для дорогих товаров

	for ( int i = 0; i < size; i++ ) {
		if ( i % 2 == 0 ) {
			arrB[i] = arrA[right];
			max_sum += arrB[i];
			right--;
		}
		else {
			arrB[i] = arrA[left];
			left++;
		}
	}

	cout << "\nПорядок пробивания на кассе: ";
	for ( int i = 0; i < size; i++ ) {
		cout << arrB[i] << " ";
	}
	cout << endl;

	cout << "\nМаксимальная сумма чека: " << max_sum << endl;

	cout << "Платные товары (позиции 1, 3, 5...): ";
	for ( int i = 0; i < size; i += 2 ) {
		cout << arrB[i] << " ";
	}
	cout << "\nБесплатные товары (позиции 2, 4, 6...): ";
	for ( int i = 1; i < size; i += 2 ) {
		cout << arrB[i] << " ";
	}
	cout << endl;

	delete[] arrA;
	delete[] arrB;
}