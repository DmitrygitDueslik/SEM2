#include <iostream>
#include <ctime>
using namespace std;

int* bubble_sort ( int* arr, int n_arr )
{
	int temp = 0;

	for ( int i = n_arr - 1; i >= 0; i-- ) {
		for ( int j = i - 1; j >= 0; j-- ) {
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
	cout << "Введите количество участников: ";
	cin >> size;

	int* arrA = new int[size];
	cout << "\nРезультаты участников: ";
	for ( int i = 0; i < size; i++ ) {
		arrA[i] = rand ( ) % 100 + 1;
		cout << arrA[i] << " ";
	}
	cout << endl;

	bubble_sort ( arrA, size );

	for ( int i = 0; i < size; i++ ) {
		cout << "Место " << i + 1 << ": " << arrA[i] << "\n";
	}

	int prize_count = 0;
	int unique_scores = 0;
	int current_score = arrA[0];

	for ( int i = 0; i < size; i++ ) {
		if ( arrA[i] != current_score ) {
			unique_scores++;
			current_score = arrA[i];

			if ( unique_scores >= 3 ) {
				break;
			}
		}

		prize_count++;
	}

	cout << "\nПризеры с топ-3 уникальными результатами" << endl;
	cout << "Количество призеров = " << prize_count << endl;

	delete[] arrA;
}