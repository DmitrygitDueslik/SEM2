#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main ( )
{
	int n;
	cout << "Введите количество рыб: ";
	cin >> n;

	deque<int> fish;

	cout << "Введите размеры рыб (+ вправо, - влево): ";
	for ( int i = 0; i < n; i++ ) {
		int size;
		cin >> size;
		fish.push_back ( size );
	}

	//  для хранения выживших рыб, плывущих вправо
	deque<int> rightSwimmers;

	// Дек для выживших рыб
	deque<int> survivors;

	cout << "\n Обработка столкновений " << endl;

	while ( !fish.empty ( ) ) {
		int current = fish.front ( );
		fish.pop_front ( );

		cout << "Обрабатываем рыбу: " << current << endl;

		if ( current > 0 ) {
			// Рыба плывёт вправо
			rightSwimmers.push_back ( current );
			cout << "  Плывёт вправо, добавлена в активные" << endl;
		}
		else {
			// Рыба плывёт влево — будет сражаться с рыбами, плывущими вправо
			bool currentAlive = true;

			// Сражаемся с рыбами, плывущими вправо (с конца дека)
			while ( !rightSwimmers.empty ( ) && currentAlive ) {
				int opponent = rightSwimmers.back ( );  // Последняя рыба, плывущая вправо

				cout << "  Столкновение: " << current << " vs " << opponent << endl;

				if ( abs ( opponent ) > abs ( current ) ) {
					// Противник больше — текущая рыба съедена
					currentAlive = false;
					cout << "   Рыба " << current << " съедена рыбой " << opponent << endl;
				}
				else {
					// Текущая рыба больше или равна — противник съеден
					rightSwimmers.pop_back ( );
					cout << "   Рыба " << opponent << " съедена рыбой " << current << endl;
				}
			}

			// Если текущая рыба выжила, она плывёт дальше влево
			if ( currentAlive ) {
				survivors.push_front ( current );
				cout << "   Рыба " << current << " выжила и плывёт влево" << endl;
			}
		}
	}

	// Добавляем всех выживших рыб, плывущих вправо
	while ( !rightSwimmers.empty ( ) ) {
		survivors.push_back ( rightSwimmers.front ( ) );
		rightSwimmers.pop_front ( );
	}

	cout << "\n=== РЕЗУЛЬТАТ ===" << endl;
	cout << "Выжившие рыбы: ";
	if ( survivors.empty ( ) ) {
		cout << "Нет выживших";
	}
	else {
		for ( int i = 0; i < survivors.size ( ); i++ ) {
			cout << survivors.at ( i ) << " ";
		}
	}
	cout << "\nКоличество выживших: " << survivors.size ( ) << endl;

	return 0;
}