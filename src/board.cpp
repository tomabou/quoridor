#include "board.h"

char board::get_porn_exp(int a, int b)
{
    if (this->porn[0] == a * this->size + b)
    {
        return 'A';
    }
    if (this->porn[1] == a * this->size + b)
    {
        return 'B';
    }
    return ' ';
}

board::board(int i)
{
    this->v = std::vector<int>((i - 1) * (i - 1), 0);
    this->temp = std::vector<int>(i * i, 0);
    this->size = i;
    this->porn[0] = i / 2;
    this->porn[1] = i * i - i / 2 - 1;
}

void board::put_wall(int a, int b, int x)
{
    if (a < 0 || a >= this->size - 1 || b < 0 || b >= this->size - 1)
    {
        return;
    }
    this->v[a * (this->size - 1) + b] = x;
    this->wall[this->turn]--;
    this->turn = 1 - this->turn;
}

bool board::can_put(int a, int b, int vh)
{
    if (a < 0 || a >= this->size - 1 || b < 0 || b >= this->size - 1)
    {
        return false;
    }
    if (this->wall[this->turn] == 0)
    {
        return false;
    }
    if (this->v[a * (this->size - 1) + b] != 0)
    {
        return false;
    }
    this->v[a * (this->size - 1) + b] = vh;
    if (this->min_length(this->porn[0], 0) == 100)
    {
        this->v[a * (this->size - 1) + b] = 0;
        return false;
    }
    if (this->min_length(this->porn[1], 1) == 100)
    {
        this->v[a * (this->size - 1) + b] = 0;
        return false;
    }
    this->v[a * (this->size - 1) + b] = 0;
    return true;
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
            int w1 = board::get_wall(i, j);
            int w2 = board::get_wall(i - 1, j);
            char pos = (w1 == 1 || w2 == 1) ? '|' : ' ';
            std::cout << get_porn_exp(i, j) << pos;
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
            char pos = (w1 == 2 || w2 == 2) ? '=' : ' ';
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

void board::put_porn(int a, int b)
{
    this->porn[this->turn] = a * (this->size) + b;
    this->turn = 1 - this->turn;
}

int board::min_length(int pos, int target)
{
    for (auto &x : this->temp)
    {
        x = 100;
    }
    std::queue<int> que;
    this->temp[pos] = 0;
    que.push(pos);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (int i : {-this->size, -1, 1, this->size})
        {
            int nv = v + i;
            if (temp[nv] == 100 && is_connect(v, nv))
            {
                temp[nv] = temp[v] + 1;
                if (nv / this->size == (1 - target) * (this->size - 1))
                {
                    return temp[nv];
                }
                que.push(nv);
            }
        }
    }
    return 100;
}

bool board::is_connect(int a, int b)
{
    if (a > b)
    {
        std::swap(a, b);
    }
    if (a < 0 && b >= this->size * this->size)
    {
        return false;
    }
    if (b - a == 1)
    {
        int x = a % this->size;
        if (x == this->size - 1)
        {
            return false;
        }
        int y = a / this->size;
        return get_wall(y, x) != 1 && get_wall(y - 1, x) != 1;
    }
    else if (b - a == this->size)
    {
        int x = a % this->size;
        int y = a / this->size;
        return get_wall(y, x) != 2 && get_wall(y, x - 1) != 2;
    }
}