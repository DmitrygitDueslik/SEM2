#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_NAME_LEN = 50;
const int MAX_LOCATION_LEN = 50;
const int MAX_PROFILE_LEN = 30;
const int MAX_RECORDS = 100;

// Структура данных (char массивы вместо string)
struct Sanatorium
{
	char name[MAX_NAME_LEN];
	char location[MAX_LOCATION_LEN];
	char profile[MAX_PROFILE_LEN];
	int ticketsCount;
};

void inputData ( Sanatorium* data, int& count )
{
	int n;
	cout << "Введите количество санаториев (макс. " << MAX_RECORDS << "): ";
	cin >> n;

	if ( n > MAX_RECORDS ) n = MAX_RECORDS;
	if ( n <= 0 ) return;

	count = n;

	for ( int i = 0; i < n; ++i ) {
		cout << "\n--- Запись #" << (i + 1) << " ---" << endl;

		cout << "Название санатория: ";
		cin.ignore ( );
		cin.getline ( data[i].name, MAX_NAME_LEN );

		cout << "Место расположения: ";
		cin.getline ( data[i].location, MAX_LOCATION_LEN );

		cout << "Лечебный профиль: ";
		cin.getline ( data[i].profile, MAX_PROFILE_LEN );

		cout << "Количество путевок: ";
		cin >> data[i].ticketsCount;
	}
}

// Критерий сортировки: группа по профилю, внутри по названию
bool shouldSwap ( const Sanatorium& a, const Sanatorium& b )
{
	int profileCmp = strcmp ( a.profile, b.profile );
	if ( profileCmp != 0 ) {
		return profileCmp > 0;
	}
	return strcmp ( a.name, b.name ) > 0;
}

void sortData ( Sanatorium* data, int count )
{
	for ( int i = 0; i < count - 1; ++i ) {
		for ( int j = 0; j < count - i - 1; ++j ) {
			if ( shouldSwap ( data[j], data[j + 1] ) ) {
				Sanatorium temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

void printTable ( const Sanatorium* data, int count )
{
	cout << "\n" << setw ( 60 ) << setfill ( '=' ) << "=" << endl;
	cout << left
		<< setw ( 25 ) << "Название"
		<< setw ( 20 ) << "Расположение"
		<< setw ( 15 ) << "Профиль"
		<< setw ( 10 ) << "Путевки" << endl;
	cout << setw ( 60 ) << setfill ( '-' ) << "-" << endl;

	for ( int i = 0; i < count; ++i ) {
		cout << left
			<< setw ( 25 ) << data[i].name
			<< setw ( 20 ) << data[i].location
			<< setw ( 15 ) << data[i].profile
			<< setw ( 10 ) << data[i].ticketsCount << endl;
	}
	cout << setw ( 60 ) << setfill ( '=' ) << "=" << endl;
}

void searchByProfile ( const Sanatorium* data, int count )
{
	char searchProfile[MAX_PROFILE_LEN];
	cout << "\nВведите лечебный профиль для поиска: ";
	cin.ignore ( );
	cin.getline ( searchProfile, MAX_PROFILE_LEN );

	bool found = false;
	cout << "\nРезультаты поиска по профилю \"" << searchProfile << "\":" << endl;

	for ( int i = 0; i < count; ++i ) {
		if ( strcmp ( data[i].profile, searchProfile ) == 0 ) {
			if ( !found ) {
				cout << left
					<< setw ( 25 ) << "Название"
					<< setw ( 20 ) << "Расположение"
					<< setw ( 15 ) << "Профиль"
					<< setw ( 10 ) << "Путевки" << endl;
				cout << setw ( 60 ) << setfill ( '-' ) << "-" << endl;
				found = true;
			}
			cout << left
				<< setw ( 25 ) << data[i].name
				<< setw ( 20 ) << data[i].location
				<< setw ( 15 ) << data[i].profile
				<< setw ( 10 ) << data[i].ticketsCount << endl;
		}
	}

	if ( !found ) {
		cout << "Санатории с таким профилем не найдены." << endl;
	}
}

int main ( )
{
	// Динамический массив вместо vector
	Sanatorium* database = new Sanatorium[MAX_RECORDS];
	int count = 0;

	int choice;
	do {
		cout << "\nМЕНЮ:" << endl;
		cout << "1. Ввести данные о санаториях" << endl;
		cout << "2. Отсортировать и вывести таблицу" << endl;
		cout << "3. Поиск по лечебному профилю" << endl;
		cout << "0. Выход" << endl;
		cout << "Выберите действие: ";
		cin >> choice;

		switch ( choice ) {
			case 1:
				inputData ( database, count );
				break;
			case 2:
				if ( count == 0 ) {
					cout << "База данных пуста." << endl;
				}
				else {
					sortData ( database, count );
					printTable ( database, count );
				}
				break;
			case 3:
				if ( count == 0 ) {
					cout << "База данных пуста." << endl;
				}
				else {
					sortData ( database, count );
					searchByProfile ( database, count );
				}
				break;
			case 0:
				cout << "Выход из программы." << endl;
				break;
			default:
				cout << "Неверный выбор." << endl;
		}
	} while ( choice != 0 );

	// Освобождение памяти
	delete[] database;

	return 0;
}