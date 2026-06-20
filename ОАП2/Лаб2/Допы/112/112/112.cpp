#include <iostream>
#include <fstream>
using namespace std;

int main ( )
{
    char line1[256], line2[256];

   
    cout << "Введите первую строку: ";
    cin.getline ( line1, 256 );
    cout << "Введите вторую строку: ";
    cin.getline ( line2, 256 );

    ofstream fout ( "data.txt" );
    fout << line1 << '\n';
    fout << line2 << '\n';
    fout.close ( );

    ifstream fin ( "data.txt" );
    fin.getline ( line1, 256 );
    fin.getline ( line2, 256 );
    fin.close ( );

  
    char shortest[256] = "";
    int minLen = 999;
    char word[256];
    int wStart = 0, wEnd = 0, i = 0;

    // Обрабатываем первую строку
    while ( line1[i] != '\0' ) {
       
        while ( line1[i] == ' ' && line1[i] != '\0' ) i++;
        if ( line1[i] == '\0' ) break;

        wStart = i;
        while ( line1[i] != ' ' && line1[i] != '\0' ) i++;
        wEnd = i;

       
        int len = 0;
        for ( int j = wStart; j < wEnd; j++ ) {
            word[len++] = line1[j];
        }
        word[len] = '\0';

        
        if ( len < minLen ) {
            minLen = len;
          
            for ( int k = 0; k <= len; k++ ) {
                shortest[k] = word[k];
            }
        }
    }

    //  самое длинное слово во второй строке
    char longest[256] = "";
    int maxLen = 0;
    i = 0;

    while ( line2[i] != '\0' ) {
        while ( line2[i] == ' ' && line2[i] != '\0' ) i++;
        if ( line2[i] == '\0' ) break;

        wStart = i;
        while ( line2[i] != ' ' && line2[i] != '\0' ) i++;
        wEnd = i;

        int len = 0;
        for ( int j = wStart; j < wEnd; j++ ) {
            word[len++] = line2[j];
        }
        word[len] = '\0';

        if ( len > maxLen ) {
            maxLen = len;
            for ( int k = 0; k <= len; k++ ) {
                longest[k] = word[k];
            }
        }
    }

   
    cout << "\nСамое короткое слово в первой строке: \"" << shortest << "\"\n";
    cout << "Самое длинное слово во второй строке: \"" << longest << "\"\n";

    return 0;
}