#include <iostream>
#include <chrono>
#include <random>
#include <stdlib.h>

using namespace std;

enum box : char
{
    CROSS = 'X',
    ZERO = 'O',
    EMPTY = '_'
};
enum progress
{
    ON,
    HUM_WIN,
    AI_WIN,
    DRAW
};
struct coors
{
    size_t x;
    size_t y;
};
struct game
{
    box** ppField{ nullptr };
    const size_t size = 3;
    size_t turn = 0;
    progress pr{ ON };
    box hum;
    box ai;
};

int32_t getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}
void initGame(game& g)
{
    g.ppField = new box * [g.size];
    for (size_t i = 0; i < g.size; i++)
    {
        g.ppField[i] = new box [g.size];
    }
    for (size_t x = 0; x < g.size; x++)
    {
        for (size_t y = 0; y < g.size; y++)
        {
            g.ppField[x][y] = EMPTY;
        }
    }
    if (getRandomNum(0, 1000) > 500)
    {
        g.hum = CROSS;
        g.ai = ZERO;
    }
    else
    {
        g.hum = ZERO;
        g.ai = CROSS;
        g.turn = 1;
    }
}
void clearScr()
{
    std::cout << "\x1B[2J\x1B[H";
}
void printGame(game& g)
{
    cout << "    ";
    for (size_t y = 0; y < g.size; y++)
    {
        cout << y + 1 << "   ";
    }
    cout << endl;
    for (size_t x = 0; x < g.size; x++)
    {
        cout << x + 1 << " | ";
        for (size_t y = 0; y < g.size; y++)
        {
            cout << g.ppField[x][y] << " | ";
        }
        cout << endl;
    }
    cout << "Human: " << g.hum << endl << "AI: " << g.ai << endl;
}
void deleteGame(game& g)
{
    for (size_t i = 0; i < g.size; i++)
    {
        delete[] g.ppField[i];
    }
    delete[] g.ppField;
    g.ppField = nullptr;
}
progress checkGame(game& g)
{
    for (size_t x = 0; x < g.size; x++)
    {
        if (g.ppField[x][0] == g.ppField[x][1] && g.ppField[x][0] == g.ppField[x][2])
        {
            if (g.ppField[x][0] == g.hum)
            {
                return HUM_WIN;
            }
            if (g.ppField[x][0] == g.ai)
            {
                return AI_WIN;
            }
        }
    }
    for (size_t y = 0; y < g.size; y++)
    {
        if (g.ppField[0][y] == g.ppField[1][y] && g.ppField[0][y] == g.ppField[2][y])
        {
            if (g.ppField[0][y] == g.hum)
            {
                return HUM_WIN;
            }
            if (g.ppField[0][y] == g.ai)
            {
                return AI_WIN;
            }
        }
    }
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[2][2])
    {
        if (g.ppField[0][0] == g.hum)
        {
            return HUM_WIN;
        }
        if (g.ppField[0][0] == g.ai)
        {
            return AI_WIN;
        }
    }
    if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[0][2])
    {
        if (g.ppField[1][1] == g.hum)
        {
            return HUM_WIN;
        }
        if (g.ppField[1][1] == g.ai)
        {
            return AI_WIN;
        }
    }
    bool draw{ true };
    for (size_t x = 0; x < g.size; x++)
    {
        for (size_t y = 0; y < g.size; y++)
        {
            if (g.ppField[x][y] == EMPTY)
            {
                draw = false;
                break;
            }
            if (!draw)
            {
                break;
            }
        }
    }
    if (draw)
    {

        return DRAW;
    }
    return ON;
}
coors humCoors(game& g)
{
    coors c;
    do
    {
        cout << "Enter x (1..3): ";
        cin >> c.x;
        cout << "Enter y (1..3): ";
        cin >> c.y;
        c.x--;
        c.y--;
    } while (c.x > 2 || c.y > 2 || g.ppField[c.x][c.y] != EMPTY);
    return c;
}
coors aiCoors(game& g)
{
    for (size_t x = 0; x < g.size; x++)
    {
        for (size_t y = 0; y < g.size; y++)
        {
            if (g.ppField[x][y] == EMPTY)
            {
                g.ppField[x][y] = g.ai;
                if (checkGame(g) == AI_WIN)
                {
                    g.ppField[x][y] = EMPTY;
                    return { x, y };
                }
                g.ppField[x][y] = EMPTY;
            }
        }
    }
    for (size_t x = 0; x < g.size; x++)
    {
        for (size_t y = 0; y < g.size; y++)
        {
            if (g.ppField[x][y] == EMPTY)
            {
                g.ppField[x][y] = g.hum;
                if (checkGame(g) == HUM_WIN)
                {
                    g.ppField[x][y] = EMPTY;
                    return { x, y };
                }
                g.ppField[x][y] = EMPTY;
            }
        }
    }
    if (g.ppField[1][1] == EMPTY)
    {
        return { 1, 1 };
    }
    if (g.ppField[0][0] == EMPTY)
    {
        return { 0, 0 };
    }
    if (g.ppField[2][2] == EMPTY)
    {
        return { 2, 2 };
    }
    if (g.ppField[0][2] == EMPTY)
    {
        return { 0, 2 };
    }
    if (g.ppField[2][0] == EMPTY)
    {
        return { 2, 0 };
    }
    if (g.ppField[0][1] == EMPTY)
    {
        return { 0, 1 };
    }
    if (g.ppField[1][0] == EMPTY)
    {
        return { 1, 0 };
    }
    if (g.ppField[1][2] == EMPTY)
    {
        return { 1, 2 };
    }
    if (g.ppField[2][1] == EMPTY)
    {
        return { 2, 1 };
    }
}
void win(game& g)
{
    cout << endl;
    if (g.pr == HUM_WIN)
    {
        cout << "Player win" << endl;
        return;
    }
    if (g.pr == AI_WIN)
    {
        cout << "AI win" << endl;
        return;
    }
    else
    {
        cout << "DRAW" << endl;
    }
    return;
}

int main()
{
    game g;
    initGame(g);
    clearScr();
    printGame(g);
    do
    {
        if (g.turn % 2 == 0)
        {
            coors c = humCoors(g);
            g.ppField[c.x][c.y] = g.hum;
        }
        else
        {
            coors c = aiCoors(g);
            g.ppField[c.x][c.y] = g.ai;
        }
        clearScr();
        printGame(g);
        g.turn++;
        g.pr = checkGame(g);
    } while (g.pr == ON);
    deleteGame(g);
    win(g);
    return 0;
}