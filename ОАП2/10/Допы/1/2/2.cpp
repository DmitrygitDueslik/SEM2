#include <iostream>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Глобальный дек для колоды карт
deque<int> deck;

// Деки для рук игроков
deque<int> playerHand;
deque<int> dealerHand;

// =====================================================
// Функция 1: Создать и перемешать колоду
// =====================================================
void createDeck ( )
{
	deck.clear ( );  // Очищаем старую колоду

	// Добавляем карты: 2-10 = их значение, J/Q/K = 10, A = 11
	int cards[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };

	// 4 масти, поэтому каждая карта 4 раза
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 13; j++ ) {
			deck.push_back ( cards[j] );  // Добавляем в конец дека
		}
	}

	cout << "🃏 Колода создана. Карт в колоде: " << deck.size ( ) << endl;
}

// =====================================================
// Функция 2: Перемешать колоду
// =====================================================
void shuffleDeck ( )
{
	// Простое перемешивание: меняем местами случайные карты
	for ( int i = 0; i < 100; i++ ) {
		int idx1 = rand ( ) % deck.size ( );
		int idx2 = rand ( ) % deck.size ( );

		// Меняем карты местами через at()
		int temp = deck.at ( idx1 );
		deck.at ( idx1 ) = deck.at ( idx2 );
		deck.at ( idx2 ) = temp;
	}
	cout << "🔀 Колода перемешана!" << endl;
}

// =====================================================
// Функция 3: Взять карту из колоды
// =====================================================
int drawCard ( )
{
	if ( deck.empty ( ) ) {
		cout << "⚠️ Колода пуста!" << endl;
		return 0;
	}

	// Берём карту с ВЕРХУШКИ дека (с конца)
	int card = deck.back ( );
	deck.pop_back ( );  // Удаляем из дека

	return card;
}

// =====================================================
// Функция 4: Посчитать сумму очков в руке
// =====================================================
int calculateScore ( deque<int>& hand )
{
	int sum = 0;
	int aceCount = 0;

	// Считаем сумму через перебор дека
	for ( int i = 0; i < hand.size ( ); i++ ) {
		sum += hand.at ( i );
		if ( hand.at ( i ) == 11 ) aceCount++;  // Считаем тузы
	}

	// Если перебор > 21, тузы считаются как 1 вместо 11
	while ( sum > 21 && aceCount > 0 ) {
		sum -= 10;
		aceCount--;
	}

	return sum;
}

// =====================================================
// Функция 5: Показать руку игрока
// =====================================================
void showHand ( deque<int>& hand, string name )
{
	cout << name << " (" << calculateScore ( hand ) << " очков): ";

	for ( int i = 0; i < hand.size ( ); i++ ) {
		cout << hand.at ( i ) << " ";
	}
	cout << endl;
}

// =====================================================
// Функция 6: Ход игрока
// =====================================================
bool playerTurn ( )
{
	cout << "\n=== 🎮 ВАШ ХОД ===" << endl;

	while ( true ) {
		showHand ( playerHand, "Ваша рука" );

		int score = calculateScore ( playerHand );

		// Проверка на перебор
		if ( score > 21 ) {
			cout << "❌ Перебор! Вы проиграли." << endl;
			return false;
		}

		// Проверка на 21
		if ( score == 21 ) {
			cout << "🎉 21 очко!" << endl;
			return true;
		}

		cout << "\n1. Взять карту (hit)" << endl;
		cout << "2. Хватит (stand)" << endl;
		cout << "Выбор: ";

		int choice;
		cin >> choice;

		if ( choice == 1 ) {
			int card = drawCard ( );
			playerHand.push_back ( card );  // Добавляем карту в руку
			cout << " Вы взяли карту: " << card << endl;
		}
		else if ( choice == 2 ) {
			cout << "✋ Вы остановились." << endl;
			return true;
		}
		else {
			cout << "❌ Неверный выбор!" << endl;
		}
	}
}

// =====================================================
// Функция 7: Ход дилера
// =====================================================
void dealerTurn ( )
{
	cout << "\n=== 🤖 ХОД ДИЛЕРА ===" << endl;

	// Дилер берёт карты, пока у него меньше 17
	while ( calculateScore ( dealerHand ) < 17 ) {
		int card = drawCard ( );
		dealerHand.push_back ( card );
		cout << "🤖 Дилер взял карту: " << card << endl;
		showHand ( dealerHand, "Рука дилера" );
	}

	int score = calculateScore ( dealerHand );
	if ( score > 21 ) {
		cout << "❌ Дилер перебрал!" << endl;
	}
}

// =====================================================
// Функция 8: Определить победителя
// =====================================================
void determineWinner ( )
{
	int playerScore = calculateScore ( playerHand );
	int dealerScore = calculateScore ( dealerHand );

	cout << "\n=== 🏆 РЕЗУЛЬТАТЫ ===" << endl;
	showHand ( playerHand, "Вы" );
	showHand ( dealerHand, "Дилер" );

	if ( playerScore > 21 ) {
		cout << "💀 Вы проиграли (перебор)!" << endl;
	}
	else if ( dealerScore > 21 ) {
		cout << "🎉 Вы выиграли (дилер перебрал)!" << endl;
	}
	else if ( playerScore > dealerScore ) {
		cout << "🎉 Вы выиграли!" << endl;
	}
	else if ( playerScore < dealerScore ) {
		cout << "💀 Вы проиграли!" << endl;
	}
	else {
		cout << "🤝 Ничья!" << endl;
	}
}

// =====================================================
// Функция 9: Очистить руки перед новой игрой
// =====================================================
void clearHands ( )
{
	playerHand.clear ( );  // Очищаем руку игрока
	dealerHand.clear ( );  // Очищаем руку дилера
	cout << "🧹 Руки очищены." << endl;
}

// =====================================================
// Функция 10: Показать статистику колоды
// =====================================================
void showDeckStatus ( )
{
	cout << "\n📊 Колода: " << deck.size ( ) << " карт осталось" << endl;
}

// =====================================================
// Главная функция
// =====================================================
int main ( )
{
	srand ( time ( 0 ) );  // Инициализация генератора случайных чисел

	cout << "🎰 === ИГРА \"21\" (BLACKJACK) === 🎰" << endl;

	// Создаём и перемешиваем колоду
	createDeck ( );
	shuffleDeck ( );

	char playAgain;

	do {
		// Очищаем руки перед новой игрой
		clearHands ( );

		// Раздаём начальные карты (по 2 каждому)
		cout << "\n Раздача карт..." << endl;
		playerHand.push_back ( drawCard ( ) );
		dealerHand.push_back ( drawCard ( ) );
		playerHand.push_back ( drawCard ( ) );
		dealerHand.push_back ( drawCard ( ) );

		// Показываем карты (одна карта дилера скрыта)
		cout << "\n=== 🎴 НАЧАЛО ИГРЫ ===" << endl;
		showHand ( playerHand, "Ваша рука" );
		cout << "Рука дилера: " << dealerHand.at ( 0 ) << " ?" << endl;

		showDeckStatus ( );

		// Ход игрока
		bool playerAlive = playerTurn ( );

		if ( playerAlive ) {
			// Ход дилера
			dealerTurn ( );

			// Определение победителя
			determineWinner ( );
		}

		showDeckStatus ( );

		cout << "\n🔄 Сыграть ещё раз? (y/n): ";
		cin >> playAgain;
	} while ( playAgain == 'y' || playAgain == 'Y' );

	// Финальная очистка
	deck.clear ( );
	playerHand.clear ( );
	dealerHand.clear ( );

	cout << "\n👋 Спасибо за игру!" << endl;

	return 0;
}