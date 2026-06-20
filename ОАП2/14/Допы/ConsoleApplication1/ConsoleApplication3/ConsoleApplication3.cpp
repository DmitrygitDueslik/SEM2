#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
int n, m;
int graph[MAX_N][MAX_N];      // Матрица смежности
bool visited[MAX_N];          // Посещённые вершины
int tin[MAX_N], low[MAX_N];   // Время входа и минимальное достижимое время
int timer;                    // Глобальный таймер DFS
int bridgeU[MAX_N], bridgeV[MAX_N]; // Хранилище найденных мостов
int bridgeCount = 0;

void processGraph ( int count, int args[] )
{
	if ( count == 3 ) {
		// 3 параметра: добавление ребра (u, v, вес)
		int u = args[0], v = args[1];
		graph[u][v] = 1;
		graph[v][u] = 1;
		cout << "  → Ребро " << u << "-" << v << " добавлено\n";
	}
	else if ( count == 2 ) {
		// 2 параметра: проверка существования ребра
		int u = args[0], v = args[1];
		if ( graph[u][v] ) cout << "  → Ребро " << u << "-" << v << " существует\n";
		else cout << "  → Ребра " << u << "-" << v << " нет\n";
	}
	else if ( count == 1 ) {
		// 1 параметр: мостов не найдено
		cout << "\nМостов в графе не найдено.\n";
	}
	else if ( count >= 4 ) {
		// 4+ параметров: вывод найденных мостов
		int bridgesNum = args[0];
		cout << "\nНайдено мостов: " << bridgesNum << "\n";
		for ( int i = 0; i < bridgesNum; i++ ) {
			cout << "  Мост #" << (i + 1) << ": " << args[1 + i * 2] << " - " << args[2 + i * 2] << "\n";
		}
	}
}

void dfs ( int u, int parent = -1 )
{
	visited[u] = true;
	tin[u] = low[u] = timer++; // Запоминаем время посещения

	for ( int v = 0; v < n; v++ ) {
		if ( v == parent ) continue; // Не идём обратно к родителю
		if ( graph[u][v] ) {         // Если есть ребро
			if ( visited[v] ) {
				// Обратное ребро (цикл): обновляем low[u]
				low[u] = min ( low[u], tin[v] );
			}
			else {
				dfs ( v, u );
				low[u] = min ( low[u], low[v] ); // Возвращаем min из поддерева

				// УСЛОВИЕ МОСТА: если из поддерева v нельзя добраться до u или выше
				if ( low[v] > tin[u] ) {
					bridgeU[bridgeCount] = u;
					bridgeV[bridgeCount] = v;
					bridgeCount++;
				}
			}
		}
	}
}

// ---------------------------------------------------------
int main ( )
{
	cout << "Вершин и рёбер: ";
	cin >> n >> m;

	for ( int i = 0; i < n; i++ ) {
		visited[i] = false;
		for ( int j = 0; j < n; j++ ) graph[i][j] = 0;
	}

	cout << "Введите рёбра (u v):\n";
	for ( int i = 0; i < m; i++ ) {
		int u, v;
		cin >> u >> v;
		int args[] = { u, v, 1 };
		processGraph ( 3, args );  //  1-е обращение: 3 параметра
	}

	// Проверка одного ребра
	int checkArgs[] = { 0, 1 };
	processGraph ( 2, checkArgs ); //  2-е обращение: 2 параметра

	timer = 0;
	bridgeCount = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( !visited[i] ) dfs ( i );
	}

	// Подготовка аргументов для вывода результатов
	int outArgs[MAX_N * 2];
	outArgs[0] = bridgeCount;
	for ( int i = 0; i < bridgeCount; i++ ) {
		outArgs[1 + i * 2] = bridgeU[i];
		outArgs[2 + i * 2] = bridgeV[i];
	}

	//  3-е обращение: 1 параметр (если мостов 0) или >=4 (если есть)
	processGraph ( (bridgeCount == 0) ? 1 : (1 + 2 * bridgeCount), outArgs );

	return 0;
}