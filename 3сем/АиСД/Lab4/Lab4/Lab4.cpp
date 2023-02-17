#include <iostream>
#include <Windows.h>
using namespace std;

void Floud();
void ShowTables();


int D[6][6]
{
//	 1   2   3   4   5   6
    {0, 28, 21, 59, 12, 27},
    {7, 0, 24, INT_MAX, 21, 9 },
    {9, 32, 0, 13, 11, INT_MAX},
    {8, INT_MAX, 5, 0, 16, INT_MAX},
    {14, 13, 15, 10, 0, 22},
    {15, 18, INT_MAX, INT_MAX, 6, 0}
};

int S[6][6]
{
//   1  2  3  4  5  6
    {0, 2, 3, 4, 5, 6},
    {1, 0, 3, 4, 5, 6},
    {1, 2, 0, 4, 5, 6},
    {1, 2, 3, 0, 5, 6},
    {1, 2, 3, 4, 0, 6},
    {1, 2, 3, 4, 5, 0}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Floud();
    ShowTables();
}

void Floud()
{
    for (int m = 0; m < 6; m++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (D[i][j] > D[i][m] + D[m][j])
                {
                    D[i][j] = D[i][m] + D[m][j];
                    S[i][j] = S[i][m];
                }
            }
        }
    }
}

void ShowTables()
{
    cout << "Длины:\n";
    cout << "\t1\t2\t3\t4\t5\t6\t\n";
    cout << "----------------------------------------------------------\n";
    for (int i = 0; i < 6; i++)
    {
		cout << i + 1 << "|\t";
        for (int j = 0; j < 6; j++)
        {
            cout << D[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n\nМатрица 'пути'\n";
	cout << "\t1\t2\t3\t4\t5\t6\t\n";
    cout << "----------------------------------------------------------\n";
    for (int i = 0; i < 6; i++)
    {
		cout << i + 1 << "|\t";
        for (int j = 0; j < 6; j++)
        {
            cout << S[i][j] << "\t";
        }
        cout << "\n";
    }
}





