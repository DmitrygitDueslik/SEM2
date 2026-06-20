#include <iostream>
using namespace std;

int main ( )
{
	FILE* fileA;
	FILE* fileB;
	errno_t err;


	int digitals[100];
	int n = 0;
	int i, j,k, count;
	err = fopen_s ( &fileA, "fileA.txt", "r" );
	if ( err != 0 ) {
		cout << "fileA не открыт";
		return 0;
	}
	
	while ( n < 100 && fscanf ( fileA, "%d", &digitals[n] ) == 1 ) {
		n++;
	}
	fclose ( fileA );

	if ( n == 0 ) {
		printf ( "Файл fileA.txt пуст.\n" );
		return 0;
	}
	err = fopen_s ( &fileB, "fileB.txt", "w" );
	if ( err != 0 ) {
		cout << "fileB не открыт";
		return 0;
	}

	int written[100] = { 0};

	for ( i = 0; i < n; i++ ) {
		
		if ( written[i] ) continue;  // уже обработали это значение
		
		
		count = 0;
		for ( j = 0; j < n; j++ ) {
			if ( digitals[j] == digitals[i] ) {
				count++;
			}
		}
		if ( count > 2 ) {
			fprintf ( fileB, "%d\n", digitals[i] );


			for ( k = 0; k < n; k++ ) {
				if ( digitals[j] == digitals[i] ) {
					written[j] = 1;//Пометка числа
				}
			}
		}
	}
		fclose ( fileB );
		printf ( "Готово! Результат записан в fileB.txt\n" );
		return 0;
}