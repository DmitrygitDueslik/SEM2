#include <iostream>
#include <cstdlib>
#include <ctime>

int main ( )
{
    int N;
    std::cout << "Enter array size: ";
    std::cin >> N;

    // 1. Выделяем динамическую память под массив
    int* arr = new int[N];

    // 2. Заполняем массив случайными числами
    srand ( time ( 0 ) );
    std::cout << "Generated array: [";
    for ( int i = 0; i < N; ++i ) {
        arr[i] = rand ( ) % 100 + 1;
        std::cout << arr[i];
        if ( i != N - 1 ) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    // 3. Находим min и max
    int min = arr[0], max = arr[0];
    for ( int i = 1; i < N; ++i ) {
        if ( arr[i] < min ) min = arr[i];
        if ( arr[i] > max ) max = arr[i];
    }
    std::cout << "Min: " << min << ", Max: " << max << std::endl;

    // 4. Освобождаем память
    delete[] arr;

    return 0;
}
