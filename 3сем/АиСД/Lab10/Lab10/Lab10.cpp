#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <ctime>

using namespace std;

#define MAX_DIST 100

typedef vector<vector<int>> Matrix;
typedef vector<int> Path;

struct Way
{
	Path way;
	size_t dist;

	size_t length()
	{
		return way.size();
	}

	void clear()
	{
		way.clear();
	}

	void push_back(int value)
	{
		way.push_back(value);
	}

	Way()
	{
		this->dist = 0;
	}

	string to_string()
	{
		string text = "Путь: ";

		for (auto i : way)
		{
			text += std::to_string(i) + " -> ";
		}

		text += "\nДлина пути : " + std::to_string(this->dist) + "\n";

		return text;
	}
};

Matrix createMatrix(size_t N, size_t spread = 100);

void fillPheramons(Matrix& matrix);

void outputMatrix(Matrix matrix);

Way antAlgorithm(
	Matrix& graph,
	Matrix& pheramons,
	size_t nIters = 100,
	size_t alpha = 1,
	size_t beta = 1,
	size_t start = 0
);

///////////////////////////////////////

void main()
{
	setlocale(LC_ALL, "Ru");
	size_t nIters = 100;
	size_t N;
	cout << "Введите кол-во городов: ";
	cin >> N;
	Matrix cities = createMatrix(N);
	outputMatrix(cities);

	Matrix pheromons = cities;
	fillPheramons(pheromons);

	Way way = antAlgorithm(cities, pheromons, nIters, 2, 2, 0);

	cout << way.to_string();
}

///////////////////////////////////////

void fillAll(vector<bool>& path, size_t N)
{
	for (size_t i = 0; i < N; i++)
	{
		path.push_back(true);
	}
}

void fillPropabs(
	Matrix& graph,
	Matrix& pheramons,
	vector<double>& propabs,
	vector<bool> notv,
	size_t alpha,
	size_t beta,
	size_t current)
{
	double sum = 0.0;
	propabs.resize(graph.size());
	for (size_t i = 0; i < notv.size(); i++)
	{
		if (notv[i] && i != current)
		{
			sum += pow(1.1 / (double)graph[current][i], alpha) * pow((double)pheramons[current][i], beta);
		}
	}

	for (size_t i = 0; i < propabs.size(); i++)
	{
		if (notv[i])
		{
			propabs[i] = 100.0 * pow(1.1 / (double)graph[current][i], alpha) * pow((double)pheramons[current][i], beta) / sum;
		}
		else
		{
			propabs[i] = 0;
		}
	}
}

size_t makeChoise(vector<double> propabs)
{
	srand(time(NULL));
	size_t answer = 0;
	size_t random = rand() % 100 + 1;
	double sum = 0.0;

	for (size_t i = 0; i < propabs.size(); i++)
	{
		if (propabs[i] == 0) continue;

		sum += propabs[i];
		if (sum >= random)
		{
			answer = i;
			break;
		}
	}

	return answer;
}

Way antAlgorithm(
	Matrix& graph,
	Matrix& pheramons,
	size_t nIters,
	size_t alpha,
	size_t beta,
	size_t start
)
{
	Way way;
	Way best;
	best.dist = INT_MAX;

	vector<bool> notv;
	vector<double> propabs;

	size_t current = start;
	size_t to;
	size_t i = 0;

	fillAll(notv, graph.size());

	way.push_back(current);

	while (i < nIters)
	{
		propabs.clear();
		notv[current] = false;
		fillPropabs(graph, pheramons, propabs, notv, alpha, beta, current);

		if (find(notv.begin(), notv.end(), true) == notv.end())
		{
			if (way.dist < best.dist)
			{
				best = way;
			}

			way.clear();
			way.dist = 0;
			current = start;

			way.push_back(current);
			notv.clear();
			fillAll(notv, graph.size());
			i++;
		}
		else
		{
			to = makeChoise(propabs);
			way.dist += graph[current][to];
			current = to;
			way.push_back(current);
		}
	}
	return best;
}

Matrix createMatrix(size_t N, size_t spread)
{
	Matrix matrix;
	matrix.resize(N);
	srand(time(NULL));

	for (auto& i : matrix)
	{
		i.resize(N);
	}

	for (size_t i = 0; i < N; i++)
	{
		matrix[i][i] = 0;

		for (size_t j = i + 1; j < N; j++)
		{
			matrix[i][j] = matrix[j][i] = rand() % MAX_DIST + 1;
		}
	}

	return matrix;
}

void fillPheramons(Matrix& matrix)
{
	for (auto& i : matrix)
	{
		for (auto& el : i)
		{
			if (el < (double)MAX_DIST * 0.25)
			{
				el = (double)MAX_DIST * 0.25;
			}
			else if (el < (double)MAX_DIST * 0.5)
			{
				el = (double)MAX_DIST * 0.5;
			}
			else if (el < (double)MAX_DIST * 0.75)
			{
				el = (double)MAX_DIST * 0.75;
			}
			else
			{
				el = (double)MAX_DIST;
			}
		}
	}
}

void outputMatrix(Matrix matrix)
{
	for (auto i : matrix)
	{
		for (auto el : i)
		{
			cout << el << "\t";
		}
		cout << endl;
	}
}