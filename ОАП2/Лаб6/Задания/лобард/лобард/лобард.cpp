#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Структурированный тип данных(1)>>>>>>>>>>>>>>>>>>>>>>
const int MAX_ITEMS = 100;
const int MAX_NAME_LEN = 50;
const int MAX_PASSPORT_LEN = 20;
const int MAX_DATE_LEN = 15;

struct PawnItem
{
	char FIO[MAX_NAME_LEN];
	char Passport[MAX_PASSPORT_LEN];
	char Itemname[MAX_NAME_LEN];
	double value;
	double Amount;
	char dateReceived[MAX_DATE_LEN];
	int storageDays;
};

PawnItem database[MAX_ITEMS];

int ItemCount = 0;
const char FILENAME[] = "lombard_data.txt";
// Ввод элементов >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void addItem ( )
{
	if ( ItemCount >= MAX_ITEMS ) {
		cout << "\nБаза данных переполнена!Максимум " << MAX_ITEMS << " записей." << endl;
	}
	PawnItem& item = database[ItemCount];

	cout << "ФИО клиента: ";
	cin.getline ( item.FIO, MAX_NAME_LEN );

	cout << "Паспортные данные: ";
	cin.getline ( item.Passport, MAX_PASSPORT_LEN );

	cout << "Наименование товара: ";
	cin.getline ( item.Itemname, MAX_NAME_LEN );

	cout << "Оценочная стоимость: ";
	cin >> item.value;

	cout << "Сумма, выданная под залог: ";
	cin >> item.Amount;

	cout << "Дата сдачи (ДД.ММ.ГГГГ): ";
	cin >> item.dateReceived;

	cout << "Срок хранения (дней): ";
	cin >> item.storageDays;

	cin.ignore ( );

	ItemCount++;
	cout << "Запись успешно добавлена!" << endl;
}

//Вывод элементов структуры в консоль(3)>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void displayAll ( )
{
	if ( ItemCount == 0 ) {
		cout << "\nБаза данных пуста." << endl;
		return;
	}
	cout << "\n<<<<<<<<<< БАЗА ДАННЫХ ЛОМБАРДА >>>>>>>>>>" << endl;

	cout << setw ( 4 ) << "№"
		<< setw ( 10 ) << "Клиент"
		<< setw ( 10 ) << "Товар"
		<< setw ( 10 ) << "Оценка"
		<< setw ( 10 ) << "Залог"
		<< setw ( 10 ) << "Дата"
		<< setw ( 10 ) << "Срок" << endl;
	cout << string ( 75, '-' ) << endl;

	for ( int i = 0; i < ItemCount; i++ ) {
		cout << setw ( 4 ) << (i + 1)
			<< setw ( 10 ) << database[i].FIO
			<< setw ( 10 ) << database[i].Itemname
			<< setw ( 10 ) << database[i].value
			<< setw ( 10 ) << database[i].Amount
			<< setw ( 10 ) << database[i].dateReceived
			<< setw ( 6 ) << database[i].storageDays << endl;
	}
	cout << "Всего записей: " << ItemCount << endl;
}
//Удаление (4)>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void deleteItem ( )
{
	displayAll ( );
	if ( ItemCount == 0 ) return;
	int index;
	cout << "Введите номер записи для удаления (1-" << ItemCount << "):";
	cin >> index;
	cin.ignore ( );
	if ( index > 0 && index < ItemCount ) {
		cout << "Удалить запись: " << database[index - 1].Itemname << "? (1 - Да, 0 - Нет): ";
		int confirm;
		cin >> confirm;
		cin.ignore ( );
		if ( confirm == 1 ) {
			for ( int i = index - 1; i < ItemCount - 1; i++ ) {
				database[i] = database[i + 1];
			}
			ItemCount--;
			cout << "Запись удалена." << endl;
		}
		else {
			cout << "Удаление отменено." << endl;
		}
	}
	else {
		cout << "Неверный номер записи!" << endl;
	}
}

