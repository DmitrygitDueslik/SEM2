#include <iostream>
#include <stdio.h>
using namespace std;

int main ( )
{
    FILE* fileA;
    FILE* fileB;
    errno_t err;

    err = fopen_s ( &fileA, "fileA.txt", "r" );
    if ( err != 0 ) {
        cout << "Ошибка: не найден fileA.txt\n";
        return 1;
    }

    // Массив для хранения чисел 
    int numbers[100];
    int n = 0;
    int x;

    // Читаем все числа из fileA
    printf ( "fileA >>>>> " );

    while ( n < 100 && fscanf_s ( fileA, "%d", &x ) == 1 ) {
        printf ( "%d ", x );
        numbers[n] = x;
        n++;
    }
    printf ( "\n" );
    fclose ( fileA );

    if ( n == 0 ) {
        cout << "Файл fileA.txt пуст.\n";
        // Создаём пустой fileB
        err = fopen_s ( &fileB, "fileB.txt", "w" );
        if ( err == 0 ) fclose ( fileB );
        return 0;
    }

    //
    err = fopen_s ( &fileB, "fileB.txt", "w" );
    if ( err != 0 ) {
        cout << "Не удалось создать fileB.txt\n";
        return 1;
    }

    //  Находим числа, которые встречаются ровно 1 раз 
    for ( int i = 0; i < n; i++ ) {
        int count = 0;

        // Считаем, сколько раз numbers[i] встречается
        for ( int j = 0; j < n; j++ ) {
            if ( numbers[j] == numbers[i] ) {
                count++;
            }
        }

        // Если число уникальное — записываем
        if ( count == 1 ) {
            fprintf ( fileB, "%d\n", numbers[i] );
        }
    }

    fclose ( fileB );
    err = fopen_s ( &fileB, "fileB.txt", "r" );
    if ( err != 0 ) {
        cout << "Не удалось создать fileB.txt\n";
        return 1;
    }
    printf ( "fileB >>>>> " );
    while ( n < 100 && fscanf_s ( fileB, "%d", &x ) == 1 ) {
        
        printf ( "%d ", x );
    }
    fclose ( fileB );
    return 0;
}