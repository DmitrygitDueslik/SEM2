    #include <iostream>
    #include <fstream>
    using namespace std;

    int main ( )
    {

        ofstream createFile ( "FILE1.txt" );
        createFile << "Line one\n";
        createFile << "Line two\n";
        createFile << "Line three\n";
        createFile << "Line four\n";
        createFile << "Line five\n";
        createFile << "Line six with last word TEST";
        createFile.close ( );

        ifstream infile ( "FILE1.txt" );
        ofstream outfile ( "FILE2.txt" );

        char line[256];
        int counter = 0;

        while ( infile.getline ( line, 256 ) ) {
            counter++;
            if ( counter >= 4 ) {
                outfile << line << '\n';
            }
        }

        infile.close ( );
        outfile.close ( );

        // 3. Подсчет символов в последнем слове
        ifstream f2 ( "FILE2.txt" );
        char lastLine[256] = "";
        char currentLine[256];

        while ( f2.getline ( currentLine, 256 ) ) {
            // Копируем строку
            int i = 0;
            while ( currentLine[i] != '\0' ) {
                lastLine[i] = currentLine[i];
                i++;
            }
            lastLine[i] = '\0';
        }
        f2.close ( );

        // 4. Покажем последнюю строку для отладки
        cout << "Последняя строка: '" << lastLine << "'\n";

        // 5. Считаем длину строки
        int len = 0;
        while ( lastLine[len] != '\0' ) len++;
        cout << "Длина строки: " << len << "\n";

        // 6. Подсчет символов в последнем слове
        int count = 0;
        int i = len - 1;

        // Считаем символы последнего слова
        while ( i >= 0 && lastLine[i] != ' ' ) {
            count++;
            i--;
        }

        cout << "Ответ: " << count << endl;

        return 0;
    }