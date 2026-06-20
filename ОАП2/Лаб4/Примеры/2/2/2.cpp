#include <iostream> // Подключаем библиотеку для ввода-вывода
#include <Windows.h>
using namespace std;

typedef int Meter; // Определяем тип Meter как синоним для int
typedef int Kilometer; // Определяем тип Kilometer как синоним для int
int main ( )
{
    SetConsoleOutputCP ( 1251 );
    SetConsoleCP ( 1251 );
    
    Meter distanceInMeters = 100; // Объявляем переменную distanceInMeters типа Meter
    Kilometer distanceInKilometers = 1; // Объявляем переменную distanceInKilometers типа Kilometer

    cout << "Расстояние: " << distanceInMeters << " метров" << endl; // Выводим расстояние в метрах
    cout << "Расстояние: " << distanceInKilometers << " километров" << endl; // Выводим расстояние в километрах

    return 0; // Возвращаем 0, чтобы указать на успешное завершение программы
}
