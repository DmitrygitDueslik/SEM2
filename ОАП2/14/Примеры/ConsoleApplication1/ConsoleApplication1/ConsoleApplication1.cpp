#include <iostream>
using namespace std;

int main ( )
{
	int n, m;
	cout << "Введите количество вершин и рёбер: ";
	cin >> n >> m;

	int graph[100][100] = { 0 };
	cout << "Введите рёбра (начало и конец):\n";
	for ( int i = 0; i < m; i++ ) {
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}

	cout << "Матрица смежности:\n";
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ )
			cout << graph[i][j] << " ";
		cout << endl;
	}
	return 0;
}