//Поиск инфы(5)>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void searchItem ( )
{
	if ( ItemCount == 0 ) {
		cout << "\nБаза данных пуста." << endl;
		return;
	}

	char searchName[MAX_NAME_LEN];
	cout << "\nВведите наименование товара для поиска: ";
	cin.getline ( searchName, MAX_NAME_LEN );

	bool found = false;
	cout << "\n--- Результаты поиска ---" << endl;

	for ( int i = 0; i < ItemCount; i++ ) {
		// Поиск подстроки через strstr
		if ( strstr ( database[i].Itemname, searchName ) != NULL ) {
			if ( !found ) {
				cout << left << setw ( 4 ) << "№"
					<< setw ( 20 ) << "Клиент"
					<< setw ( 15 ) << "Товар"
					<< setw ( 10 ) << "Залог"
					<< setw ( 12 ) << "Дата" << endl;
				cout << string ( 63, '-' ) << endl;
			}
			cout << left << setw ( 4 ) << (i + 1)
				<< setw ( 20 ) << database[i].FIO
				<< setw ( 15 ) << database[i].Itemname
				<< setw ( 10 ) << database[i].Amount
				<< setw ( 12 ) << database[i].dateReceived << endl;
			found = true;
		}
	}

	if ( !found ) {
		cout << "Товары с таким названием не найдены." << endl;
	}
}

//6 Запись в файл
void saveToFile ( )
{
	ofstream outFile ( FILENAME );
	if ( !outFile.is_open ( ) ) {
		cout << "Ошибка открытия файла для записи!" << endl;
		return;
	}

	// Записываем количество записей
	outFile << ItemCount << endl;

	for ( int i = 0; i < ItemCount; i++ ) {
		outFile << database[i].FIO << endl;
		outFile << database[i].Passport << endl;
		outFile << database[i].Itemname << endl;
		outFile << database[i].value << endl;
		outFile << database[i].Amount << endl;
		outFile << database[i].dateReceived << endl;
		outFile << database[i].storageDays << endl;
	}

	outFile.close ( );
	cout << "Данные успешно сохранены в файл " << FILENAME << endl;
}

//  7 Чтение из файла
void loadFromFile ( )
{
	ifstream inFile ( FILENAME );
	if ( !inFile.is_open ( ) ) {
		cout << "Файл не найден. Создаем новую базу." << endl;
		return;
	}

	inFile >> ItemCount;
	inFile.ignore ( ); // Пропускаем символ новой строки после числа

	for ( int i = 0; i < ItemCount; i++ ) {
		inFile.getline ( database[i].FIO, MAX_NAME_LEN );
		inFile.getline ( database[i].Passport, MAX_PASSPORT_LEN );
		inFile.getline ( database[i].Itemname, MAX_NAME_LEN );
		inFile >> database[i].value;
		inFile >> database[i].Amount;
		inFile >> database[i].dateReceived;
		inFile >> database[i].storageDays;
		inFile.ignore ( ); // Пропускаем символ новой строки
	}

	inFile.close ( );
	cout << "Загружено записей: " << ItemCount << endl;
}

void showMenu ( )
{
	cout << "\n<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>" << endl;
	cout << "   СИСТЕМА УЧЕТА ЛОМБАРДА     " << endl;
	cout << "<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>" << endl;
	cout << "1. Добавить товар" << endl;
	cout << "2. Показать все товары" << endl;
	cout << "3. Удалить товар" << endl;
	cout << "4. Поиск по названию товара" << endl;
	cout << "5. Сохранить в файл" << endl;
	cout << "6. Загрузить из файла" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберите действие: ";
}

int main ( )
{
	int choice;
	do {
		showMenu ( );
		cin >> choice;
		cin.ignore ( );

		switch ( choice ) {
			case 1: addItem ( ); break;
			case 2: displayAll ( ); break;
			case 3: deleteItem ( ); break;
			case 4: searchItem ( ); break;
			case 5: saveToFile ( ); break;
			case 6: loadFromFile ( ); break;
			case 0:
				cout << "Программа завершена." << endl;
				break;
			default:
				cout << "Неверный выбор! Попробуйте снова." << endl;
		}
	} while ( choice != 0 );

	return 0;
}