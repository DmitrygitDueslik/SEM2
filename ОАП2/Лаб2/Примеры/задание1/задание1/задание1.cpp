#include <fstream>
#include <iostream>
using namespace std;
void main ( )
{
    setlocale ( LC_ALL, "RUSSIAN" );
    char buff[50];            // буфер для хранения считываемого из файла текста
    ofstream fout ( "t.txt" );   // создание объекта fout класса ofstream для записи 
    fout << "Работа с файлами в С++"; // запись строки в файл
    fout.close ( );
    ifstream fin ( "t.txt" );    // создание объекта fin класса ifstream для чтения  
    if ( !fin.is_open ( ) )
        cout << "Файл не может быть открыт!\n";
    else {
        fin >> buff;           // считывание первого слова из файла
        cout << buff << endl;  // печать слова
        fin.getline ( buff, 50 ); // считывание строки из файла
        fin.close ( );
        cout << buff << endl;   // печать строки
    }
}
