#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <locale>
using namespace std;
const int TABLE_SIZE = 20;

struct Cell
{
	string fio;
	bool isEmpty;

	Cell ( ) : isEmpty ( true ) {}
};

Cell hashTable[TABLE_SIZE];

// --- Хэш-функция ---
int getHash ( const string& str )
{
	unsigned long sum = 0;
	for ( char c : str ) {
		sum += static_cast<unsigned char>(c);
	}
	return sum % TABLE_SIZE;
}

// --- Функция добавления ---
void add ( const string& fio )
{
	int index = getHash ( fio );

	if ( hashTable[index].isEmpty ) {
		hashTable[index].fio = fio;
		hashTable[index].isEmpty = false;
		cout << " Успех: '" << fio << "' записано в ячейку [" << index << "]" << endl;
	}
	else {
		cout << " Коллизия! Ячейка [" << index << "] занята ('"
			<< hashTable[index].fio << "'). Нельзя добавить '" << fio << "'" << endl;
	}
}

// --- Функция вывода всей таблицы ---
void printTable ( )
{
	cout << "\n --- ХЭШ-ТАБЛИЦА (Размер: " << TABLE_SIZE << ") ---" << endl;
	cout << "--------------------------------------------------" << endl;

	for ( int i = 0; i < TABLE_SIZE; ++i ) {
		if ( !hashTable[i].isEmpty ) {
			cout << " Индекс [" << i << "]: " << hashTable[i].fio << endl;
		}
		else {
			cout << " Индекс [" << i << "]: (пусто)" << endl;
		}
	}

	cout << "--------------------------------------------------" << endl;
}

// --- Главное меню ---
void showMenu ( )
{
	int choice;
	string inputFIO;

	while ( true ) {
		cout << "\n МЕНЮ:" << endl;
		cout << "1. Вывести всю таблицу" << endl;
		cout << "2. Добавить новое ФИО" << endl;
		cout << "0. Выход" << endl;

		if ( !(cin >> choice) ) {
			cin.clear ( );
			cin.ignore ( 10000, '\n' );
			cout << " Ошибка ввода. Попробуйте число." << endl;
			continue;
		}

		switch ( choice ) {
			case 1:
				printTable ( );
				break;

			case 2:
				cout << "Введите ФИО для добавления: ";

				cin.ignore ( 10000, '\n' );

				getline ( cin, inputFIO );

				if ( !inputFIO.empty ( ) ) {
					add ( inputFIO );
				}
				else {
					cout << " Пустая строка не добавлена." << endl;
				}
				break;

			case 0:
				cout << "Выход из программы..." << endl;
				return;

			default:
				cout << " Неверный выбор. Попробуйте снова." << endl;
		}
	}
}

int main ( )
{
	add ( "Ziraynov Dmitriy Nikolaevich" );
	add ( "Beloded Nikolay Ivanovich" );

	showMenu ( );

	return 0;
}