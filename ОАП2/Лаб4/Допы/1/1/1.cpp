#include <iostream>

using namespace std;

#define MAX(a,b)( (a)>(b)? (a):(b))

int main ( )
{
    int n;
    cout << "Введите n элементов массива: ";
    cin >> n;

    

    int* masive = new int[n];
    cout << "Введите элементы массива: ";
    for ( int i = 0; i < n; i++ ) {
        cin >> masive[i];
    }

    long long max_product =0;

    // Перебираем элементы исключаем
    for ( int i = 0; i < n; i++ ) {
        long long product = 1;

        
        for ( int j = 0; j < n; j++ ) {
            if ( j == i ) continue;
            product *= masive[j];
        }
        max_product = MAX ( max_product, product );
    }
    cout << "\nМаксимальное произведение подмассива размера n-1: "
        << max_product << endl;

    delete[] masive;
    return 0;
}