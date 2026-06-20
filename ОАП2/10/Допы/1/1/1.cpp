#include <iostream>
#include <deque>
#include <string>
#include <cmath>
using namespace std;

struct Request
{
	int floor;
	int priority; // приоритет: 2 = из лифта (высокий), 1 = с этажа (низкий)
	string type;	// текстовое описание для вывода
};

deque <Request> requests;
//Добавить
void add ( int floor, int priority, string type )
{
	Request req;
	req.floor = floor;
	req.priority = priority;
	req.type = type;
	if ( priority == 2 ) {
		//Высокий-начало дека
		//Низкий-конец дека
		requests.push_front ( req );
		cout << " Добавлен приоритетный запрос: этаж " << floor << " (" << type << ")" << endl;
	}
	else {
		requests.push_back ( req );
		cout << " Добавлен запрос: этаж " << floor << " (" << type << ")" << endl;
	}
}
//Найти ближайший запрос в направлении движения
int findNearest ( int currentfloor, int direction )
{
	int nearestId = -1;
	int minDist = 999;
	for ( int i = 0; i < requests.size ( ); i++ ) {
		int floor = requests[i].floor;
		int dist = abs ( floor - currentfloor );
		bool inDir = false;
		if ( direction == 1 && floor >= currentfloor )inDir = true;
		if ( direction == -1 && floor <= currentfloor )inDir = true;
		if ( inDir && dist < minDist ) {
			minDist = dist;
			nearestId = i;
		}
	}
	return nearestId;
}
//Обработка запросов
void process ( )
{
	int currentFloor = 1;   // лифт  с 1 этажа
	int direction = 1;      // 1 = вверх, -1 = вниз
	int stopNumber = 1;
	cout << "\n Лифт начинает движение с 1 этажа " << endl;
	while ( !requests.empty ( ) ) {
		int idx = -1;
		for ( int i = 0; i < requests.size ( ); i++ ) {
			if ( requests[i].priority == 2 ) {
				if ( idx == -1 || abs ( requests[i].floor - currentFloor ) < abs ( requests[idx].floor - currentFloor ) );
				idx = i;
			}
		}
		if ( idx == -1 ) {
			idx = findNearest ( currentFloor, direction );
		}
		if ( idx == -1 ) {
			direction = -direction;
			cout << " Нет запросов в направлении " << (direction == 1 ? "вверх" : "вниз") << ". Разворот..." << endl;
			idx = findNearest ( currentFloor, direction );
		}
		if ( idx != -1 ) {
			Request req = requests[idx];
			// Вывод остановки
			cout << "Остановка #" << stopNumber << ": этаж " << req.floor
				<< " [" << req.type << ", приоритет " << req.priority << "]" << endl;

			// Перемещаем лифт
			currentFloor = req.floor;

			// Меняем направление если нужно
			if ( req.floor > currentFloor ) direction = 1;
			else if ( req.floor < currentFloor ) direction = -1;

			// Удаление запроса из дека
			requests.erase ( requests.begin ( ) + idx );
			stopNumber++;
		}
		cout << "\n Все запросы обработаны. Лифт на этаже " << currentFloor << endl;
	}
}
//текущие запросы
void showRequests ( )
{
	cout << "\nТекущие запросы в деке:" << endl;
	if ( requests.empty ( ) ) {
		cout << "  (пусто)" << endl;
	}
	else {
		for ( int i = 0; i < requests.size ( ); i++ ) {
			cout << "  " << (i + 1) << ". Этаж " << requests[i].floor
				<< "  Приоритет: " << requests[i].priority
				<< "  " << requests[i].type << endl;
		}
	}
	cout << endl;
}

void showMenu ( )
{
	cout << "\n МЕНЮ ЛИФТА " << endl;
	cout << "1. Добавить запрос (из лифта, высокий приоритет)" << endl;
	cout << "2. Добавить запрос (с этажа, низкий приоритет)" << endl;
	cout << "3. Показать запросы" << endl;
	cout << "4. Запустить обработку" << endl;
	cout << "5. Выход" << endl;
}

int main ( )
{
	cout << " Система управления лифтом запущена" << endl;

	int choice, floor;

	do {
		showMenu ( );
		cin >> choice;

		switch ( choice ) {
			case 1:  // Запрос из лифта (высокий приоритет)
				cout << "Введите номер этажа: ";
				cin >> floor;
				add ( floor, 2, "из лифта" );
				break;

			case 2:  // Запрос с этажа (низкий приоритет)
				cout << "Введите номер этажа: ";
				cin >> floor;
				add ( floor, 1, "с этажа" );
				break;

			case 3:  // Показать запросы
				showRequests ( );
				break;

			case 4:  // Обработать
				process ( );
				break;

			case 5:
				cout << "Завершение работы" << endl;
				break;

			default:
				cout << "Неверный выбор" << endl;
		}
	} while ( choice != 5 );

	return 0;
}