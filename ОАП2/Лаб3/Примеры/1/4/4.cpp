#include <iostream>
#include <thread>

thread_local int counter = 0; // У каждого потока — своя копия

void increment ( )
{
    counter++;
    std::cout << "Thread " << std::this_thread::get_id ( )
        << ": counter = " << counter << std::endl;
    counter++;
}

int main ( )
{
    std::thread t1 ( increment );
    std::thread t2 ( increment );
    t1.join ( );
    t2.join ( );
    return 0;
}
