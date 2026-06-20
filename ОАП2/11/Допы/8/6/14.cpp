#include <iostream>
using namespace std;

struct Queue
{
	char data;
	Queue* next;
};

void enqueue ( Queue*& front, Queue*& rear, char value )
{
	Queue* newNode = new Queue;
	newNode->data = value;
	newNode->next = nullptr;

	if ( front == nullptr ) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
}

char dequeue ( Queue*& front, Queue*& rear )
{
	if ( front == nullptr ) {
		return '\0';
	}

	Queue* temp = front;
	char value = temp->data;
	front = front->next;

	if ( front == nullptr ) {
		rear = nullptr;
	}

	delete temp;
	return value;
}

void displayQueue ( Queue* front )
{
	if ( front == nullptr ) {
		cout << "Очередь пуста" << endl;
		return;
	}

	cout << "Очередь: ";
	for ( Queue* p = front; p != nullptr; p = p->next ) {
		cout << "'" << p->data << "' ";
	}
	cout << endl;
}

void clearQueue ( Queue*& front, Queue*& rear )
{
	while ( front != nullptr ) {
		dequeue ( front, rear );
	}
}

void processTargetSymbol ( Queue*& front, Queue*& rear, char target )
{
	if ( front == nullptr ) {
		cout << "Очередь пуста. Нечего искать." << endl;
		return;
	}

	// Поиск эталонного символа
	Queue* current = front;
	bool found = false;
	int countToRemove = 0; // Счетчик элементов, которые нужно удалить

	while ( current != nullptr ) {
		if ( current->data == target ) {
			found = true;
			break;
		}
		countToRemove++;
		current = current->next;
	}

	if ( !found ) {
		cout << "Символ '" << target << "' не найден в очереди. Удалений не произведено." << endl;
		return;
	}

	//Удаление элементов до эталонного
	cout << "Символ '" << target << "' найден. Удаляем " << countToRemove << " элементов перед ним..." << endl;

	for ( int i = 0; i < countToRemove; i++ ) {
		if ( front != nullptr ) {
			char removed = dequeue ( front, rear );

			cout << "Удален: '" << removed << "'" << endl;
		}
	}

	cout << "Готово. Теперь первый элемент очереди: '" << front->data << "'" << endl;
}

void menu ( )
{
	cout << "\n МЕНЮ " << endl;
	cout << "1. Добавить символ в очередь" << endl;
	cout << "2. Вывести текущую очередь" << endl;
	cout << "3. Найти эталонный символ и удалить предыдущие" << endl;
	cout << "4. Очистить очередь" << endl;
	cout << "0. Выход" << endl;
}

int main ( )
{
	Queue* front = nullptr;
	Queue* rear = nullptr;

	int choice;
	char ch, target;

	do {
		menu ( );
		cout << "Выберите действие: ";
		cin >> choice;

		switch ( choice ) {
			case 1:
				cout << "Введите символ: ";
				cin.ignore ( );
				cin >> ch;

				enqueue ( front, rear, ch );
				cout << "Символ '" << ch << "' добавлен." << endl;
				break;

			case 2: // Вывод
				displayQueue ( front );
				break;

			case 3: // Поиск и удаление
				if ( front == nullptr ) {
					cout << "Очередь пуста!" << endl;
				}
				else {
					cout << "Введите эталонный символ для поиска: ";
					cin.ignore ( );
					cin >> target;

					// Выполняем логику
					processTargetSymbol ( front, rear, target );

					cout << "Результат работы: ";
					displayQueue ( front );
				}
				break;

			case 4: // Очистка
				clearQueue ( front, rear );
				cout << "Очередь очищена." << endl;
				break;

			case 0: // Выход
				cout << "Выход из программы." << endl;
				break;

			default:
				cout << "Неверный выбор!" << endl;
		}
	} while ( choice != 0 );

	clearQueue ( front, rear );
	return 0;
}