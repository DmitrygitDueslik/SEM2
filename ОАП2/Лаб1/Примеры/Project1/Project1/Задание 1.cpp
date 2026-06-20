#include <stdio.h>
#include <iostream>
int main ( )
{
    setlocale ( LC_ALL, "" );
    int a; errno_t err;
    FILE* f;
    err = fopen_s ( &f, "a.txt", "w" );
    if ( err != 0 ) {
        perror ( "Невозможно создать файл\n" );
        return EXIT_FAILURE;
    }
    for ( a = 0; a < 70; a += 3 ) {
        fprintf ( f, "%d, ", a );
    }
    fclose ( f );  // закрываем файл после записи
    printf ( "Данные записаны в файл a.txt\n" );

    err = fopen_s ( &f, "a.txt", "r" );
    if ( err != 0 )  
    {
        printf ( "Ошибка открытия файла\n" );
        return -1;
    }

    // читаем и выводим содержимое файла
    err = fgets ( str, sizeof ( str ), mf );

    printf ( "\n" );
    fclose ( f );
    return 0;
}