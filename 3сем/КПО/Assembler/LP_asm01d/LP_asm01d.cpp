#include<iostream>

extern "C"
{
	int getmax(int* arr, int size)
	{
		int max = 0;
		for (int i = 0; i < size; i++)
		{
			if (max < arr[i]) max = arr[i];
		}
		return max;
	}

	int getmin(int* arr, int size)
	{
		int min = 0;
		for (int i = 0; i < size; i++)
		{
			if (min > arr[i]) min = arr[i];
		}
		return min;
	}
	void get_pause()
	{
		system("pause");
	}
}