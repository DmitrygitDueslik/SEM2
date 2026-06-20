#include <iostream>
#include <fstream>
using namespace std;

int main ( )
{
    char line[256];

    
    cout << "Enter digit groups (123 00 456 0): ";
    cin.getline ( line, 256 );


    ofstream fout ( "file.txt" );
    fout << line;
    fout.close ( );

   
    ifstream fin ( "file.txt" );
    fin.getline ( line, 256 );  
    fin.close ( );

    
    char shortest[256] = "";
    int minLen = 999;  
    int i = 0;

    while ( line[i] != '\0' ) {
        // Пропускаем пробелы
        while ( line[i] == ' ' ) i++;
        if ( line[i] == '\0' ) break;

        int start = i;
        while ( line[i] != ' ' && line[i] != '\0' ) i++;
        int end = i;
        int len = end - start;

        
        if ( len < minLen ) {
            minLen = len;
            
            for ( int j = 0; j < len; j++ ) {
                shortest[j] = line[start + j];
            }
            shortest[len] = '\0';
        }
    }

    
    cout << "Shortest group: \"" << shortest << "\"\n";
    return 0;
}