#include <iostream>
#include <stdio.h>
using namespace std;
int main ( )
{
	FILE* f1;
	FILE* f2;
	errno_t err;

	err = fopen_s ( &f1, "F1.txt", "w" );
	if ( err != 0 ) {
		perror ( "ошибка открытия F1.txt" );
		return 0;
	}
	int countlines = 6;
	const char* lines[] = {
		"Aист летит над рекой",
		"Берёза зеленеет",
		"Aлмаз сверкает на солнце",
		"Ветер шумит в листве",
		"Aнна читает книгу",
		"Дождь стучит по крыше",
	};
	for ( int i = 0; i < countlines; i++ ) {
		fprintf ( f1, "%s\n", lines[i] );
	}
	fclose ( f1 );

	err = fopen_s ( &f1, "F1.txt", "r" );
	if ( err != 0 ) {
		perror ( "ошибка открытия F1.txt" );
		return 0;
	}
	err = fopen_s ( &f2, "F2.txt", "w" );
		if ( err != 0 ) {
			perror ( "ошибка открытия F2.txt" );
			fclose ( f1 );
			return 0;
		}
	char buffer[256];
	int copied = 0;
	while ( fgets ( buffer, sizeof ( buffer ), f1 ) != NULL ) {
		
		int len = 0;
		while ( buffer[len] != '\0' && buffer[len] != '\n' ) len++;
		if ( buffer[len] == '\n' ) buffer[len] = '\0';

		// Пропускаем пустые строки
		if ( len == 0 ) continue;

		if ( buffer[0] == 'A' ) {
			fprintf ( f2, "%s\n", buffer );
			cout << "  " << buffer << "\n";
			copied++;
		}
	}
	fclose ( f1 );
	fclose ( f2 );

	cout << "\nСкопировано строк: " << copied << "\n";
	cout << "Результат записан в файл F2.txt\n";

	return 0;
}