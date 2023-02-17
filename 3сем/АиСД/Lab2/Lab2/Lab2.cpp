#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <array>

using namespace std;
const int N = 10; 
int i, j;
bool* visited = new bool[N];

//матрица смежности графа
int graph[N][N] =
{
	{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};


void BFS(int start)
{
	queue <int> q; // очередь для хранения номеров вершин
	bool visited[N];
	bool inqueue[N];
	int view_cell; // номер посещаемой вершины
	for (int i = 0; i < N; i++)
	{
		visited[i] = inqueue[i] = false;
	}
	q.push(start);
	visited[start] = inqueue[start] = true; //рассмотрели первую вершину
	while (!q.empty())
	{
		view_cell = q.front(); //обращение к первому элементу очереди
		cout << view_cell + 1 << " ";
		visited[view_cell] = true;
		q.pop();
		for (int i = 0; i < N; i++)
		{
			if (!inqueue[i] && graph[view_cell][i]) //если вершина не в очереди и смежна с текущей
			{
				q.push(i);
				inqueue[i] = true;
			}
		}
	}
}


void DFS(int start)
{
	stack <int> s; // стек для хранения номеров вершин
	bool visited[N]; 
	bool inqueue[N]; 
	int view_cell; // номер посещаемой вершины
	for (int i = 0; i < N; i++)
	{
		visited[i] = inqueue[i] = false;
	}
	s.push(start); // записываем начальную вершину в очередь
	visited[start] = inqueue[start] = true; //рассмотрели первую вершину
	while (!s.empty())
	{
		view_cell = s.top(); //обращение к первому элементу очереди
		cout << view_cell + 1 << " ";

		visited[view_cell] = true;
		s.pop();
		for (int i = 0; i < N; i++)
		{
			if (!inqueue[i] && graph[view_cell][i]) 
			{
				s.push(i);
				inqueue[i] = true;
			}
		}
	}
}

struct Edge
{
	int start;
	int finish;
};

//главная функция
void main() {
	setlocale(LC_ALL, "rus");
	cout << "Список смежности: " << endl;
	vector<Edge> edges =
	{
		{1, 2}, {2, 1}, {1, 5}, {5, 1},
		{2, 7}, {7, 2}, {2, 8}, {8, 2},
		{7, 8}, {8, 7}, {8, 3}, {3, 8},
		{5, 6}, {6, 5}, {4, 6}, {6, 4},
		{4, 9}, {9, 4}, {6, 9}, {9, 6}, 
		{9, 10}, {10, 9}
	};
	int n = 11; 
	vector<vector<int>> adjList; 
	adjList.resize(n); 
	for (auto& edge : edges)
	{
		adjList[edge.start].push_back(edge.finish); 
	}
	for (int i = 1; i < n; i++)
	{
		cout << i << "--> {";
		for (int v : adjList[i]) {
			cout << v << " ";
		}
		cout << "}" << endl;
	}
	cout << endl;
	cout << "Список ребер: " << endl;
	   for (int i = 1; i < n; i++)
	   {
		   for (int v : adjList[i]) {
			   cout << "{" << i<<","<<v<<"}";
		   }
		   cout << endl;
	   }
	cout << endl;
	int start = 1;
	cout << "Матрица смежности графа: " << endl;
	for (i = 0; i < N; i++)
	{
		visited[i] = false;
		for (j = 0; j < N; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << endl;
	cout << "Стартовая вершина: " << start;
	cout << endl;
	cout << "\nПорядок обхода в глубину: ";
	DFS(start - 1);
	delete[]visited;
	cout << "\n\nПорядок обхода в ширину: ";
	BFS(start - 1);
	cout << endl;
	cout << "Расчёт О-большое: " << endl;
	int v, e;
	cin >> v >> e;
	cout << "O(|V| + |E|) = " << abs(v) + abs(e) << endl;
}