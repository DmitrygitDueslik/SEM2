#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main ( )
{
	long long N;
	cout << "Введите число N: ";
	cin >> N;

	// Проверка корректности ввода
	if ( N < 1 ) {
		cout << "Ошибка: N должно быть >= 1" << endl;
		return 1;
	}

	int maxSteps = (N > 1) ? (int)floor ( log2 ( N ) ) + 1 : 1;

	long long low = 1, high = N;
	vector<long long> guesses;

	while ( low <= high ) {
		long long guess = low + (high - low) / 2;
		guesses.push_back ( guess );

		cout << "Ваше число: " << guess << endl;
		cout << "Введите ответ:" << endl;
		cout << "  1 - мало " << endl;
		cout << "  2 - много " << endl;
		cout << "  3 - угадал" << endl;
		cout << "> ";

		int response;
		cin >> response;

		if ( response == 1 ) {
			low = guess + 1;
			cout << endl;
		}
		else if ( response == 2 ) {
			high = guess - 1;
			cout << endl;
		}
		else if ( response == 3 ) {
			// Число угадано!
			cout << "\nОтлично! Я угадал!" << endl;
			break;
		}
		else {
			cout << "\n Неверный ввод! Используйте цифры 1, 2 или 3.\n" << endl;
			guesses.pop_back ( );
			continue;
		}
	}

	if ( low > high && guesses.size ( ) > 0 &&
		(guesses.back ( ) != low - 1 || guesses.back ( ) != high + 1) ) {
		cout << "\n диапазон поиска ограничен" << endl;
	}

	cout << "Максимальное количество шагов = " << maxSteps << endl;
	cout << "\nВсе шаги бинарного поиска:" << endl;

	cout << N << endl;

	// Выводим все предположения программы
	for ( size_t i = 0; i < guesses.size ( ); i++ ) {
		cout << "\n" << guesses[i];
	}

	cout << "\nВсего сделано шагов: " << guesses.size ( ) << endl;

	long long target = !guesses.empty ( ) ? guesses.back ( ) : 1;
	long long temp = target;

	cout << "\nЦепочка шагов ";

	// Выводим само число в начале цепочки
	cout << N;

	// Делим на 2, пока не получим 0
	while ( N > 1 ) {
		N = N / 2;      // Деление нацело
		cout << " ---" << N; // Выводим стрелку и новое значение
	}

	cout << endl;

	return 0;
}