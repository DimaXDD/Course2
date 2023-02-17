#include <iostream>
using namespace std;

void hanoi_tower(int n, int from, int to)
{
	if (n == 1) {
		cout << "Переложить диск с " << from << " на " << to << endl;
	} else {
		int temp = 6 - from - to;
		hanoi_tower(n - 1, from, temp);
		cout << "Переложить диск с " << from << " на " << to << endl;
		hanoi_tower(n - 1, temp, to);
	}
}

void transform_disk(int y)
{
	int temp = y;
	int count = 0;
	while (temp > 0) {
		temp /= 10;
		count++;
	}

	int* arr = new int[count];
	for (int i = 0; i < count; i++) {
		arr[i] = y % 10;
		y /= 10;
	}
}

void transform_tower(int x)
{
	int temp = x;
	int count = 0;
	while (temp > 0) {
		temp /= 10;
		count++;
	}

	int* arr = new int[count];
	for (int i = 0; i < count; i++) {
		arr[i] = x % 10;
		x /= 10;
	}

	for (int i = count - 1; i >= 0; i--) {
		if (arr[i] > 3)
		{
			cout << "После урезания 0, осталось число " << arr[i] << ", оно больше 3, введите корректно" << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, from, to;
	
    do
    {
        cout << "Введите кол-во дисков: ";
        cin >> n;
        cin.clear();
        cin.ignore(32767, '\n');
		transform_disk(n);
    } while (n <= 0);

	do
	{
		cout << "Введите стержень, с которого нужно переместить: ";
		cin >> from;
		cin.clear();
		cin.ignore(32767, '\n');
		transform_tower(from);
	} while (from <= 0 || from > 3);
	
	do
	{
		cout << "Введите номер стержня, на который нужно переместить: ";
		cin >> to;
		cin.clear();
		cin.ignore(32767, '\n');
		transform_tower(to);
	} while (to <= 0 || to > 3);
	
	hanoi_tower(n, from, to);
	return 0;
}