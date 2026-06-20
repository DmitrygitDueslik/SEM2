#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;
const int INF = 999999; // Бесконечность для сравнения весов

int n; // Количество вершин
int graph[MAX_VERTICES][MAX_VERTICES]; // Матрица смежности (хранит веса)
bool visited[MAX_VERTICES]; // Для отслеживания посещенных

void processGraph ( int count, int args[] )
{
	for ( int i = 0; i < count; i++ ) {
		cout << args[i] << " ";
	}
	cout << endl;

	if ( count == 3 ) {
		int u = args[0], v = args[1], w = args[2];
		graph[u][v] = w;
		graph[v][u] = w; // Неориентированный граф
		cout << " Добавлено ребро " << u << "-" << v << " вес " << w << endl;
	}
	else if ( count == 2 ) {
		int u = args[0], v = args[1];
		if ( graph[u][v] > 0 && graph[u][v] != INF )
			cout << " Ребро " << u << "-" << v << " существует\n";
		else
			cout << " Ребра " << u << "-" << v << " нет\n";
	}
	else if ( count >= 4 ) {
		cout << " Это список вершин для анализа\n";
	}
}

//  ( Модифицированный BFS)
void findShortestPath ( int start, int end )
{
	int dist[MAX_VERTICES];   // Расстояние от старта до каждой вершины
	int parent[MAX_VERTICES]; // Откуда пришли в вершину (для восстановления пути)

	// Инициализация
	for ( int i = 0; i < n; i++ ) {
		dist[i] = INF;
		parent[i] = -1;
		visited[i] = false;
	}

	dist[start] = 0;

	for ( int iter = 0; iter < n; iter++ ) {
		int u = -1;
		int minDist = INF;

		for ( int i = 0; i < n; i++ ) {
			if ( !visited[i] && dist[i] < minDist ) {
				minDist = dist[i];
				u = i;
			}
		}

		if ( u == -1 ) break;

		if ( u == end ) break;

		visited[u] = true; // Помечаем как обработанную

		// 2. Обновляем расстояния до соседей вершины u
		for ( int v = 0; v < n; v++ ) {
			// Если есть ребро и вершина v еще не обработана окончательно
			if ( graph[u][v] > 0 && !visited[v] ) {
				int newDist = dist[u] + graph[u][v];

				// Если нашли путь короче, чем был ранее
				if ( newDist < dist[v] ) {
					dist[v] = newDist;
					parent[v] = u; // Запоминаем, что пришли в v из u
				}
			}
		}
	}

	if ( dist[end] == INF ) {
		cout << "Пути из " << start << " в " << end << " не существует!\n";
	}
	else {
		cout << "\nКратчайший путь (вес " << dist[end] << "): ";

		int path[MAX_VERTICES];
		int len = 0;
		for ( int v = end; v != -1; v = parent[v] ) {
			path[len++] = v;
		}

		for ( int i = len - 1; i >= 0; i-- ) {
			cout << path[i];
			if ( i > 0 ) cout << " -> ";
		}
		cout << endl;
	}
}

int main ( )
{
	int m;

	// Обнуляем матрицу
	for ( int i = 0; i < MAX_VERTICES; i++ )
		for ( int j = 0; j < MAX_VERTICES; j++ )
			graph[i][j] = 0;

	cout << "Введите количество вершин и рёбер: ";
	cin >> n >> m;

	cout << "Введите рёбра (u v weight):\n";
	for ( int i = 0; i < m; i++ ) {
		int u, v, w;
		cin >> u >> v >> w;

		//  1-е обращение: 3 параметра (добавление ребра)
		int args1[] = { u, v, w };
		processGraph ( 3, args1 );
	}

	//  2-е обращение: 2 параметра (проверка связи между 0 и 1)
	int args2[] = { 0, 1 };
	processGraph ( 2, args2 );

	//  3-е обращение: 4 параметра (тестовый список)
	int args3[] = { 0, 1, 2, 3 };
	processGraph ( 4, args3 );

	int start, end;
	cout << "\nСтарт (A): "; cin >> start;
	cout << "Финиш (B): "; cin >> end;

	findShortestPath ( start, end );

	return 0;
}