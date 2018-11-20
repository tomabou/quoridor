#include "board.h"

board::board(int i)
{
    this->v = std::vector<int>((i - 1) * (i - 1), 0);
    this->size = i;
}

void board::put_wall(int a, int b, int x)
{
    if (a < 0 || a >= this->size - 1 || b < 0 || b >= this->size - 1)
    {
        return;
    }
    this->v[a * (this->size - 1) + b] = x;
}

void board::show()
{
    for (int j = 0; j < this->size * 2 + 1; j++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int i = 0; i < this->size; i++)
    {
        std::cout << "#";
        for (int j = 0; j < this->size - 1; j++)
        {
            int w1 = get_wall(i, j);
            int w2 = get_wall(i - 1, j);
            char pos = (w1 == 1 || w2 == 1) ? '|' : ' ';
            std::cout << ' ' << pos;
        }
        std::cout << " #" << std::endl;
        if (i == this->size - 1)
        {
            break;
        }
        std::cout << "#";
        for (int j = 0; j < this->size; j++)
        {
            int w1 = get_wall(i, j);
            int w2 = get_wall(i, j - 1);
            char pos = (w1 == 2 || w2 == 2) ? '-' : ' ';
            std::cout << pos << (j == this->size - 1 ? '#' : '*');
        }
        std::cout << std::endl;
    }
    for (int j = 0; j < this->size * 2 + 1; j++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
}

int board::get_wall(int a, int b)
{
    if (a < 0 || a >= this->size - 1 || b < 0 || b >= this->size - 1)
    {
        return 0;
    }
    return this->v[a * (this->size - 1) + b];
}