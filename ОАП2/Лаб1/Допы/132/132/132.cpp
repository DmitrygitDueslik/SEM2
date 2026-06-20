#include <iostream>
#include<stdio.h>
using namespace std;

int main ( )
{
	
	FILE* F1;
	FILE* F2;
	errno_t err;
	int lines = 6;
	const char* info[] = {
	"3Aист летит над рекой",
		"Берёза зеленеет",
		"4Aлмаз сверкает на солнце",
		"Ветер шумит в листве",
		"5Aнна читает книгу",
		"Дождь стучит по крыше",

	};
	err = fopen_s ( &F1, "F1.txt", "w" );
	if ( err != 0 ) {
		cout << "F1 не открыт";
		return 0;
	}
	for ( int i = 0; i < lines; i++ ) {
		fprintf ( F1, "%s\n", info[i] );
	}
	fclose ( F1 );

	err = fopen_s ( &F1, "F1.txt", "r" );
	if ( err != 0 ) {
		cout << "Не удалось открыть F1 для чтения\n";
		return 1;
	}

	err = fopen_s ( &F2, "F2.txt", "w" );
	if ( err != 0 ) {
		cout << "F2 не открыт\n";
		fclose ( F1 );
		return 1;
	}

	char buffer[256];
	int copied = 0;

	while ( fgets ( buffer, sizeof ( buffer ), F1 ) != NULL ) {
		int len = 0;
		while ( buffer[len] != '\0' && buffer[len] != '\n' ) len++;
		if ( buffer[len] == '\n' ) buffer[len] = '\0';
		if ( len > 0 && buffer[0] >= '0' && buffer[0] <= '9' ) {
			fprintf ( F2, "%s\n", buffer );
			copied++;
		}
	}
	fclose ( F1 );
	fclose ( F2 );

	cout << "Готово! Скопировано строк: " << copied << "\n";
	cout << "Результат в F2.txt\n";

	return 0;
}