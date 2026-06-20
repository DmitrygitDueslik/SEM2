#include <iostream>
using namespace std;

struct Queue
{
	int symbol;
	Queue* next;
};

void enqueue ( Queue* ph[], int v, int maxSize );
int dequeue ( Queue* ph[] );
void display ( Queue* ph[] );
bool isEmpty ( Queue* ph[] );
int getSize ( Queue* ph[] );
void removeFirstNegative ( Queue* ph[] );
void menu ( );

int main ( )
{
	int maxSize;
	cout << "Введите максимальный размер очереди: ";
	cin >> maxSize;

	Queue* ph[2] = { nullptr, nullptr }; // ph[0] - голова, ph[1] - хвост

	int choice;
	int ch;
	int count = 0; // Счётчик введённых символов

	do {
		menu ( );
		cout << "Выберите действие: ";
		cin >> choice;

		switch ( choice ) {
			case 1:
				cout << "Введите целое число: ";
				cin >> ch;

				// Проверяем, не заполнена ли очередь
				if ( getSize ( ph ) >= maxSize ) {
					cout << "Очередь заполнена! Удаляем первый элемент." << endl;
					char removed = dequeue ( ph );
					cout << "Удалён символ: " << removed << endl;
				}

				enqueue ( ph, ch, maxSize );

				display ( ph );
				break;

			case 2: // Удаление элемента
				if ( isEmpty ( ph ) ) {
					cout << "Очередь пуста!" << endl;
				}
				else {
					char removed = dequeue ( ph );
					cout << "Удалён символ: " << removed << endl;
					display ( ph );
				}
				break;

			case 3: // Вывод очереди
				display ( ph );
				break;

			case 4: // Проверка на пустоту
				if ( isEmpty ( ph ) )
					cout << "Очередь пуста" << endl;
				else
					cout << "Очередь не пуста" << endl;
				break;

			case 5: // Размер очереди
				cout << "Текущий размер очереди: " << getSize ( ph ) << endl;
				break;
			case 6: // Удаление первого отрицательного элемента
				removeFirstNegative ( ph );
				display ( ph );
				break;
			case 0: // Выход
				cout << "Выход из программы" << endl;
				break;

			default:
				cout << "Неверный выбор!" << endl;
		}
		cout << endl;
	} while ( choice != 0 );

	while ( !isEmpty ( ph ) ) {
		dequeue ( ph );
	}

	return 0;
}

void enqueue ( Queue* ph[], int v, int maxSize )
{
	if ( getSize ( ph ) >= maxSize ) {
		cout << "Очередь заполнена!" << endl;
		return;
	}

	Queue* p = new Queue;
	p->symbol = v;
	p->next = nullptr;

	if ( ph[0] == nullptr ) {
		ph[0] = ph[1] = p;
	}
	else {
		ph[1]->next = p;
		ph[1] = p;
	}
	cout << "Символ '" << v << "' добавлен в очередь" << endl;
}

int dequeue ( Queue* ph[] )
{
	if ( ph[0] == nullptr ) {
		cout << "Очередь пуста!" << endl;
		return '\0';
	}

	Queue* q = ph[0];
	ph[0] = q->next;

	if ( ph[0] == nullptr ) {
		ph[1] = nullptr;
	}

	char v = q->symbol;
	delete q;
	return v;
}

void display ( Queue* ph[] )
{
	if ( ph[0] == nullptr ) {
		cout << "Очередь пуста" << endl;
		return;
	}

	cout << "Очередь: ";
	for ( Queue* p = ph[0]; p != nullptr; p = p->next ) {
		cout << p->symbol << " ";
	}
	cout << endl;
}

bool isEmpty ( Queue* ph[] )
{
	return ph[0] == nullptr;
}

int getSize ( Queue* ph[] )
{
	int count = 0;
	for ( Queue* p = ph[0]; p != nullptr; p = p->next ) {
		count++;
	}
	return count;
}

void removeFirstNegative ( Queue* ph[] )
{
	if ( ph[0] == nullptr ) {
		cout << "Очередь пуста!" << endl;
		return;
	}

	Queue* current = ph[0];
	Queue* prev = nullptr;

	while ( current != nullptr && current->symbol >= 0 ) {
		prev = current;
		current = current->next;
	}

	if ( current == nullptr ) {
		cout << "Отрицательных элементов нет!" << endl;
		return;
	}

	// Удаляем найденный элемент
	if ( prev == nullptr ) {
		// Удаляем первый элемент
		ph[0] = current->next;
		if ( ph[0] == nullptr ) {
			ph[1] = nullptr;
		}
	}
	else {
		// Удаляем элемент в середине или конце
		prev->next = current->next;
		if ( current == ph[1] ) {
			ph[1] = prev;
		}
	}

	cout << "Удалён первый отрицательный элемент: " << current->symbol << endl;
	delete current;
}
void menu ( )
{
	cout << "\n МЕНЮ " << endl;
	cout << "1. Добавить число в очередь" << endl;
	cout << "2. Удалить число из очереди" << endl;
	cout << "3. Вывести очередь" << endl;
	cout << "4. Проверить на пустоту" << endl;
	cout << "5. Размер очереди" << endl;
	cout << "6. Удалить первый отрицательный элемент" << endl;
	cout << "0. Выход" << endl;
}