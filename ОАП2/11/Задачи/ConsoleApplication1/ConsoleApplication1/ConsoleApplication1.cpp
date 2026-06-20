#include <iostream>
using namespace std;

struct Queue
{
	char symbol;
	Queue* next;
};

void enqueue ( Queue* ph[], char v, int maxSize );
char dequeue ( Queue* ph[] );
void display ( Queue* ph[] );
bool isEmpty ( Queue* ph[] );
int getSize ( Queue* ph[] );
void menu ( );

int main ( )
{
	int maxSize;
	cout << "Введите максимальный размер очереди: ";
	cin >> maxSize;

	Queue* ph[2] = { nullptr, nullptr }; // ph[0] - голова, ph[1] - хвост

	int choice;
	char ch;
	int count = 0; // Счётчик введённых символов

	do {
		menu ( );
		cout << "Выберите действие: ";
		cin >> choice;

		switch ( choice ) {
			case 1:
				cout << "Введите символ: ";
				cin >> ch;

				// Проверяем, не заполнена ли очередь
				if ( getSize ( ph ) >= maxSize ) {
					cout << "Очередь заполнена! Удаляем первый элемент." << endl;
					char removed = dequeue ( ph );
					cout << "Удалён символ: " << removed << endl;
				}

				enqueue ( ph, ch, maxSize );
				count++;

				// После 5-го символа удаляем по одному элементу при каждом вводе
				if ( count > 5 ) {
					cout << "Введено более 5 символов. Удаляем первый элемент." << endl;
					char removed = dequeue ( ph );
					cout << "Удалён символ: " << removed << endl;
				}

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

			case 0: // Выход
				cout << "Выход из программы" << endl;
				break;

			default:
				cout << "Неверный выбор!" << endl;
		}
		cout << endl;
	} while ( choice != 0 );

	// Очистка памяти
	while ( !isEmpty ( ph ) ) {
		dequeue ( ph );
	}

	return 0;
}

// Добавление элемента в очередь
void enqueue ( Queue* ph[], char v, int maxSize )
{
	if ( getSize ( ph ) >= maxSize ) {
		cout << "Очередь заполнена!" << endl;
		return;
	}

	Queue* p = new Queue;
	p->symbol = v;
	p->next = nullptr;

	if ( ph[0] == nullptr ) { // Пустая очередь
		ph[0] = ph[1] = p;
	}
	else {
		ph[1]->next = p;
		ph[1] = p;
	}
	cout << "Символ '" << v << "' добавлен в очередь" << endl;
}

// Удаление элемента из очереди
char dequeue ( Queue* ph[] )
{
	if ( ph[0] == nullptr ) {
		cout << "Очередь пуста!" << endl;
		return '\0';
	}

	Queue* q = ph[0];
	ph[0] = q->next;

	if ( ph[0] == nullptr ) { // Очередь стала пустой
		ph[1] = nullptr;
	}

	char v = q->symbol;
	delete q;
	return v;
}

// Вывод очереди
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

// Проверка на пустоту
bool isEmpty ( Queue* ph[] )
{
	return ph[0] == nullptr;
}

// Получение размера очереди
int getSize ( Queue* ph[] )
{
	int count = 0;
	for ( Queue* p = ph[0]; p != nullptr; p = p->next ) {
		count++;
	}
	return count;
}

void menu ( )
{
	cout << "\n МЕНЮ " << endl;
	cout << "1. Добавить символ в очередь" << endl;
	cout << "2. Удалить символ из очереди" << endl;
	cout << "3. Вывести очередь" << endl;
	cout << "4. Проверить на пустоту" << endl;
	cout << "5. Размер очереди" << endl;
	cout << "0. Выход" << endl;
}