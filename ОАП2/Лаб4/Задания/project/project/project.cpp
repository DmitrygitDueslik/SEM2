#include <iostream>
#include <ctime>
using namespace std;

typedef int mililitrs;
typedef int liters;

// макросы
#define ML_TO_L(ml) ((ml) / 1000.0)
#define MAX_LITERS 20      // макс. литров в одном элементе
#define MAX_MILLILITERS 5000 // макс. мл в одном элементе

#define DEBUG
#define RELEASE
#define SECOND 2
int main ( )
{
	srand ( unsigned int ( time ( 0 ) ) );
	int n, k;
	cout << "Input n and k for massive \n";
	cin >> n >> k;
	liters* A = new liters[n];
	mililitrs* B = new mililitrs[k];

	for ( int i = 0; i < n; i++ ) {
		A[i] = rand ( ) % MAX_LITERS + 1;
	}
	for ( int i = 0; i < k; i++ ) {
		B[i] = rand ( ) % MAX_MILLILITERS + 1;
	}

	double total = 0.0;

	for ( int i = 0; i < n; i++ ) {
		total += A[i];  //(неявно)
	}

	// Суммируем миллилитры(перевод в литры)
	for ( int i = 0; i < k; i++ ) {
		// Явное использование макроса
		total += ML_TO_L ( B[i] );  // Milliliters → double
	}

#ifdef DEBUG
	cout << "\n[DEBUG]  A (liters): ";
	for ( int i = 0; i < n; i++ ) cout << A[i] << " ";
	cout << "\n[DEBUG]  B (milliliters): ";
	for ( int i = 0; i < k; i++ ) cout << B[i] << " ";
	cout << "\n";
#endif

#if SECOND == 1
	cout << "\n[DEBUG]  A (liters): ";
	for ( int i = 0; i < n; i++ ) cout << A[i] << " ";
	cout << "\n[DEBUG]  B (milliliters): ";
	for ( int i = 0; i < k; i++ ) cout << B[i] << " ";
	cout << "\n";
#else SECOND ==2
	cout << "\NNO";

#endif

#if defined(SECOND)
	cout << "TRUE";
#endif

#ifdef RELEASE
	cout << "\n[DEBUG]  A (liters): ";
	for ( int i = 0; i < n; i++ ) cout << A[i] << " ";
	cout << "\n[DEBUG]  B (milliliters): ";
	for ( int i = 0; i < k; i++ ) cout << B[i] << " ";
	cout << "\n";
#endif
	cout << "\nTotal volume: " << total << " liters\n";

	delete[] A;
	delete[] B;

	return 0;
}