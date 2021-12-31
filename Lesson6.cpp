#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

int getMArr(int*&);
void initArr(int*, const int);
void coutArr(int*, const int);
void getMemMatrix(int**&, const int, const int);
void delMatrix(int**, const int, const int);
void initMatrix(int**, const int, const int);
void coutMatrix(int**, const int, const int);
void unionFile(std::string, std::string);
void findWord();

int main()
{
    //task 1
    int length = 0;
    int* arr;
    length = getMArr(arr);
    if (arr != nullptr)
    {
        initArr(arr, length);
        coutArr(arr, length);
    }
    else
        std::cerr << "Bad allocate" << std::endl;
    delete[] arr;
    arr = nullptr;
    //task 2
    int** matrix;
    const int x = 4, y = 4;
    getMemMatrix(matrix, x, y);
    initMatrix(matrix, x, y);
    coutMatrix(matrix, x, y);
    delMatrix(matrix, x, y);
    //tak 3
    std::string name1, name2;
    std::cout << "Enter name first file" << std::endl;
    std::cin >> name1;
    std::cout << "Enter name second file" << std::endl;
    std::cin >> name2;
    std::ofstream f1(name1);
    std::ofstream f2(name2);
    for (size_t i = 0; i < 50; i++)
    {
        f1 << i << ' ';
        f2 << i + 50 << ' ';
    }
    f1.close();
    f2.close();
    //task 4
    unionFile(name1, name2);
    //task 5
    findWord();
    return 0;
}

int getMArr(int*& arr)
{
    int n = 0;
    std::cout << "Enter size array" << std::endl;
    std::cin >> n;
    if (n > 0)
        arr = new (std::nothrow) int[n];
    else
        std::cerr << "Invalid array size" << std::endl;
    return n;
}
void initArr(int* arr, const int length)
{
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = pow(2, i);
    }
}
void coutArr(int* arr, const int length)
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
void getMemMatrix(int**& matrix, int x, int y)
{
    matrix = new  int *[x];
    for (size_t i = 0; i < x; i++)
    {
        matrix[i] = new  int[y];
    }
}
void delMatrix(int** matrix, const int x, const int y)
{
    for (size_t i = 0; i < x; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void initMatrix(int** matrix, const int x, const int y)
{
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}
void coutMatrix(int** matrix, const int x, const int y)
{
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
void unionFile(std::string name1, std::string name2)
{
    std::ofstream f3("c.txt");
    std::ifstream f1(name1);
    std::ifstream f2(name2);
    if (f1.is_open() && f2.is_open() && f3.is_open())
    {
        std::string buf;
        while (!f1.eof())
        {
            getline(f1, buf);
            f3 << buf;
        }
        f3 << std::endl;
        while (!f2.eof())
        {
            getline(f2, buf);
            f3 << buf;
        }
    }
    else
        std::cerr << "Cant open file" << std::endl;
    f1.close();
    f2.close();
    f3.close();
    return;
}
void findWord()
{
    std::string name, word;
    std::cout << "Enter name file" << std::endl;
    std::cin >> name;
    std::cout << "Enter word" << std::endl;
    std::cin >> word;
    std::ifstream fin(name);
    bool check = false;
    if (fin.is_open())
    {
        std::string buf;
        while (!fin.eof())
        {
            getline(fin, buf);
            if (buf.find(word) != std::string::npos)
            {
                check = true;
                std::cout << "Word was found" << std::endl;
                return;
            }
        }
    }
    else
        std::cerr << "Cant open file" << std::endl;
    if (!check)
    {
        std::cout << "Word was not found" << std::endl;
    }
    fin.close();
    return;
}