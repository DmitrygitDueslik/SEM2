#include <iostream>
#include <fstream>
using namespace std;

int main ( )
{

    ofstream create ( "FILE1.txt" );
    create << "Artist\n";
    create << "Hello\n";
    create << "Apple pie\n";      
    create << "Africa\n";
    create << "Arthas\n";
    create << "Banana\n";
    create.close ( );

    ifstream file1 ( "FILE1.txt" );
    ofstream file2 ( "FILE2.txt" );

    char buffer[256];
    int totalWords = 0;

   
    while ( file1.getline ( buffer, 256 ) ) {
      
        if ( buffer[0] == '\0' ) continue;

        
        if ( buffer[0] == 'A' ) {
            file2 << buffer << '\n';  

            // Считаем слова в этой строке
            bool inWord = false;
            for ( int i = 0; buffer[i] != '\0'; i++ ) {
                if ( buffer[i] != ' ' && buffer[i] != '\t' ) {
                    if ( !inWord ) {
                        totalWords++;
                        inWord = true;
                    }
                }
                else {
                    inWord = false;
                }
            }
        }
    }

    file1.close ( );
    file2.close ( );

    
    cout << "Строки, начинающиеся с 'A', скопированы в FILE2.txt";
    ifstream open ( "FILE2.txt" );
    cout << "\n";
    char line[256];
    while ( open.getline ( line, 256 ) ) {
        cout << line << "; ";
    }
    open.close();
    cout << "\n";
    cout << "Общее количество слов в FILE2.txt: " << totalWords << endl;

    return 0;
}