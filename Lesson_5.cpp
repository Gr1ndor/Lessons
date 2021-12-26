#include <iostream>

void task1(double*, size_t);
void cout(int*, size_t);
void task2(int*, size_t);
void task3(int*, size_t);
void task4(int*, int&, int);
void left(int*, int);
void right(int*, int);
bool task5(int*, int);

int main()
{
	const size_t length = 8;
	double arr1[length]{ 1.2, 3, 4, 5.6, 7.981, 5, 7, 12.98 };
	task1(arr1, length);

	int arr2[length]{ 0, 0, 0, 1, 1, 1, 0, 0 };
	cout(arr2, length);
	task2(arr2, length);
	cout(arr2, length);

	int arr3[length]{ 0 };
	task3(arr3, length);
	cout(arr3, length);

	int arr4[length]{ 1, 2, 3, 4, 5, 6, 7, 8 };
	int n = -5;
	task4(arr4, n, length);
	cout(arr4, length);

	int arr5[5]{ 10, 1, 2, 3, 4 };
	if (task5(arr5, 5))
	{
		std::cout << "Balance";
	}
	else
	{
		std::cout << "No balance";
	}
	return 0;
}

void task1(double* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	return;
}

void cout(int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	return;
}

void task2(int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == 1)
			arr[i] = 0;
		else
			arr[i] = 1;
	}
	return;
}

void task3(int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = i * 3 + 1;
	}
	return;
}

void task4(int* arr, int& n, int length)
{
	std::cout << length << std::endl;
	while (n > 0)
	{
		right(arr, length);
		n--;
	}
	while (n < 0)
	{
		left(arr, length);
		n++;
	}
	return;
}

void left(int* arr, int length)
{
	int t = arr[0];
	length--;
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[length] = t;
	return;
}

void right(int* arr, int length)
{
	length--;
	int t = arr[length];
	for (size_t i = length; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = t;
	return;
}

bool task5(int* arr, int length)
{
	int sum1 = 0;
	int sum2 = 0;
	int i = 0;
	length--;
	while (i != length)
	{
		
		if (sum2 > sum1)
		{
			sum1 += arr[i];
			i++;
		}
		else
		{
			sum2 += arr[length];
			length--;
		}
	}
	if (sum2 > sum1)
		sum1 += arr[i];
	else
		sum2 += arr[i];
	return (sum1 == sum2);
}