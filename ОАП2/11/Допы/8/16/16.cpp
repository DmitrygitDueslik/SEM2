#include <iostream>
using namespace std;

struct Queue
{
	int data;
	Queue* next;
};

void enqueue ( Queue*& front, Queue*& rear, int value )
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

int dequeue ( Queue*& front, Queue*& rear )
{
	if ( front == nullptr ) {
		cout << "Очередь пуста!" << endl;
		return 0;
	}

	Queue* temp = front;
	int value = temp->data;
	front = front->next;

	if ( front == nullptr ) {
		rear = nullptr;
	}

	delete temp;
	return value;
}

void display ( Queue* front )
{
	if ( front == nullptr ) {
		cout << "Очередь пуста" << endl;
		return;
	}

	cout << "Очередь: ";
	for ( Queue* p = front; p != nullptr; p = p->next ) {
		cout << p->data << " ";
	}
	cout << endl;
}

bool isEmpty ( Queue* front )
{
	return front == nullptr;
}

void clearQueue ( Queue*& front, Queue*& rear )
{
	while ( front != nullptr ) {
		dequeue ( front, rear );
	}
}

// Разделить  на положительные и отрицательные
void splitQueue ( Queue* source, Queue*& positive, Queue*& negative )
{
	positive = nullptr;
	Queue* posRear = nullptr;

	negative = nullptr;
	Queue* negRear = nullptr;

	for ( Queue* current = source; current != nullptr; current = current->next ) {
		if ( current->data >= 0 ) {
			// Положительное или ноль в первую очередь
			enqueue ( positive, posRear, current->data );
		}
		else {
			// Отрицательное во вторую очередь
			enqueue ( negative, negRear, current->data );
		}
	}
}

void menu ( )
{
	cout << "\nМЕНЮ " << endl;
	cout << "1. Добавить число в очередь" << endl;
	cout << "2. Вывести исходную очередь" << endl;
	cout << "3. Разделить очередь на положительные/отрицательные" << endl;
	cout << "4. Вывести очередь с положительными" << endl;
	cout << "5. Вывести очередь с отрицательными" << endl;
	cout << "6. Очистить все очереди" << endl;
	cout << "0. Выход" << endl;
}

int main ( )
{
	Queue* source = nullptr;
	Queue* sourceRear = nullptr;

	Queue* positive = nullptr;
	Queue* positiveRear = nullptr;

	Queue* negative = nullptr;
	Queue* negativeRear = nullptr;

	int choice, value;

	do {
		menu ( );
		cout << "Выберите действие: ";
		cin >> choice;

		switch ( choice ) {
			case 1: // Ввод числа
				cout << "Введите целое число: ";
				cin >> value;
				enqueue ( source, sourceRear, value );
				cout << "Число " << value << " добавлено в очередь" << endl;
				break;

			case 2:
				display ( source );
				break;

			case 3: // Разделение очереди
				if ( isEmpty ( source ) ) {
					cout << "Нечего разделять." << endl;
				}
				else {
					// Очищаем старые , если были
					clearQueue ( positive, positiveRear );
					clearQueue ( negative, negativeRear );

					// Разделяем
					splitQueue ( source, positive, negative );
					cout << "Очередь разделена!" << endl;
				}
				break;

			case 4:
				cout << "Положительные числа: ";
				display ( positive );
				break;

			case 5:
				cout << "Отрицательные числа: ";
				display ( negative );
				break;

			case 6: // Очистка
				clearQueue ( source, sourceRear );
				clearQueue ( positive, positiveRear );
				clearQueue ( negative, negativeRear );
				cout << "Все очереди очищены" << endl;
				break;

			case 0: // Выход
				cout << "Выход из программы" << endl;
				break;

			default:
				cout << "Неверный выбор!" << endl;
		}
		cout << endl;
	} while ( choice != 0 );

	clearQueue ( source, sourceRear );
	clearQueue ( positive, positiveRear );
	clearQueue ( negative, negativeRear );

	return 0;
}