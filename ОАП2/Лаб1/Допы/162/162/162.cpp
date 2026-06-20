#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main ( )
{
    FILE* file1;
    FILE* file2;
    errno_t err;

    srand ( (unsigned int)time ( NULL ) );

    err = fopen_s ( &file1, "file1.txt", "w" );
    if ( err != 0 ) {
        cout << "Ошибка открытия file1.txt\n";
        return 1;
    }

    // Генерируем 5 положительных двузначных чисел 
    for ( int k = 0; k < 2; k++ ) {
        for ( int i = 0; i < 5; i++ ) {
            fprintf ( file1, "%d ", rand ( ) % 90 + 10 );
        }
        // Генерируем 5 отрицательных
        for ( int j= 0; j < 5; j++ ) {
            fprintf ( file1, "%d ", -(rand ( ) % 90 + 10) );
        }
    }
    fclose ( file1 );

    cout << "Файл file1.txt создан.\n";

    // Читаем file1 и записываем в file2 блоками по 10 
    err = fopen_s ( &file1, "file1.txt", "r" );
    if ( err != 0 ) {
        cout << "Не удалось открыть file1.txt для чтения\n";
        return 1;
    }

    err = fopen_s ( &file2, "file2.txt", "w" );
    if ( err != 0 ) {
        cout << "Не удалось создать file2.txt\n";
        fclose ( file1 );
        return 1;
    }

    // Массивы для хранения чисел
    int pos[20], neg[20];
    int posCount = 0, negCount = 0;
    int x;

    // Читаем все числа из file1
    while ( fscanf_s ( file1, "%d", &x ) == 1 ) {
        if ( x > 0 ) {
            pos[posCount++] = x;
        }
        else if ( x < 0 ) {
            neg[negCount++] = x;
        }
    }
    fclose ( file1 );

    // Записываем в file2: сначала до 10 полож., потом до 10 отр.
    int p = 0, q = 0;

    // Положительные (до 10)
    int written = 0;
    while ( written < 10 && p < posCount ) {
        fprintf ( file2, "%d ", pos[p++] );
        written++;
    }

    // Отрицательные (до 10)
    written = 0;
    while ( written < 10 && q < negCount ) {
        fprintf ( file2, "%d ", neg[q++] );
        written++;
    }

    fclose ( file2 );
    cout << " Результат в file2.txt\n";

    err = fopen_s ( &file1, "file1.txt", "r" );
    if ( err != 0 ) {
        cout << "Не удалось открыть file1.txt для чтения\n";
        return 1;
    }

    err = fopen_s ( &file2, "file2.txt", "r" );
    if ( err != 0 ) {
        cout << "Не удалось создать file2.txt\n";
        fclose ( file1 );
        return 1;
    }
    printf ( "\nfile1 >>>>>>>> " );
    while ( fscanf_s ( file1, "%d ", &x ) == 1 ) {
        printf ( "%d ", x );
    }
    printf ( "\nfile2 >>>>>>>> " );

    while ( fscanf_s ( file2, "%d ", &x ) == 1 ) {
        printf( "%d ", x );
    }
    
    fclose ( file1 );
    fclose ( file2 );
    return 0;
}