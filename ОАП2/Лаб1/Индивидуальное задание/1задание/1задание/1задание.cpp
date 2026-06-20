#include <iostream>
#include <ctime>
using namespace std;
int main ( )
{
	FILE* a;
	FILE* b;
	errno_t err;	
	const int nA = 4;
	srand ( (unsigned int)time ( NULL ) );
	err = fopen_s( &a, "A.txt","w" );
	if ( err != 0 ) {
		perror ( "ошибка открытия A.txt" );
		return 0;
	}
	fprintf ( a, "%d", nA );
	fprintf ( a, "\n");

	for ( int i = 0; i < nA; i++ ) {
		for ( int j = 0; j < nA; j++ ) {
			fprintf ( a, "%d", rand ( ) % 50);
			fprintf ( a, " " );
		}
		fprintf ( a, "\n" );
	}
	fclose ( a );

	err = fopen_s ( &b, "B.txt", "w" );
	if ( err != 0 ) {
		perror ( "ошибка  открытия B.txt" );
		return 0;
	}
	fprintf ( b, "%d", nA );
	fprintf ( b, "\n" );

	for ( int i = 0; i < nA; i++ ) {
		for ( int j = 0; j < nA; j++ ) {
			fprintf ( b, "%d", rand ( ) % 50 );
			fprintf ( b, " " );
		}
		fprintf ( b, "\n" );
	}
	fclose ( b );

	//Часть 2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 

	err = fopen_s ( &a, "A.txt", "r" );
	if ( err != 0 ) {
		perror ( "ошибка  открытия A.txt" );
		return 0;
	}
	fscanf_s ( a, "A.txt", &nA );
	int** A = new int* [nA];
	for ( int i = 0; i < nA; i++ ) {
		A[i] = new int[nA];
		for ( int j = 0; j < nA; j++ ) {
			fscanf_s ( a, "%d", &A[i][j] );
		}
	}
	fclose ( a );

	err = fopen_s ( &b, "B.txt", "r" );
	if ( err != 0 ) {
		perror ( "ошибка  открытия B.txt" );
		for ( int i = 0; i < nA; i++ ) delete[] A[i];
		delete[] A; //Не откроется файл- не удалим - утечка
		return 0;
	}
	fscanf_s ( b, "B.txt", &nA );
	int** B = new int* [nA];
	for ( int i = 0; i < nA; i++ ) {
		B[i] = new int[nA];
		for ( int j = 0; j < nA; j++ ) {
			fscanf_s ( b, "%d", &B[i][j] );
		}
	}
	fclose ( b);

	//Часть 3 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	int** C = new int* [nA];
	for ( int i = 0; i < nA; i++ ) {
		C[i] = new int[nA] ( );
		for ( int j = 0; j < nA; j++ ) {
			for ( int k = 0; k < nA; k++ ) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	//4>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	FILE* c;
	err = fopen_s ( &c, "C.txt", "w" );
	if ( err != 0 ) {
		perror ( "ошибка  открытия B.txt" );
		return 0;
	}
	fprintf ( c, "%d ", nA );  
	fprintf ( c, "\n" );
	for ( int i = 0; i < nA; i++ ) {
		for ( int j = 0; j < nA; j++ ) {
			fprintf ( c, "%d ", C[i][j] );
			fprintf ( c, " " );
		}
		fprintf ( c, "\n" );
	}
	fclose (c );


	cout << "Матрица A (" << nA << "x" << nA << "):\n";
	for ( int i = 0; i < nA; i++ ) {
		for ( int j = 0; j < nA; j++ ) 
		{ 
			cout << A[i][j] << " ";
		}

		cout << "\n";
	}

	cout << "\nМатрица B (" << nA << "x" << nA << "):\n";
	for ( int i = 0; i < nA; i++ ) {
		for ( int j = 0; j < nA; j++ ) {
			cout << B[i][j] << " ";
		}
			cout << "\n";
	}

	cout << "\nМатрица C = A × B (" << nA << "x" << nA << "):\n";
	for ( int i = 0; i < nA; i++ ) {
		for ( int j = 0; j < nA; j++ )
		{
			cout << C[i][j] << " "; 
		}
		cout << "\n";
	}


	return 0;
}