#include <iostream>

#define V 9

using namespace std;


// Функция для поиска вершины с минимальным расстоянием из множества вершин, которые еще не включены в кратчайший путь
int minDistance(int dist[], bool sptSet[])
{
	// Инициализируем минимальное расстояние как бесконечность
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// Вывод
void printSolution(int dist[])
{
	cout << "Вершина \t Дистанция от заданной вершины" << endl;

	char str[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
	for (int i = 0; i < V; i++)
		cout << "До вершины " << str[i] << " \t\t " << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // содержит кратчайшее расстояние от src до i

	bool sptSet[V]; // sptSet[i] будет true, если вершина i включена в кратчайший путь

	// Инициализация всех расстояний как бесконечность и sptSet[] как false
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Расстояние от источника до самого себя всегда равно 0
	dist[src] = 0;

	// Находим кратчайший путь для всех вершин
	for (int count = 0; count < V - 1; count++)
	{
		// Выбираем вершину с минимальным расстоянием из множества вершин, которые еще не включены в кратчайший путь
		int u = minDistance(dist, sptSet);

		// Добавляем выбранную вершину в кратчайший путь
		sptSet[u] = true;

		// Обновляем значение расстояния соседних вершин выбранной вершины
		for (int v = 0; v < V; v++)

			// Обновляем dist[v] только если не в sptSet, есть ребро от u до v, и вес ребра меньше текущего значения dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// Вывод кратчайшего расстояния до всех вершин
	printSolution(dist);
}

int main()
{
	int dot;
	setlocale(LC_ALL, "rus");
	// матрица смежности графа
	int graph[V][V] =
	{
		//   A  B  C   D  E  F  G  H  I
			{0, 7, 10, 0, 0, 0, 0, 0, 0},
			{7, 0, 0, 0, 0, 9, 27, 0, 0},
			{10, 0, 0, 0, 31, 8, 0, 0, 0},
			{0, 0, 0, 0, 32, 0, 0, 17, 21},
			{0, 0, 31, 32, 0, 0, 0, 0, 0},
			{0, 9, 8, 0, 0, 0, 0, 11, 0},
			{0, 27, 0, 0, 0, 0, 0, 0, 15},
			{0, 0, 0, 17, 0, 11, 0, 0, 15},
			{0, 0, 0, 21, 0, 0, 15, 15, 0},
	};
	// A - 0, B - 1, C - 2, D - 3, 
	// E - 4, F - 5, G - 6, H - 7, I - 8
	start:
	do
	{
		cout << "Введите номер вершины, чтобы получить минимальный путь:\n";
		cout << "Формат ввода: A - 0, B - 1, C - 2, D - 3, E - 4, F - 5, G - 6, H - 7, I - 8" << endl;
		cin >> dot;
		cin.clear();
		cin.ignore(32767, '\n');
	} while (dot < 0 || dot > 8);

	dijkstra(graph, dot);
	int point;
	do
	{
		cout << "Хотите продолжить? (1 - да, 0 и другое - нет)" << endl;
		cin >> point;
		cin.clear();
		cin.ignore(32767, '\n');
	} while (point < 0 || point > 1);
	if (point == 1)
	{
		goto start;
	}
	else
	{
		goto finish;
	}
	
finish:
	return 0;
}
