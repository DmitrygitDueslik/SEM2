#include <iostream>
#include <locale>
#include <tchar.h>
#include <string>
using namespace std;
typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date
{
	day dd;
	month mm;
	year yyyy;
};

// Перегружаемые операторы <, >, ==
bool operator<( const Date& d1, const Date& d2 )
{
	if ( d1.yyyy != d2.yyyy )
		return d1.yyyy < d2.yyyy;
	if ( d1.mm != d2.mm )
		return d1.mm < d2.mm;
	return d1.dd < d2.dd;
}

bool operator>( const Date& d1, const Date& d2 )
{
	return d2 < d1;
}

bool operator==( const Date& d1, const Date& d2 )
{
	return (d1.dd == d2.dd) && (d1.mm == d2.mm) && (d1.yyyy == d2.yyyy);
}

// 2.  псевдонимы типов данных для полей структуры
typedef string computer_type;        // тип_компьютера
typedef string processor_type;       // процессор
typedef string video_card_type;      // видеокарта
typedef int ram_size;                     // размер_ОЗУ (в ГБ)
typedef int hard_disk_size;               // размер_жесткого диска (в ГБ)
typedef bool has_camera;                  // наличие камеры
typedef Date purchase_date;               // дата_приобретения

// 1.  структура Компьютер
struct Computer
{
	computer_type type;           // тип компьютера (	ноутбук, ...)
	processor_type processor;     // процессор
	video_card_type videoCard;    // видеокарта
	ram_size ram;                 // размер ОЗУ
	hard_disk_size hardDisk;      // размер жесткого диска
	has_camera camera;            // наличие камеры
	purchase_date date;           // дата приобретения
};
// Операция 1 operator==
// Компьютеры относятся к одному классу, если у них есть камера и одинаковый объем ОЗУ
bool operator==( const Computer& c1, const Computer& c2 )
{
	return (c1.camera == c2.camera) && (c1.ram == c2.ram);
}

// Операция 2 operator>
// Первый компьютер мощнее второго, если у него больше ОЗУ
bool operator>( const Computer& c1, const Computer& c2 )
{
	return c1.ram > c2.ram;
}

//  функция для вывода даты
void printDate ( const Date& d )
{
	cout << (int)d.dd << "." << (int)d.mm << "." << d.yyyy;
	// Здесь я сделал явное преобразование char в int , ну как бы логично дата в int и не в char выводить
	// Дата ведь цифры и логично использовать int, а char это символы(тоже можно использовать , но как-то логичнее
	// использовать int)
}

//  функция для вывода информации о компьютере
void printComputer ( const Computer& c )
{
	cout << "Тип: " << c.type
		<< ", Процессор: " << c.processor
		<< ", Видеокарта: " << c.videoCard
		<< ", ОЗУ: " << c.ram << " ГБ"
		<< ", HDD: " << c.hardDisk << " ГБ"
		<< ", Камера: " << (c.camera ? "есть" : "нет")
		<< ", Дата покупки: ";
	printDate ( c.date );
	cout << endl;
}
int _tmain ( int argc, _TCHAR* argv[] )
{
	// Задание 1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	Date date1 = { 7, 1, 1980 };
	Date date2 = { 7, 2, 1993 };
	Date date3 = { 7, 1, 1980 };

	if ( date1 < date2 ) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if ( date1 > date2 ) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if ( date1 == date2 ) cout << "истина" << endl;
	else cout << "ложь" << endl;

	if ( date1 == date3 ) cout << "истина" << endl;
	else cout << "ложь" << endl;

	// Задание 2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	cout << "ЗАДАНИЕ 2 (Вариант 5: Компьютер) " << endl << endl;

	//  три компьютера для демонстрации
	Computer c1 = {
		"Ноутбук",
		"Intel Core i5",
		"NVIDIA GTX 1650",
		16,     // ОЗУ 16 ГБ
		512,    // HDD 512 ГБ
		true,   // камера есть
		{10, 5, 2023}  // дата покупки: 10.05.2023
	};

	Computer c2 = {
		"Ноутбук",
		"Intel Core i7",
		"NVIDIA RTX 3060",
		16,     // ОЗУ 16 ГБ
		1024,   // HDD 1024 ГБ
		true,   // камера есть
		{15, 6, 2023}  // дата покупки: 15.06.2023
	};

	Computer c3 = {
		"Сервер",
		"AMD EPYC",
		"Integrated",
		64,     // ОЗУ 64 ГБ
		2048,   // HDD 2048 ГБ
		false,  // камеры нет
		{20, 1, 2022}  // дата покупки: 20.01.2022
	};

	// Вывод информации о компьютерах
	cout << "Компьютер 1: ";
	printComputer ( c1 );

	cout << "Компьютер 2: ";
	printComputer ( c2 );

	cout << "Компьютер 3: ";
	printComputer ( c3 );

	cout << endl;

	//  операция 1: operator==
	cout << " Проверка оператора == (Есть ли камера и ОЗУ одинакова) " << endl;
	cout << "c1 и c2 (оба с камерой и  с 16 ГБ ОЗУ): ";
	if ( c1 == c2 )
		cout << "истина - относятся к одному классу" << endl;
	else
		cout << "ложь - разные классы" << endl;

	cout << "c1 и c3 (ноутбук и сервер(проверка камеры и ОЗУ)): ";
	if ( c1 == c3 )
		cout << "истина - относятся к одному классу" << endl;
	else
		cout << "ложь - разные классы" << endl;

	cout << endl;

	//  операция 2: operator>
	cout << " Проверка оператора > (мощность по ОЗУ) " << endl;
	cout << "c3 > c1 (64 ГБ > 16 ГБ): ";
	if ( c3 > c1 )
		cout << "истина - c3 мощнее" << endl;
	else
		cout << "ложь - c3 не мощнее" << endl;

	cout << "c1 > c3 (16 ГБ > 64 ГБ): ";
	if ( c1 > c3 )
		cout << "истина - c1 мощнее" << endl;
	else
		cout << "ложь - c1 не мощнее" << endl;

	cout << "c2 > c1 (16 ГБ > 16 ГБ): ";
	if ( c2 > c1 )
		cout << "истина - c2 мощнее" << endl;
	else
		cout << "ложь - c2 не мощнее" << endl;

	return 0;
}