#include <iostream>
#include <locale>
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    //Log::LOG log;
    //log.isOpen = false;

    //try
    //{
    //    // 1. Обработка параметров
    //    Parm::PARM parm = Parm::getparm(argc, argv);

    //    // 2. Создание журнала
    //    log = Log::getlog(parm.log);
    //    Log::WriteLog(log);
    //    Log::WriteParm(log, parm);

    //    // 3. Ввод исходного кода
    //    In::IN in = In::getin(parm.in);
    //    Log::WriteIn(log, in);

    //    // Вывод на консоль
    //    std::cout << "Всего символов: " << in.size << std::endl;
    //    std::cout << "Всего строк: " << in.lines << std::endl;
    //    std::cout << "Пропущено: " << in.ignor << std::endl;

    //    Log::Close(log);
    //}
    //catch (Error::ERROR e)
    //{
    //    Log::WriteError(log, e);
    //    Log::Close(log);
    //}

    //system("pause");



    //// ТЕСТ 1: Проверка функции geterror
    //std::cout << "--- тест Error::geterror ---" << std::endl << std::endl;
    //try
    //{
    //    throw ERROR_THROW(100);  // Генерируем ошибку с кодом 100
    //}
    //catch (Error::ERROR e)
    //{
    //    std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
    //}

    //// ТЕСТ 2: Проверка функции geterrorin
    //std::cout << "--- тест Error::geterrorin ---" << std::endl << std::endl;
    //try
    //{
    //    throw ERROR_THROW_IN(111, 7, 7);  // Ошибка 111, строка 7, позиция 7
    //}
    //catch (Error::ERROR e)
    //{
    //    std::cout << "Ошибка " << e.id << ": " << e.message
    //        << ", строка " << e.inext.line
    //        << ", позиция " << e.inext.col << std::endl << std::endl;
    //}

    
    
    //std::cout << "--- тест Parm::getparm ---" << std::endl << std::endl;

    //try
    //{
    //    // Получаем параметры из командной строки
    //    Parm::PARM parm = Parm::getparm(argc, argv);

    //    // Выводим полученные параметры
    //    std::wcout << "-in: " << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << std::endl << std::endl;
    //}
    //catch (Error::ERROR e)
    //{
    //    std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
    //}


    //std::cout << "--- тест In::getin ---" << std::endl << std::endl;


    try
    {
        // Получаем параметры командной строки
        Parm::PARM parm = Parm::getparm(argc, argv);

        // Читаем входной файл
        In::IN in = In::getin(parm.in);

        // Выводим содержимое файла
        std::cout << in.text << std::endl;

        // Выводим статистику
        std::cout << "Всего символов: " << in.size << std::endl;
        std::cout << "Всего строк: " << in.lines << std::endl;
        std::cout << "Пропущено: " << in.ignor << std::endl;
    }
    catch (Error::ERROR e)
    {
        std::cout << "Ошибка " << e.id << ": " << e.message << std::endl;
        std::cout << "строка " << e.inext.line  
            << " позиция " << e.inext.col << std::endl << std::endl;
    }


    
    //Тест 2 -----------------
    // в свойствах -in:in.txt
    // в свойствах -in:in.txt -out:o.txt -log:l.txt


    //Тест 3

    //cd C:\Users\Обезьяна\source\repos\Project1\x64\Debug
    //Project1.exe - in:in.txt
    // Без ошибки
    // 
    // 
    // 
    // Для ошибки
    //Hello WorMld!!!
    //ПрХивеХт Мир!Y!

    return 0;
}