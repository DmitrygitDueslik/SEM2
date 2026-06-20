#include <iostream>
#include <fstream>
using namespace std;

int main ( )
{
 
    ofstream createFile ( "FILE1.txt" );
    createFile << "Cat\n";
    createFile << "Blue car\n";
    createFile << "Snow\n";
    createFile << "Tree on castle\n";
    createFile << "Chair\n";
    createFile << "Window\n";
    createFile << "\n";          
    createFile << "Notebook";
    createFile.close ( );

    ifstream infile ( "FILE1.txt" );
    ofstream outfile ( "FILE2.txt" );

    char line[256];
    int totalChars = 0;

    while ( infile.getline ( line, 256 ) ) {
        
        int words = 0;
        bool inWord = false;

        for ( int i = 0; line[i] != '\0'; i++ ) {
            if ( line[i] != ' ' && line[i] != '\t' ) {
                if ( !inWord ) {
                    words++;
                    inWord = true;
                }
            }
            else {
                inWord = false;
            }
        }

        
        if ( words == 1 ) {
            outfile << line << '\n';
            // Считаем длину строки (без \n)
            int len = 0;
            while ( line[len] != '\0' ) len++;
            totalChars += len;
        }
    }

    infile.close ( );
    outfile.close ( );

    
    cout << "\n=== Содержимое FILE2.txt ===\n";
    ifstream f2 ( "FILE2.txt" );
    char buf[256];

    while ( f2.getline ( buf, 256 ) ) {
        cout << "\"" << buf << "\"\n";
    }
    f2.close ( );

    
    cout << "\nОбщее количество символов в FILE2.txt: " << totalChars << endl;

    return 0;
}