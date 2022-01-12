#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#define SwapINT(a, b) int c = a; a = b; b = c;

#pragma pack(push, 1)
struct employee
{
	std::string name;
	size_t age;
	bool married;
};
#pragma pack(pop)
namespace MySpace
{
	void arrInit(float* arr, const size_t length)
	{
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = (rand() % 1000 - 500) / 10.0;
		}
	}
	void arrCout(const float* arr, const size_t length)
	{
		for (size_t i = 0; i < length; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
	}
	void arrTask(const float* arr, const size_t length)
	{
		int pos = 0;
		int neg = 0;
		for (size_t i = 0; i < length; i++)
		{
			(arr[i] < 0) ? (neg++) : (pos++);
		}
		std::cout << "Positive = " << pos << std::endl;
		std::cout << "Negative = " << neg << std::endl;
	}
}
void arr2Init(int* arr, const size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "Enter element of array " << i+1 << ' ';
		std::cin >> arr[i];
	}
}
void arrSort(int* arr, const size_t length)
{
	for (size_t i = 0; i < (length - 1); i++)
	{
		for (size_t j = 0; j < (length - 1); j++)
		{
			if (arr[j] > arr[j+1])
			{
				SwapINT(arr[j], arr[j + 1]);
			}
		}
	}
}
void arrCout(const int* arr, const size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}
void structTask()
{
	employee* emp = new employee;
	emp->age = 25;
	emp->married = false;
	emp->name = "John";
	std::cout << "Name: " << emp->name<< std::endl;
	std::cout << "Age: " << emp->age<< std::endl;
	std::cout << "Married: " << emp->married << std::endl;
	std::cout << "Size: " << sizeof(emp) << std::endl;
	std::ofstream file("a.txt");
	file << emp->name << " " << emp->age << " " << emp->married << std::endl;
	file.close();
	delete emp;
}