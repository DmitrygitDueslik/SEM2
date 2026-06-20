#include "stdafx.h"
#include "DateCalculator.h"

int main ( )
{
	int date, month, year, days;
	int inputdate;
	cout << "Введите дату ДДММГГГГ" << "\n";
	cin >> inputdate;
	cout << "<<<<<<<<<<<<<<<<<<<<<\n";
	cout << "\n";

	year = inputdate % 10000;
	int temp = inputdate / 10000;
	month = temp % 100;
	date = temp / 100;
	bool LeapYear = IsLeapYear ( year );
	bool NextYear = IsLeapYear ( year + 1 );
	// корректность ввода
	if ( date < 1 || date > 31 || month < 1 || month > 12 || (!Truedays ( date, month, year, LeapYear )) ) {
		cout << "Ошибка: Неверная дата!" << endl;
		system ( "pause" );
		return 0;
	}
	cout << endl;
	//Функции вывода названия месяца lab 3
	char MonthForOut[10];
	Month ( month, MonthForOut );
	cout << "Вывод порядкового номера месяца введенной даты с названием этого месяца\n";
	cout << "Порядковый номер месяца: " << month << "; Название месяца: " << MonthForOut << endl;
	cout << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

	//функция дата по номеру дня в году lab 3
	cout << "\nВведите порядковый номер дня в году: \n";
	int dayNumberInput;
	int calcDay = 0;
	int calcMonth = 0;
	char calcMonthName[10];
	cin >> dayNumberInput;
	GetDateFromDayOfYear ( dayNumberInput, year, LeapYear, calcDay, calcMonth );
	if ( calcDay == -1 || calcMonth == -1 ) {
		cout << "Ошибка: Номер дня " << dayNumberInput;
		cout << " не существует в году " << year << "!" << endl;
	}
	else {
		// название месяца
		Month ( calcMonth, calcMonthName );

		cout << "Результат вычисления:" << endl;
		cout << "Дата: " << calcDay << " " << calcMonthName << " " << year << endl;
	}
	cout << "\n<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "\n";
	// Определение високосного года

	cout << "Является ли введенный год " << year << " високосным \n";
	if ( LeapYear ) {
		cout << year << " Год является високосным\n";
		cout << 366 << " Дней \n";
		days = 366;
	}
	else {
		cout << year << " Не является високосным \n";
		cout << 365 << " Дней " << endl;
		days = 365;
	}

	cout << "\n";
	cout << "<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "\n";
	cout << "Порядковый номер введенного дня в году ГГГГ\n ";
	int dayOfYear = GetDayOfYear ( date, month, year, LeapYear );
	cout << dayOfYear << endl;

	cout << "\n";
	cout << "<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "\n";

	//  Дни до дня рождения
	cout << "Введите дату рождения (только ДД и ММ)\n";
	int inputBirth;
	cin >> inputBirth;

	int monthofbirth = inputBirth % 100;
	int dateofbirth = inputBirth / 100;

	// корректность дня рождения
	if ( dateofbirth < 1 || dateofbirth > 31 || monthofbirth < 1 || monthofbirth > 12 ) {
		cout << "Ошибка: Неверная дата рождения!" << endl;
		system ( "pause" );
		return 0;
	}

	// Вычисляем порядковый номер дня рождения в текущем году
	int birthdayDayOfYear = GetDayOfYear ( dateofbirth, monthofbirth, year, NextYear );
	cout << "Порядковый номер дня рождения в году \n ";
	cout << birthdayDayOfYear << endl;
	cout << "\n";

	// Вычисляем сколько дней осталось до дня рождения
	int daysUntilBirthday = DaysUntilBirthday ( date, month, year, dateofbirth, monthofbirth, LeapYear, NextYear );
	cout << "<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "До ближайшего дня рождения осталось: " << daysUntilBirthday << " дней" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<" << endl;

	system ( "pause" );
	return 0;
}