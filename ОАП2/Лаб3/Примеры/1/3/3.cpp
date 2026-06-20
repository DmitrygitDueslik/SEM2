#include <iostream>

int x = 10; // Глобальная переменная

void test ( )
{
    int x = 20; // Локальная переменная (перекрывает глобальную)
    std::cout << "Local x in test(): " << x << std::endl;
}

int main ( )
{
    std::cout << "Global x before: " << x << std::endl;
    test ( );
    std::cout << "Global x after: " << x << std::endl;
    return 0;
}
