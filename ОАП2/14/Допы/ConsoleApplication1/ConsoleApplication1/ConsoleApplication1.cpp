#include <iostream>
using namespace std;
const int MAX_N = 100;
int n, m;
int graph[MAX_N][MAX_N];
bool visited[MAX_N];

void processGraph ( int count, int args[] )
{
	if ( count == 2 ) {
		int u = args[0], v = args[1];
		graph[u][v] = 1;
		graph[v][u] = 1;// Неориентированный граф
		cout << "  Ребро " << u << "-" << v << " добавлено\n";
	}
	else if ( count == 1 ) {
		// 1 параметр: вывод отдельной вершины
		cout << args[0] << " ";
	}
	else if ( count >= 3 ) {
		// 3+ параметров: номер компоненты, размер, список вершин
		cout << "\nКомпонента #" << args[0]
			<< " (вершин: " << args[1] << "): ";
		for ( int i = 2; i < count; i++ ) {
			cout << args[i] << " ";
		}
		cout << endl;
	}
}
// DFS для поиска всех вершин в одной компоненте связности
void dfs ( int v, int component[], int& compSize )
{
	visited[v] = true;
	component[compSize++] = v;
	for ( int i = 0; i < n; i++ ) {
		if ( graph[v][i] == 1 && !visited[i] ) {
			dfs ( i, component, compSize );
		}
	}
}

int main ( )
{
	cout << "Введите количество вершин и рёбер: ";
	cin >> n >> m;
	for ( int i = 0; i < n; i++ ) {
		visited[i] = false;
		for ( int j = 0; j < n; j++ ) graph[i][j] = 0;
	}
	cout << "Введите рёбра (вершина1 вершина2):\n";
	for ( int i = 0; i < m; i++ ) {
		int u, v;
		cin >> u >> v;
		int edgeArgs[2] = { u, v };
		processGraph ( 2, edgeArgs );  // 1-е обращение: 2 параметра
	}

	// Поиск компонент связности

	int compCount = 0;
	cout << "\n--- Результат ---\n";

	for ( int i = 0; i < n; i++ ) {
		if ( !visited[i] ) {
			compCount++;
			int component[MAX_N];
			int size = 0;
			dfs ( i, component, size );
			int args[MAX_N];
			args[0] = compCount;
			args[1] = size;
			for ( int k = 0; k < size; k++ ) {
				args[k + 2] = component[k];
			}
			// 2-e и последующие обращения: переменное число параметров (>=3)
			processGraph ( 2 + size, args );
		}
		cout << "\nВсего компонент связности: " << compCount << endl;
		return 0;
	}
}