#include <iostream>
#include <string>
#include <chrono>

#define INT_MAX 32767
using namespace std;
using namespace std::chrono;
struct BookPhone
{
	int key;
	string fio;
	BookPhone* next;
};
struct HashTable
{
	BookPhone** buckets;
	int size;
	int count;
};

HashTable* createTable ( int size )
{
	HashTable* table = new HashTable;
	table->size = size;
	table->count = 0;

	table->buckets = new BookPhone * [size];
	for ( int i = 0; i < size; i++ ) {
		table->buckets[i] = nullptr;
	}
	return table;
}
int HashIndex ( int key, int size )
{
	if ( size <= 0 ) {
		return 0;
	}
	return   key % size;
}
void insert ( HashTable* table, int key, string fio )
{
	int index = HashIndex ( key, table->size );
	BookPhone* newbook = new BookPhone;
	newbook->key = key;
	newbook->fio = fio;
	newbook->next = nullptr;
	newbook->next = table->buckets[index];
	table->buckets[index] = newbook;
	table->count++;
}

BookPhone* search ( HashTable* table, int key )
{
	int index = HashIndex ( key, table->size );
	BookPhone* current = table->buckets[index];
	while ( current != nullptr ) {
		if ( current->key == key ) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}
void Print ( HashTable* table )
{
	cout << "\n ТАБЛИЦА (Размер: " << table->size << ", Записей: " << table->count << ") " << endl;
	for ( int i = 0; i < table->size; i++ ) {
		cout << "Полка [" << i << "]: ";
		BookPhone* current = table->buckets[i];
		if ( current == nullptr ) {
			cout << "Пусто";
		}
		else {
			while ( current != nullptr ) {
				cout << "[Тел: " << current->key << ", ФИО: " << current->fio << "] -> ";
				current = current->next;
			}
			cout << "NULL";
		}
		cout << endl;
	}
	cout << "----------------------------------------\n" << endl;
}
bool deleteKey ( HashTable* table, int key )
{
	int index = HashIndex ( key, table->size );
	BookPhone* current = table->buckets[index];
	BookPhone* prev = nullptr;//Для предыдущего элемента в списке
	while ( current != nullptr ) {
		if ( current->key == key ) {
			if ( prev == nullptr ) {
				table->buckets[index] = current->next;
			}
			else {
				prev->next = current->next;
			}
			delete current;
			table->count--;
			return true;
		}//Не нашли идем дальше
		prev = current;
		current = current->next;
	}
	return false;
}

void destroy ( HashTable* table )
{
	for ( int i = 0; i < table->size; i++ ) {
		BookPhone* current = table->buckets[i];
		while ( current != nullptr ) {
			BookPhone* temp = current;
			current = current->next;
			delete temp;
		}
	}
	delete[] table->buckets;
	delete table;
}
//Функция для исследования времени

void researchTime ( HashTable* table )
{
	cout << "\n ИССЛЕДОВАНИЕ ВРЕМЕНИ \n" << endl;

	for ( int i = 0; i < table->size; i++ ) {
		BookPhone* current = table->buckets[i];
		while ( current != nullptr ) {
			BookPhone* temp = current;
			current = current->next;
			delete temp;
		}
		table->buckets[i] = nullptr;
	}
	table->count = 0;

	// коллизии
	int elements = table->size * 10;
	cout << "Заполнение " << elements << " элементов " << endl;
	auto start_fill = high_resolution_clock::now ( );

	for ( int i = 0; i < elements; i++ ) {
		int randomKey = 1 + (rand ( ) % INT_MAX);
		string fio = "User_" + to_string ( i );
		insert ( table, randomKey, fio );
	}

	auto end_fill = high_resolution_clock::now ( );
	duration<double, milli>time_fill = end_fill - start_fill;
	cout << "Время заполнения: " << time_fill.count ( ) << " мс" << endl;

	Print ( table );

	cout << "Выполнение 10000 поисков" << endl;
	int iteration = 10000;
	auto start_search = high_resolution_clock::now ( );

	for ( int i = 0; i < iteration; i++ ) {
		int searchKey = 1 + (rand ( ) % INT_MAX);
		search ( table, searchKey );
	}
	auto end_search = high_resolution_clock::now ( );
	duration<double, micro>time_search = end_search - start_search;
	cout << "Общее время поиска: " << time_search.count ( ) << " мкс" << endl;
	cout << "Среднее время одного поиска: " << (time_search.count ( ) / iteration) << " мкс" << endl;
	cout << "--------------------------\n" << endl;
}

int main ( )
{
	srand ( time ( 0 ) );
	int size;
	cout << "Введите размер хеш-таблицы (10, 16, 32): ";
	cin >> size;
	if ( size <= 0 ) {
		cout << "Ошибка: размер должен быть больше 0." << endl;
		return 1;
	}
	HashTable* table = createTable ( size );
	int choice;
	do {
		cout << "\nМЕНЮ:" << endl;
		cout << "1. Вывод таблицы" << endl;
		cout << "2. Добавить элемент" << endl;
		cout << "3. Найти элемент" << endl;
		cout << "4. Удалить элемент" << endl;
		cout << "5. Исследовать время (Авто-тест)" << endl;
		cout << "0. Выход" << endl;
		cout << "Выбор: ";
		cin >> choice;
		int key;
		string fio;
		BookPhone* found;
		switch ( choice ) {
			case 1:
				Print ( table );
				break;
			case 2:
				cout << "Телефон (ключ, макс " << INT_MAX << "): ";
				cin >> key;
				if ( key <= 0 || key > INT_MAX ) {
					cout << "Ошибка: Ключ должен быть в диапазоне от 1 до " << INT_MAX << endl;
					cin.ignore ( 10000, '\n' );
					break;
				}
				cin.ignore ( );
				cout << "ФИО: ";
				getline ( cin, fio );
				if ( fio.empty ( ) ) {
					cout << "Ошибка: ФИО не может быть пустым." << endl;
					break;
				}
				insert ( table, key, fio );
				cout << "Добавлено " << endl;
				break;
			case 3:
				cout << "Телефон для поиска: ";
				cin >> key;
				found = search ( table, key );
				if ( found != nullptr ) {
					cout << "Найдено: " << found->fio << endl;
				}
				else {
					cout << "Не найдено " << endl;
				}
				break;
			case 4:
				cout << "Телефон для удаления: ";
				cin >> key;
				if ( deleteKey ( table, key ) ) {
					cout << "Удалено " << endl;
				}
				else {
					cout << "Не найдено " << endl;
				}break;
			case 5:
				researchTime ( table );
				break;
			case 0:break;
			default:
				cout << "Неверный выбор " << endl;
		}
		if ( choice != 0 ) system ( "pause" );
	} while ( choice != 0 );
	destroy ( table );
	return 0;
}