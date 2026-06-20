#include <stdio.h>  
#include <fstream>
#include <cstring>  // для strlen
using namespace std;

int main ( )
{
    int k;
    FILE* fin = nullptr;  // инициализация nullptr

    // Проверка успешности открытия файла
    if ( fopen_s ( &fin, "f:\\name1.txt", "rt" ) != 0 || fin == nullptr ) {
        printf ( "Ошибка открытия файла\n" );
        return 1;
    }

    ofstream fout1 ( "f:\\name2.txt" );
    ofstream fout2 ( "f:\\name3.txt" );

    printf ( "Vvedite 4islo k\n" );
    scanf_s ( "%d", &k );

    while ( !feof ( fin ) ) {
        char s[255] = "";
        fgets ( s, 254, fin );

        // Проверяем, не произошла ли ошибка чтения
        if ( ferror ( fin ) ) {
            break;
        }

        size_t len = strlen ( s );  // используем size_t вместо int
        if ( len <= k )
            fout1 << s;
        else {
            // Явно приводим size_t к int для вычисления начального индекса
            int start_index = static_cast<int>(len) - k - 1;
            if ( start_index < 0 ) start_index = 0;

            for ( int i = start_index; i < static_cast<int> ( len ); i++ )
                fout1 << s[i];
        }

        if ( len < k )
            fout2 << " " << endl;
        else
            fout2 << s[k - 1] << endl;
    }

    if ( fin != nullptr ) {
        fclose ( fin );
    }

    fout1.close ( );
    fout2.close ( );
    return 0;
}