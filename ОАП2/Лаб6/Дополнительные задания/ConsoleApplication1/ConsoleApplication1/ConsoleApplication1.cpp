#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_EXAMS = 10;
const int MAX_NAME_LEN = 50;

struct Student
{
	char FIO[MAX_NAME_LEN];
	int examCount;
	int grades[MAX_EXAMS];
};

Student students[MAX_STUDENTS];
int studentCount = 0;

bool isExcellent ( const Student& s )
{
	for ( int i = 0; i < s.examCount; i++ ) {
		if ( s.grades[i] != 4 && s.grades[i] != 5 ) {
			return false;
		}
	}
	return true;
}

double calculateSuccessRate ( const Student* arr, int count )
{
	if ( count == 0 ) return 0.0;

	int excellentCount = 0;

	for ( int i = 0; i < count; i++ ) {
		if ( isExcellent ( arr[i] ) ) {
			excellentCount++;
		}
	}

	return (static_cast<double> ( excellentCount ) / count) * 100.0;
}

void addStudent ( )
{
	if ( studentCount >= MAX_STUDENTS ) {
		cout << "\nМаксимум студентов достигнут!" << endl;
		return;
	}

	Student& s = students[studentCount];

	cout << "\n--- Добавление студента #" << (studentCount + 1) << " ---" << endl;

	cout << "ФИО: ";
	cin.getline ( s.FIO, MAX_NAME_LEN );

	cout << "Количество экзаменов (1-" << MAX_EXAMS << "): ";
	cin >> s.examCount;

	if ( s.examCount < 1 || s.examCount > MAX_EXAMS ) {
		cout << "Неверное количество экзаменов!" << endl;
		return;
	}

	cout << "Введите оценки (4 или 5 - отлично, 3 - хорошо, 2 - неуд):" << endl;
	for ( int i = 0; i < s.examCount; i++ ) {
		cout << "  Оценка " << (i + 1) << ": ";
		cin >> s.grades[i];

		if ( s.grades[i] < 2 || s.grades[i] > 5 ) {
			cout << "  ⚠ Оценка должна быть от 2 до 5!" << endl;
			i--;
		}
	}

	cin.ignore ( );
	studentCount++;
	cout << "Студент добавлен!" << endl;
}

void displayAll ( )
{
	if ( studentCount == 0 ) {
		cout << "\nСписок студентов пуст." << endl;
		return;
	}

	cout << "\n========== СПИСОК СТУДЕНТОВ ==========" << endl;
	cout << left << setw ( 4 ) << "№"
		<< setw ( 25 ) << "ФИО"
		<< setw ( 8 ) << "Экз."
		<< "Оценки" << endl;
	cout << string ( 50, '-' ) << endl;

	for ( int i = 0; i < studentCount; i++ ) {
		cout << left << setw ( 4 ) << (i + 1)
			<< setw ( 25 ) << students[i].FIO
			<< setw ( 8 ) << students[i].examCount;

		for ( int j = 0; j < students[i].examCount; j++ ) {
			cout << students[i].grades[j] << " ";
		}

		if ( isExcellent ( students[i] ) ) {
			cout << " [✓ отлично]";
		}
		cout << endl;
	}
}

void showStatistics ( )
{
	if ( studentCount == 0 ) {
		cout << "\nНет данных для анализа." << endl;
		return;
	}

	double rate = calculateSuccessRate ( students, studentCount );

	cout << "\n========== СТАТИСТИКА УСПЕВАЕМОСТИ ==========" << endl;
	cout << "Всего студентов: " << studentCount << endl;

	int excellentCount = 0;
	for ( int i = 0; i < studentCount; i++ ) {
		if ( isExcellent ( students[i] ) ) excellentCount++;
	}

	cout << "Сдали все экзамены на 4 и 5: " << excellentCount << " чел." << endl;
	cout << fixed << setprecision ( 2 );
	cout << "Успеваемость: " << rate << "%" << endl;
	cout << "=============================================" << endl;
}

void showMenu ( )
{
	cout << "\n--------------------------" << endl;
	cout << "  УЧЁТ УСПЕВАЕМОСТИ       " << endl;
	cout << "--------------------------" << endl;
	cout << "1. Добавить студента" << endl;
	cout << "2. Показать всех студентов" << endl;
	cout << "3. Показать статистику" << endl;
	cout << "4. Проверить конкретного студента" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберите действие: ";
}

void checkSingleStudent ( )
{
	displayAll ( );
	if ( studentCount == 0 ) return;

	int num;
	cout << "\nВведите номер студента для проверки: ";
	cin >> num;
	cin.ignore ( );

	if ( num > 0 && num <= studentCount ) {
		Student& s = students[num - 1];
		cout << "\nСтудент: " << s.FIO << endl;
		cout << "Оценки: ";
		for ( int i = 0; i < s.examCount; i++ ) {
			cout << s.grades[i] << " ";
		}
		cout << endl;

		if ( isExcellent ( s ) ) {
			cout << "✓ Все экзамены сданы на 4 и 5!" << endl;
		}
		else {
			cout << "✗ Есть оценки ниже 4." << endl;
		}
	}
	else {
		cout << "Неверный номер!" << endl;
	}
}

int main ( )
{
	int choice;
	do {
		showMenu ( );
		cin >> choice;
		cin.ignore ( );

		switch ( choice ) {
			case 1: addStudent ( ); break;
			case 2: displayAll ( ); break;
			case 3: showStatistics ( ); break;
			case 4: checkSingleStudent ( ); break;
			case 0:
				cout << "Программа завершена." << endl;
				break;
			default:
				cout << "Неверный выбор!" << endl;
		}
	} while ( choice != 0 );

	return 0;
}