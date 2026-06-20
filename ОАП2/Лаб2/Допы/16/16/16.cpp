#include <iostream>
#include <fstream>
using namespace std;

int main ( )
{
    
    ifstream f1 ( "FILE1.txt" );
    char line[256], second[256];
    f1.getline ( line, 256 );
    f1.close ( );

    
    int i = 0;
    while ( line[i] != ' ' && line[i] != '\0' ) i++; // пропускаем  слово1
    i++; // пропуск пробела

    int j = 0;
    while ( line[i] != ' ' && line[i] != '\0' ) {
        second[j++] = line[i++];
    }
    second[j] = '\0';

    cout << "Второе слово: " << second << "\n";

 
    f1.open ( "FILE1.txt" );
    ofstream f2 ( "FILE2.txt" );

    while ( f1.getline ( line, 256 ) ) {
        
        // ищем подстроку 
        if ( strstr ( line, second ) != nullptr ) {
            f2 << line << '\n';
        }
    }

    f1.close ( );
    f2.close ( );

  
    ifstream f2r ( "FILE2.txt" );
    char last[256] = "";
    char buf[256];

    while ( f2r.getline ( buf, 256 ) ) {
        
        int k = 0;
        while ( buf[k] != '\0' ) {
            last[k] = buf[k];
            k++;
        }
        last[k] = '\0';
    }
    f2r.close ( );

  
    int digits = 0;
    for ( int i = 0; last[i] != '\0'; i++ ) {
        if ( last[i] >= '0' && last[i] <= '9' ) {
            digits++;
        }
    }

    cout << "Последняя строка: " << last << "\n";
    cout << "Цифр в ней: " << digits << "\n";

    return 0;
}