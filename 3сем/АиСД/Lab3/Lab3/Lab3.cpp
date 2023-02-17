#include <iostream>

#define V 9

using namespace std;


// ������� ��� ������ ������� � ����������� ����������� �� ��������� ������, ������� ��� �� �������� � ���������� ����
int minDistance(int dist[], bool sptSet[])
{
	// �������������� ����������� ���������� ��� �������������
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// �����
void printSolution(int dist[])
{
	cout << "������� \t ��������� �� �������� �������" << endl;

	char str[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
	for (int i = 0; i < V; i++)
		cout << "�� ������� " << str[i] << " \t\t " << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // �������� ���������� ���������� �� src �� i

	bool sptSet[V]; // sptSet[i] ����� true, ���� ������� i �������� � ���������� ����

	// ������������� ���� ���������� ��� ������������� � sptSet[] ��� false
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// ���������� �� ��������� �� ������ ���� ������ ����� 0
	dist[src] = 0;

	// ������� ���������� ���� ��� ���� ������
	for (int count = 0; count < V - 1; count++)
	{
		// �������� ������� � ����������� ����������� �� ��������� ������, ������� ��� �� �������� � ���������� ����
		int u = minDistance(dist, sptSet);

		// ��������� ��������� ������� � ���������� ����
		sptSet[u] = true;

		// ��������� �������� ���������� �������� ������ ��������� �������
		for (int v = 0; v < V; v++)

			// ��������� dist[v] ������ ���� �� � sptSet, ���� ����� �� u �� v, � ��� ����� ������ �������� �������� dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// ����� ����������� ���������� �� ���� ������
	printSolution(dist);
}

int main()
{
	int dot;
	setlocale(LC_ALL, "rus");
	// ������� ��������� �����
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
		cout << "������� ����� �������, ����� �������� ����������� ����:\n";
		cout << "������ �����: A - 0, B - 1, C - 2, D - 3, E - 4, F - 5, G - 6, H - 7, I - 8" << endl;
		cin >> dot;
		cin.clear();
		cin.ignore(32767, '\n');
	} while (dot < 0 || dot > 8);

	dijkstra(graph, dot);
	int point;
	do
	{
		cout << "������ ����������? (1 - ��, 0 � ������ - ���)" << endl;
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
