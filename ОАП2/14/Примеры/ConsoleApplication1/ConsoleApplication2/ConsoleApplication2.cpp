#include <iostream>
#include <climits> // Для INT_MAX

using namespace std;

// Структура узла списка смежности
struct Node
{
	int vertex;     // Номер вершины
	Node* next;     // Указатель на следующий узел
};

// Функция добавления ребра в список смежности
void addEdge ( Node** adjList, int u, int v )
{
	// Добавляем v в список u
	Node* newNode = new Node;
	newNode->vertex = v;
	newNode->next = adjList[u];
	adjList[u] = newNode;

	// Для неориентированного графа добавляем обратное ребро
	newNode = new Node;
	newNode->vertex = u;
	newNode->next = adjList[v];
	adjList[v] = newNode;
}

// Функция вывода списка смежности
void printAdjList ( Node** adjList, int n )
{
	cout << "\nСписок смежности:\n";
	for ( int i = 0; i < n; i++ ) {
		cout << "Вершина " << i << ": ";
		Node* current = adjList[i];
		while ( current != nullptr ) {
			cout << current->vertex << " ";
			current = current->next;
		}
		cout << endl;
	}
}

// Функция освобождения памяти
void freeMemory ( Node** adjList, int n )
{
	for ( int i = 0; i < n; i++ ) {
		Node* current = adjList[i];
		while ( current != nullptr ) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}
	delete[] adjList;
}

int main ( )
{
	int n, m;
	cout << "Введите количество вершин и рёбер: ";
	cin >> n >> m;

	// Создание массива указателей на списки смежности
	Node** adjList = new Node * [n];
	for ( int i = 0; i < n; i++ ) {
		adjList[i] = nullptr;
	}

	cout << "Введите рёбра (начало и конец):\n";
	for ( int i = 0; i < m; i++ ) {
		int u, v;
		cin >> u >> v;
		addEdge ( adjList, u, v );
	}

	printAdjList ( adjList, n );
	freeMemory ( adjList, n );

	return 0;
}