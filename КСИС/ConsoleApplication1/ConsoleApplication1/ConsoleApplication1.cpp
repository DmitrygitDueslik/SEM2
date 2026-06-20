#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

// Вариант 7: Полином x^10 + x^9 + x^5 + x^4 + x + 1
// Двоичное представление: 11000110011 (11 бит)
void crc10 ( const char* data, int len, char* remainder )
{
	const char poly[] = "11000110011"; // Полином степени 10 (длина 11 бит)
	const int poly_len = 11;

	//  временная копия данных для  деления
	char* temp = new char[len + 1];
	strcpy_s ( temp, len + 1, data );

	// Алгоритм деления  (XOR)
	for ( int i = 0; i <= len - poly_len; i++ ) {
		if ( temp[i] == '1' ) {
			for ( int j = 0; j < poly_len; j++ ) {
				// Если биты совпадают -> 0, если разные -> 1 (операция XOR)
				temp[i + j] = (temp[i + j] == poly[j]) ? '0' : '1';
			}
		}
	}

	// Копируем остаток ( в результат
	for ( int i = 0; i < 10; i++ ) {
		remainder[i] = temp[len - 10 + i];
	}
	remainder[10] = '\0'; // Завершающий ноль строки

	delete[] temp;
}

// Генерация случайной последовательности 0 и 1
void gen_random ( char* s, int k )
{
	for ( int i = 0; i < k; i++ ) {
		s[i] = (rand ( ) % 2) ? '1' : '0';
	}
	s[k] = '\0';
}

int main ( )
{
	srand ( time ( 0 ) );

	int k;
	cout << "Введите длину последовательности (рекомендуется 1000): ";
	cin >> k;

	char* data = new char[k + 1];

	cout << "Сгенерировать случайную? (1 - да, 0 - ввод вручную): ";
	int choice;
	cin >> choice;

	if ( choice == 1 ) {
		gen_random ( data, k );
		cout << "Случайная последовательность (первые 100 бит):\n";
		for ( int i = 0; i < k && i < 100; i++ ) cout << data[i];
		if ( k > 100 ) cout << "...";
		cout << endl;
	}
	else {
		cout << "Введите последовательность из 0 и 1:\n";
		cin >> data;
		k = strlen ( data );
	}

	//  Добавляем 10 нулей к концу данных из-за степени полинома
	char* extended = new char[k + 10 + 1];
	strcpy_s ( extended, k + 1, data );

	for ( int i = 0; i < 10; i++ )
		extended[k + i] = '0';

	extended[k + 10] = '\0';

	//  Вычисление CRC-10
	char crc[11];
	crc10 ( extended, k + 10, crc );

	cout << "\nВычисленный CRC-10: " << crc << endl;

	//  Данные + CRC
	char* full = new char[k + 10 + 1];
	strcpy_s ( full, k + 1, data );
	strcat_s ( full, k + 10 + 1, crc );

	cout << "\nПолная последовательность с добавленным CRC:\n";

	for ( int i = 0; i < k + 10; i++ ) {
		cout << full[i];
		if ( (i + 1) % 100 == 0 ) cout << endl;
	}
	cout << endl;

	// Проверка правильности
	// Вычисление CRC от полного сообщения. Если ошибок нет, остаток должен быть 0.
	char check[11];
	crc10 ( full, k + 10, check );

	cout << "\nРезультат проверки (остаток от деления полного сообщения): " << check << endl;

	// Сравниваем с строкой из 10 нулей
	if ( strcmp ( check, "0000000000" ) == 0 )
		cout << ">>> Проверка успешна: CRC равен нулю." << endl;
	else
		cout << ">>> Ошибка: CRC не равен нулю!" << endl;

	delete[] data;
	delete[] extended;
	delete[] full;

	return 0;
}