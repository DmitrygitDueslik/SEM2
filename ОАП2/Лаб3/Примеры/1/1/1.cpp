#include <iostream>

void callCounter ( )
{
    static int count = 0; // Статическая переменная сохраняет значение между вызовами
    count++;
    std::cout << "Function called " << count << " time(s)" << std::endl;
}

int main ( )
{
    callCounter ( );
    callCounter ( );
    callCounter ( );
    return 0;
}
