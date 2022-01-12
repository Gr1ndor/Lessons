#include <iostream>
#include "mylib.h"

#define CHECK(x, y) (((x<y)&&(x>=0)) ? (true) : (false))
#define length 10

int main()
{
    //task 1 + 5
    float arr[length]{0};
    MySpace::arrInit(arr, length);
    MySpace::arrCout(arr, length);
    MySpace::arrTask(arr, length);
    //task 2
    int x = 0, y = 0;
    std::cout << "Enter number ";
    std::cin >> x;
    std::cout << "Enter max number ";
    std::cin >> y;
    if (CHECK(x,y))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    //task 3
    int arr2[length]{ 0 };
    arr2Init(arr2, length);
    arrSort(arr2, length);
    arrCout(arr2, length);
    //task 4
    structTask();
}