#include <iostream>
#include <stdio.h>
using namespace std;

int main ( )
{
    FILE* F1;
    FILE* F2;
    errno_t err;

    err = fopen_s ( &F1, "F1.txt", "w" );
    if ( err != 0 ) {
        cout << "Не удалось создать F1.txt\n";
        return 1;
    }

    // Записываем строки (некоторые заканчиваются на 'а')
    fprintf ( F1, "Мамa\n" );
    fprintf ( F1, "Папa\n" );
    fprintf ( F1, "Дом\n" );
    fprintf ( F1, "Рекa\n" );
    fprintf ( F1, "Горa\n" );
    fprintf ( F1, "Стол\n" );
    fprintf ( F1, "Земля\n" );  
    fprintf ( F1, "Тучa\n" );  

    fclose ( F1 );
    cout << "Файл F1.txt создан.\n";

    // 
    err = fopen_s ( &F1, "F1.txt", "r" );
    if ( err != 0 ) {
        cout << "Не удалось открыть F1.txt для чтения\n";
        return 1;
    }

    err = fopen_s ( &F2, "F2.txt", "w" );
    if ( err != 0 ) {
        cout << "Не удалось создать F2.txt\n";
        fclose ( F1 );
        return 1;
    }

    char buffer[256];
    int copied = 0;

    cout << "\nСодержимое F1.txt:\n";
    while ( fgets ( buffer, sizeof ( buffer ), F1 ) !=NULL) {
        cout << "  " << buffer;  // выводим строку

        // Удаляем \n в конце, если есть
        int len = 0;
        while ( buffer[len] != '\0' && buffer[len] != '\n' ) len++;
        if ( buffer[len] == '\n' ) {
            buffer[len] = '\0';
            len--;
        }

        //  строка не пустая и последний символ — 'а'
        if ( len >= 0 && buffer[len] == 'a' ) {
            fprintf ( F2, "%s\n", buffer );
            copied++;
        }
    }

    fclose ( F1 );
    fclose ( F2 );

    // 
    cout << "\nСкопировано в F2.txt строк: " << copied << "\n";

    err = fopen_s ( &F2, "F2.txt", "r" );
    if ( err == 0 ) {
        cout << "\nСодержимое F2.txt:\n";
        while ( fgets ( buffer, sizeof ( buffer ), F2 ) != NULL ) {
            cout << "  " << buffer;
        }
        fclose ( F2 );
    }

    cout << "\nГотово!\n";
    return 0;
}