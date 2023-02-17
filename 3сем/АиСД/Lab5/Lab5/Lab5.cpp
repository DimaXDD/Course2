#include <iostream>
#include <vector>
#include <algorithm>

#define V 8

using namespace std;

#pragma region Prima

bool checker(vector<int> vstd, int check)
{
	for (int g = 0; g < vstd.size(); g++)
		if (check == vstd[g])
			return true;
	return false;
}

void primMST(int graph[V][V])
{
	int result[8][8] = {};

	std::vector<int> visited;

	visited.push_back(0); // добавляем начальную точку

	int weight = INT_MAX; //вес
	int VisitNow; // номер посещяемого в масииве посещённых
	int FromPoint; // из какой точки соединяем

	while (visited.size() != 8)
	{
		VisitNow = INT_MAX;
		FromPoint = INT_MAX;
		weight = INT_MAX;
		for (int a = 0; a < visited.size(); a++) {
			for (int i = 0; i < 8; i++) {
				if (graph[visited[a]][i] < weight && checker(visited, i) == false) {
					weight = graph[visited[a]][i];
					VisitNow = i;
					FromPoint = visited[a];
				}
			};
		};
		if (VisitNow != INT_MAX && FromPoint != INT_MAX) {
			result[FromPoint][VisitNow] = weight;
			visited.push_back(VisitNow);
		}
	}

	int sum = 0;
	cout << "Вершины \t\t Вес ребра" << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if (result[i][j] != NULL) {
				cout << i + 1 << " -> " << j + 1 << " \t\t\t " << result[i][j] << "\n";
				sum += result[i][j];
			}
	}
	cout << "\nВес минимального остовного дерева: " << sum << endl;
}


#pragma endregion

#pragma region Kruskal
struct Node // Сохранить график как структуру данных
{
	int start;
	int end;
	int length;
};
bool compare(Node a, Node b) // Сравнить длину ребер
{
	return a.length < b.length;
}
void Kruskal(vector<Node>& arr, vector<Node>& arr2, vector<bool>& visited)
{
	int M, N;
	M = visited.size();
	N = arr.size();
	// Заполнить массив данными
	arr[0].start = 0; arr[0].end = 1; arr[0].length = 2;
	arr[1].start = 0; arr[1].end = 3; arr[1].length = 8;
	arr[2].start = 0; arr[2].end = 4; arr[2].length = 2;
	arr[3].start = 1; arr[3].end = 3; arr[3].length = 10;
	arr[4].start = 1; arr[4].end = 2; arr[4].length = 3;
	arr[5].start = 1; arr[5].end = 4; arr[5].length = 5;
	arr[6].start = 2; arr[6].end = 4; arr[6].length = 12;
	arr[7].start = 2; arr[7].end = 7; arr[7].length = 7;
	arr[8].start = 3; arr[8].end = 5; arr[8].length = 3;
	arr[9].start = 3; arr[9].end = 4; arr[9].length = 14;
	arr[10].start = 3; arr[10].end = 6; arr[10].length = 1;
	arr[11].start = 4; arr[11].end = 5; arr[11].length = 11;
	arr[12].start = 4; arr[12].end = 6; arr[12].length = 4;
	arr[13].start = 4; arr[13].end = 7; arr[13].length = 8;
	arr[14].start = 5; arr[14].end = 6; arr[14].length = 6;
	arr[15].start = 6; arr[15].end = 7; arr[15].length = 9;

	sort(arr.begin(), arr.end(), compare); // Сортировать ребра по весу
	int weight = 0;
	cout << "Вершины \t\t Вес ребра" << endl;

	for (int i = 0; i < N; i++) // Перебрать все ребра
	{
		if (!visited[arr[i].start] || !visited[arr[i].end]) // Если вершина не посещена
		{
			weight += arr[i].length; // Добавить вес ребра к общему весу
			visited[arr[i].start] = true; // Пометить вершину как посещенную
			visited[arr[i].end] = true;
			cout << arr[i].start + 1 << " -> " << arr[i].end + 1 << " \t\t\t " << arr[i].length << endl;
			arr2[i].start = arr[i].start; // Сохранить ребро в новый массив
			arr2[i].end = arr[i].end;
			arr2[i].length = arr[i].length;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (arr2[i].length == 0)
		{
			cout << arr[i].start + 1 << " -> " << arr[i].end + 1 << " \t\t\t " << arr[i].length << endl;
			weight += arr[i].length;
			break;
		}
	}

	cout << "\nВес минимального остовного дерева: " << weight << endl;
}
#pragma endregion

int main()
{
	setlocale(LC_ALL, "rus");
	int N = 16; // Количество ребер
	int graph[V][V] =
	{
		 {INT_MAX , 2  ,INT_MAX ,8   ,2   ,INT_MAX ,INT_MAX ,INT_MAX}, //v0
		 {2   ,INT_MAX ,3   ,10  ,5   ,INT_MAX ,INT_MAX ,INT_MAX}, //v1
		 {INT_MAX ,3   ,INT_MAX ,INT_MAX ,12  ,INT_MAX ,INT_MAX ,7},   //v2
		 {8   ,10  ,INT_MAX ,INT_MAX ,14  ,3   ,1   ,INT_MAX}, //v3
		 {2   ,5   ,12  ,14  ,INT_MAX ,11  ,4   ,8},   //v4
		 {INT_MAX ,INT_MAX ,INT_MAX ,3   ,11  ,INT_MAX ,6   ,INT_MAX}, //v5
		 {INT_MAX ,INT_MAX ,INT_MAX ,1   ,4   ,6   ,INT_MAX ,9},   //v6
		 {INT_MAX ,INT_MAX ,7   ,INT_MAX ,8   ,INT_MAX ,9   ,INT_MAX}, //v7
	};

	cout << "Алгоритм Прима:" << endl;
	primMST(graph);

	vector<Node> arr(N);
	vector<Node> arr2(N);
	vector<bool> visited(V);
	cout << "\nАлгоритм Краскала:" << endl;
	Kruskal(arr, arr2, visited);

	cout << "\nЦикломатическое число: " << N - V + 1 << endl;

	return 0;
}