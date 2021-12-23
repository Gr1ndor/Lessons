#include <iostream>

int main()
{
    // 1 task 
    float a{ 0 }, b{ 0 };
    std::cout << "Enter 2 numbers" << std::endl;
    std::cin >> a, b;
    if ((a + b >= 10) && (a + b <= 20))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    
    // 2 tak
    int x{ 10 }, y{ 10 };
    if ((x == y && y == 10) || (x + y == 10))
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    
    // 3 task
    for (size_t i = 1; i < 50; i+=2)
    {
        std::cout << i << " ";
    }
    
    // 4 task
    int simple{ 4 }, count{ 3 }, n = simple;
    if (simple % 2 == 0 && simple != 2)
    {
        std::cout << "False" << std::endl;
    }
    else
    {
        while (true)
        {
            if (count > n || simple == 3)
            {
                std::cout << "True" << std::endl;
                break;
            }
            if (simple % count == 0)
            {
                std::cout << "False" << std::endl;
                break;
            }
            n = simple / count;
            count += 2;
        }
    }
    
    //task 5
    unsigned short year{ 0 };
    std::cout << "Enter year: ";
    std::cin >> year;
    if (((year % 100 == 0) && (year % 400 != 0)) || (year % 4 != 0))
        std::cout << "False" << std::endl;
    else
        std::cout << "True" << std::endl;

    return 0;