#include <iostream>
#include <fstream>
using namespace std;

int main ( )
{
    char input[256];

   
    cout << "Введите строку (цифры и слова через пробел): ";
    cin.getline ( input, 256 );


    ofstream fout ( "data.txt" );
    fout << input;
    fout.close ( );

    
    ifstream fin ( "data.txt" );
    fin.getline ( input, 256 );
    fin.close ( );

    //  Разбираем строку
    int i = 0;
    cout << "\nЧётные числа: ";

    while ( input[i] != '\0' ) {
        // Пропускаем пробелы
        while ( input[i] == ' ' ) i++;
        if ( input[i] == '\0' ) break;

        // Начало
        int start = i;
        while ( input[i] != ' ' && input[i] != '\0' ) i++;
        int end = i;

        // состоит ли ТОЛЬКО из цифр
        bool isNumber = true;
        for ( int j = start; j < end; j++ ) {
            if ( input[j] < '0' || input[j] > '9' ) {
                isNumber = false;
                break;
            }
        }

        // Если это число — преобразуем в int и проверим чётность
        if ( isNumber ) {
            int num = 0;
            for ( int j = start; j < end; j++ ) {
                num = num * 10 + (input[j] - '0');
            }
            if ( num % 2 == 0 ) {
                cout << num << " ";
            }
        }
    }

    cout << "\n";
    return 0;
}