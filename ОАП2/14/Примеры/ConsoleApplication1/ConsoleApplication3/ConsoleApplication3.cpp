#include <iostream>
#include <queue>
#include <stack>
#include <list>

using namespace std;

const int MAX_VERTICES = 10; // Максимальное количество вершин
list<int> adjList[MAX_VERTICES]; // Массив списков смежности
bool visited[MAX_VERTICES]; // Массив для отслеживания посещённых вершин

// Функция для добавления ребра
void addEdge ( int u, int v )
{
	adjList[u].push_back ( v );
	adjList[v].push_back ( u ); // Для неориентированного графа
}

// Обнуление массива visited
void resetVisited ( )
{
	for ( int i = 0; i < MAX_VERTICES; ++i ) {
		visited[i] = false;
	}
}

// Обход в ширину (BFS)
void BFS ( int startVertex )
{
	queue<int> q;
	q.push ( startVertex );
	visited[startVertex] = true;

	cout << "Обход в ширину (BFS), начиная с вершины " << startVertex << ": ";

	while ( !q.empty ( ) ) {
		int current = q.front ( );
		q.pop ( );
		cout << current << " ";

		for ( int neighbor : adjList[current] ) {
			if ( !visited[neighbor] ) {
				q.push ( neighbor );
				visited[neighbor] = true;
			}
		}
	}
	cout << endl;
}

// Обход в глубину (DFS)
void DFS ( int startVertex )
{
	stack<int> s;
	s.push ( startVertex );

	cout << "Обход в глубину (DFS), начиная с вершины " << startVertex << ": ";

	while ( !s.empty ( ) ) {
		int current = s.top ( );
		s.pop ( );

		if ( !visited[current] ) {
			cout << current << " ";
			visited[current] = true;
		}

		for ( auto it = adjList[current].rbegin ( ); it != adjList[current].rend ( ); ++it ) {
			if ( !visited[*it] ) {
				s.push ( *it );
			}
		}
	}
	cout << endl;
}

int main ( )
{
	int vertices = 5; // Количество вершин в графе

	// Добавление рёбер
	addEdge ( 0, 1 );
	addEdge ( 0, 4 );
	addEdge ( 1, 2 );
	addEdge ( 1, 3 );
	addEdge ( 1, 4 );
	addEdge ( 2, 3 );
	addEdge ( 3, 4 );

	// Вывод доступных алгоритмов
	cout << "Выберите метод обхода:" << endl;
	cout << "1. BFS (Обход в ширину)" << endl;
	cout << "2. DFS (Обход в глубину)" << endl;

	int choice;
	cin >> choice;

	if ( choice == 1 ) {
		resetVisited ( ); // Сброс массива visited
		BFS ( 0 ); // Запуск BFS с вершины 0
	}
	else if ( choice == 2 ) {
		resetVisited ( ); // Сброс массива visited
		DFS ( 0 ); // Запуск DFS с вершины 0
	}
	else {
		cout << "Неверный выбор!" << endl;
	}

	return 0;
}