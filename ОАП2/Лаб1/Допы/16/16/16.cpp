#include <iostream>
#include <ctime>;
#include <stdlib.h>
using namespace std;
int main ( )
{

	FILE* fileA;
	FILE* fileB;
	FILE* fileC;
	srand ( (unsigned int)time (NULL) );
	errno_t err;
	err = fopen_s ( &fileA, "fileA.txt", "w" );
	if ( err != 0 ) {
		cout << "fileA не открыт";
		return 0;
	}
	err = fopen_s ( &fileB, "fileB.txt", "w" );
	if ( err != 0 ) {
		cout << "fileB не открыт";
		fclose ( fileA );
		return 0;
	}
	int count = 10;
	for ( int i = 0; i < count; i++ ) {
		fprintf ( fileA, "%d ", rand ( ) % 20 + 1 );
	}
	for ( int i = 0; i < count; i++ ) {
		fprintf ( fileB, "%d ", rand ( ) % 20 + 1 );
	}
	fclose ( fileA );
	fclose ( fileB );

	int filea[10], fileb[10];

	err = fopen_s ( &fileA, "fileA.txt", "r" );
	if ( err != 0 ) {
		cout << "fileA не открыт";
		return 0;
	}
	err = fopen_s ( &fileB, "fileB.txt", "r" );
	if ( err != 0 ) {
		cout << "fileB не открыт";
		fclose ( fileA );
		return 0;
	}

	for ( int i = 0; i < count; i++ ) {
		fscanf_s( fileA, "%d", &filea[i] );
		fscanf_s( fileB, "%d", &fileb[i] );
	}

	fclose ( fileA );
	fclose ( fileB );

	cout << "Прочитано из fileA: ";
	for ( int i = 0; i < count; i++ ) cout << filea[i] << "     ";
	cout << "\nПрочитано из fileB: ";
	for ( int i = 0; i < count; i++ ) cout << fileb[i] << "     ";
	cout << endl;

	err = fopen_s ( &fileC, "fileC", "w" );
	if ( err != 0 ) {
		cout << "fileC не открыт";
		return 0;
	}

	int filec[10];
	for ( int i = 0; i < count; i++ ) {
		fprintf ( fileC, "%d ", ( filea[i] + fileb[i]) );
		filec[i] = filea[i] + fileb[i];
	}
	fclose ( fileC );
	cout << "Прочитано из fileC: ";
	for ( int i = 0; i < count; i++ ) {
		cout << filec[i] << "     ";
	}
	return 0;
}