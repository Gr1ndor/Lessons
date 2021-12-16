#include <iostream>

enum CrossZero
{
    empty, cross, zero
};

struct Field
{
    char name1[20] = "FirstPlayer", name2[20] = "SecondPlayer", winner[20] = "NoOne";
    unsigned short int turnNum = 0; 
    bool endGame = 0; // если игра закончилась, то правда, иначе ложь
    CrossZero play1 = cross, play2 = zero;
};

union MyData
{
    int in;
    float fl;
    char ch;
};

struct MyVariant
{
    MyData data;
    unsigned int isInt : 1 , isFloat : 1, isChar : 1;
};


int main()
{
    short int a = 123'456;
    int b = 123'456'789;
    long long c = 123'456'789'000;
    char d = 'd';
    bool e = true;
    float f = 1.23f;
    double g = 1.234'567;

    CrossZero game1[3][3]{ empty, empty, empty, empty, empty, empty, empty, empty, empty };

    MyVariant m{'L',0,0,1};
    std::cout << m.data.in << ' ' << m.data.ch << ' ' << m.data.fl << std::endl;
    std::cout << m.isInt << ' ' << m.isFloat << ' ' << m.isChar << std::endl;
    m.data.in = 123;
    m.isChar = 0;
    m.isInt = 1;
    std::cout << m.data.in << ' ' << m.data.ch << ' ' << m.data.fl << std::endl;
    std::cout << m.isInt << ' ' << m.isFloat << ' ' << m.isChar << std::endl;

    return 0;
}