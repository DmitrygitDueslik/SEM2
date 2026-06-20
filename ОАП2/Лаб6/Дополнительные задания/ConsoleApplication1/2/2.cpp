#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int MAX_TRAINS = 8;
const int MAX_NAME_LEN = 50;
const int MAX_TIME_LEN = 10;
const int MAX_NUM_LEN = 10;

struct TRAIN
{
	char destination[MAX_NAME_LEN];
	char trainNumber[MAX_NUM_LEN];
	char departureTime[MAX_TIME_LEN];
};

TRAIN trains[MAX_TRAINS];
int trainCount = 0;

bool isTimeAfter ( const char* time1, const char* time2 )
{
	return strcmp ( time1, time2 ) > 0;
}

void insertSorted ( const TRAIN& newTrain )
{
	int i = trainCount - 1;

	while ( i >= 0 && strcmp ( newTrain.destination, trains[i].destination ) < 0 ) {
		trains[i + 1] = trains[i];
		i--;
	}

	trains[i + 1] = newTrain;
	trainCount++;
}

void addTrain ( )
{
	if ( trainCount >= MAX_TRAINS ) {
		cout << "\nМаксимум записей достигнут!" << endl;
		return;
	}

	TRAIN newTrain;

	cout << "\n--- Ввод поезда #" << (trainCount + 1) << " ---" << endl;

	cout << "Пункт назначения: ";
	cin.getline ( newTrain.destination, MAX_NAME_LEN );

	cout << "Номер поезда: ";
	cin.getline ( newTrain.trainNumber, MAX_NUM_LEN );

	cout << "Время отправления (ЧЧ:ММ): ";
	cin.getline ( newTrain.departureTime, MAX_TIME_LEN );

	insertSorted ( newTrain );
	cout << "Запись добавлена (список отсортирован)." << endl;
}

void displayAll ( )
{
	if ( trainCount == 0 ) {
		cout << "\nСписок поездов пуст." << endl;
		return;
	}

	cout << "\n========== РАСПИСАНИЕ ПОЕЗДОВ ==========" << endl;
	cout << left << setw ( 4 ) << "№"
		<< setw ( 25 ) << "Пункт назначения"
		<< setw ( 12 ) << "Номер"
		<< "Время" << endl;
	cout << string ( 55, '-' ) << endl;

	for ( int i = 0; i < trainCount; i++ ) {
		cout << left << setw ( 4 ) << (i + 1)
			<< setw ( 25 ) << trains[i].destination
			<< setw ( 12 ) << trains[i].trainNumber
			<< trains[i].departureTime << endl;
	}
}

void searchByTime ( )
{
	if ( trainCount == 0 ) {
		cout << "\nСписок поездов пуст." << endl;
		return;
	}

	char searchTime[MAX_TIME_LEN];
	cout << "\nВведите время для поиска (ЧЧ:ММ): ";
	cin.getline ( searchTime, MAX_TIME_LEN );

	bool found = false;
	cout << "\n--- Поезда, отправляющиеся после " << searchTime << " ---" << endl;

	for ( int i = 0; i < trainCount; i++ ) {
		if ( isTimeAfter ( trains[i].departureTime, searchTime ) ) {
			if ( !found ) {
				cout << left << setw ( 4 ) << "№"
					<< setw ( 25 ) << "Пункт назначения"
					<< setw ( 12 ) << "Номер"
					<< "Время" << endl;
				cout << string ( 55, '-' ) << endl;
			}
			cout << left << setw ( 4 ) << (i + 1)
				<< setw ( 25 ) << trains[i].destination
				<< setw ( 12 ) << trains[i].trainNumber
				<< trains[i].departureTime << endl;
			found = true;
		}
	}

	if ( !found ) {
		cout << "Поездов, отправляющихся после " << searchTime << ", не найдено." << endl;
	}
}

// --- Меню ---
void showMenu ( )
{
	cout << "\n--------------------------" << endl;
	cout << "  РАСПИСАНИЕ ПОЕЗДОВ      " << endl;
	cout << "--------------------------" << endl;
	cout << "1. Добавить поезд" << endl;
	cout << "2. Показать все поезда" << endl;
	cout << "3. Найти поезда после времени" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберите действие: ";
}

// --- Главная функция ---
int main ( )
{
	int choice;
	do {
		showMenu ( );
		cin >> choice;
		cin.ignore ( );

		switch ( choice ) {
			case 1: addTrain ( ); break;
			case 2: displayAll ( ); break;
			case 3: searchByTime ( ); break;
			case 0:
				cout << "Программа завершена." << endl;
				break;
			default:
				cout << "Неверный выбор!" << endl;
		}
	} while ( choice != 0 );

	return 0;
}