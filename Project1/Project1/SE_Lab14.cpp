#include <iostream>
#include <locale>
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"
#include<fstream>


int wmain(int argc, wchar_t* argv[])
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    Log::LOG log;
    log.isOpen = false;

    try
    {
        // 1. ��������� ����������
        Parm::PARM parm = Parm::getparm(argc, argv);

        // 2. �������� �������
        log = Log::getlog(parm.log);
        Log::WriteLog(log);
        Log::WriteParm(log, parm);

        // 3. ���� ��������� ����
        In::IN in = In::getin(parm.in);
        Log::WriteIn(log, in);

        // ����� �� �������
        std::cout << "����� ��������: " << in.size << std::endl;
        std::cout << "����� �����: " << in.lines << std::endl;
        std::cout << "���������: " << in.ignor << std::endl;

        Log::Close(log);
    }
    catch (Error::ERROR e)
    {
        Log::WriteError(log, e);
        Log::Close(log);
    }

    system("pause");



    //// ���� 1: �������� ������� geterror
    //std::cout << "--- ���� Error::geterror ---" << std::endl << std::endl;
    //try
    //{
    //    throw ERROR_THROW(100);  // ���������� ������ � ����� 100
    //}
    //catch (Error::ERROR e)
    //{
    //    std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
    //}

    //// ���� 2: �������� ������� geterrorin
    //std::cout << "--- ���� Error::geterrorin ---" << std::endl << std::endl;
    //try
    //{
    //    throw ERROR_THROW_IN(111, 7, 7);  // ������ 111, ������ 7, ������� 7
    //}
    //catch (Error::ERROR e)
    //{
    //    std::cout << "������ " << e.id << ": " << e.message
    //        << ", ������ " << e.inext.line
    //        << ", ������� " << e.inext.col << std::endl << std::endl;
    //}

    //
    //
    //std::cout << "--- ���� Parm::getparm ---" << std::endl << std::endl;

    //try
    //{
    //    // �������� ��������� �� ��������� ������
    //    Parm::PARM parm = Parm::getparm(argc, argv);

    //    // ������� ���������� ���������
    //    std::wcout << "-in: " << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << std::endl << std::endl;
    //}
    //catch (Error::ERROR e)
    //{
    //    std::cout << "������ " << e.id << ": " << e.message << std::endl << std::endl;
    //}


    //std::cout << "--- ���� In::getin ---" << std::endl << std::endl;


    //try
    //{
    //    // �������� ��������� ��������� ������
    //    Parm::PARM parm = Parm::getparm(argc, argv);

    //    // ������ ������� ����
    //    In::IN in = In::getin(parm.in);

    //    // ������� ���������� �����
    //    std::cout << in.text << std::endl;

    //    // ������� ����������
    //    std::cout << "����� ��������: " << in.size << std::endl;
    //    std::cout << "����� �����: " << in.lines << std::endl;
    //    std::cout << "���������: " << in.ignor << std::endl;
    //}
    //catch (Error::ERROR e)
    //{
    //    std::cout << "������ " << e.id << ": " << e.message << std::endl;
    //    std::cout << "������ " << e.inext.line  
    //        << " ������� " << e.inext.col << std::endl << std::endl;
    //}


    return 0;
}