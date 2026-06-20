#include <iostream>
#include <limits.h>//для использования максимальных значений INT_MAX

using namespace std;

int main ( )
{
	int size; // Количество вершин в графе
	cout << "Введите количество вершин: ";
	cin >> size;

	// Создание динамической матрицы смежности
	int** graph = new int* [size]; // Выделяем память для массива указателей
	for ( int i = 0; i < size; i++ ) {
		graph[i] = new int[size]; // Выделяем память для строк
		for ( int j = 0; j < size; j++ ) {
			if ( i == j ) {
				graph[i][j] = 0; // Расстояние от вершины до самой себя равно 0
			}
			else {
				graph[i][j] = INT_MAX; // Изначально пути нет (максимальное значение)
			}
		}
	}

	int edges; // Количество рёбер
	cout << "Введите количество рёбер: ";
	cin >> edges;

	cout << "Введите рёбра в формате (вершина1 вершина2 вес):\n";
	for ( int i = 0; i < edges; i++ ) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from][to] = weight; // Устанавливаем вес ребра между вершинами
	}

	// Алгоритм Флойда-Уоршелла
	for ( int k = 0; k < size; k++ ) { // Промежуточная вершина
		for ( int i = 0; i < size; i++ ) { // Начальная вершина
			for ( int j = 0; j < size; j++ ) { // Конечная вершина
				// Проверяем, существует ли путь через вершину k
				if ( graph[i][k] != INT_MAX && graph[k][j] != INT_MAX ) {
					int newDist = graph[i][k] + graph[k][j]; // Вычисляем новое расстояние
					if ( newDist < graph[i][j] ) { // Если найден более короткий путь, обновляем его
						graph[i][j] = newDist;
					}
				}
			}
		}
	}

	// Вывод результирующей матрицы кратчайших расстояний
	cout << "Матрица кратчайших расстояний:\n";
	for ( int i = 0; i < size; i++ ) {
		for ( int j = 0; j < size; j++ ) {
			if ( graph[i][j] == INT_MAX ) {
				cout << "? "; // Выводим знак вопроса, если пути нет
			}
			else {
				cout << graph[i][j] << " "; // Выводим расстояние
			}
		}
		cout << endl;
	}

	for ( int i = 0; i < size; i++ ) {
		delete[] graph[i]; // Удаляем каждую строку
	}
	delete[] graph; // Удаляем массив указателей

	return 0;
}