#include <iostream>
#include <fstream>
using namespace std;

// Объявление функций (правильные прототипы)
double readFromFile ( ifstream& f, char s[] );    // Функция чтения из файла
void writeToFile ( ofstream& f, double a, char s[] ); // Функция записи в файл

int main ( )
{  // main должен возвращать int
    //setlocale ( LC_ALL, "RUSSIAN" );
    double a, b;
    char str[40];  // Увеличим размер буфера

    cout << "Ввести имя файла для чтения: \n";
    cin >> str;

    ifstream infile ( str );  // Открываем файл для чтения
    if ( !infile.is_open ( ) ) {
        cout << "Ошибка открытия файла для чтения\n";
        return 1;
    }

    a = readFromFile ( infile, str );
    cout << "Прочитанное из файла число = " << a << endl;

    b = pow ( a, 2 );
    cout << "b = " << b << endl;

    infile.close ( );  // Закрываем файл чтения

    cout << "Введите имя файла для записи: \n";
    cin >> str;

    ofstream ofile;
    writeToFile ( ofile, b, str );  // Записываем b (квадрат числа)

    return 0;
}

// Функция чтения из файла
double readFromFile ( ifstream& f, char s[] )
{
    double a;

    if ( !f.is_open ( ) ) {  // Проверка открытия файла
        cout << "\nОшибка открытия файла";
        exit ( 1 );
    }

    f >> a;  // Читаем число из файла

    if ( f.fail ( ) ) {  // Проверка успешности чтения
        cout << "\nОшибка открытия файла";
        exit ( 1 );
    }

    return a;
}

// Функция записи в файл
void writeToFile ( ofstream& f, double a, char s[] )
{
    f.open ( s );  // Открываем файл

    if ( !f.is_open ( ) ) {  // Проверка открытия файла
        cout << "\nОшибка открытия файла для записи";
        exit ( 1 );
    }

    f << a;  // Записываем число в файл

    if ( f.fail ( ) ) {  // Проверка успешности записи
        cout << "\nОшибка записи в файл";
        exit ( 1 );
    }

    f.close ( );  // Закрываем файл
    cout << "\nДанные успешно записаны в файл";
}