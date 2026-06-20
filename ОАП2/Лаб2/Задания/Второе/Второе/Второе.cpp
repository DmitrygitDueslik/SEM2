#include <iostream>
#include <fstream>
using namespace std;

// Функция записи строки в файл
void zapisat_v_file ( char* text )
{
    ofstream file ( "file.txt" );

    int i = 0;
    while ( text[i] != '\0' ) {
        file << text[i];
        i++;
    }

    file.close ( );
}

// Функция поиска целого числа (без точки после)
void naiti_celoe_chislo ( )
{
    ifstream file ( "file.txt" );

    char s[1000];
    char c;
    int i = 0;

    while ( file.get ( c ) ) {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    file.close ( );

    cout << "Из файла: " << s << endl;

    bool naydeno = false;

    // Идем по строке
    for ( int j = 0; s[j] != '\0'; j++ ) {
        // Если нашли цифру
        if ( s[j] >= '0' && s[j] <= '9' ) {
            // Запоминаем начало числа
            int start = j;

            // Проверяем знак перед числом
            if ( j > 0 && (s[j - 1] == '+' || s[j - 1] == '-') ) {
                start = j - 1;
            }

            // Идем по всем цифрам
            while ( s[j] >= '0' && s[j] <= '9' ) {
                j++;
            }

            // после цифр не должно быть точки
            // Если точка это вещественное число пропускаем
            if ( s[j] == '.' ) {
                continue; // Пропускаем  ищем дальше
            }

            // Если нет точки это целое число
            cout << "Целое число: ";
            for ( int k = start; k < j; k++ ) {
                cout << s[k];
            }
            cout << endl;

            naydeno = true;
            break;
        }
    }

    if ( !naydeno ) {
        cout << "Целых чисел не найдено!" << endl;
    }
}

int main ( )
{
    char vvod[1000];

    // Ввод
    cout << "Введите строку (например: abc123.456+789): ";

    int i = 0;
    char symbol;

    while ( true ) {    
        symbol = cin.get ( );

        if ( symbol == '\n' ) {
            vvod[i] = '\0';
            break;
        }

        vvod[i] = symbol;
        i++;
    }

    // Вывод
    cout << "Вы ввели: " << vvod << endl;

    // Запись в файл
    zapisat_v_file ( vvod );

    // Поиск целого числа
    naiti_celoe_chislo ( );

    return 0;
}