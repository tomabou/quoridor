#include "../src/board.h"

int main()
{
    auto b = new board(9);
    b->put_wall(0, 0, 2);
    b->put_wall(0, 2, 2);
    b->put_wall(0, 4, 2);
    b->put_wall(0, 6, 2);
    b->put_wall(1, 1, 2);
    b->put_wall(1, 3, 2);
    b->put_wall(1, 5, 2);
    b->put_wall(1, 7, 2);
    b->put_wall(2, 0, 2);
    b->put_wall(2, 2, 2);
    b->put_wall(2, 4, 2);
    b->put_wall(2, 6, 2);
    //b->put_porn(4, 5);
    //b->put_porn(5, 5);
    std::cout << b->min_length(39, 0) << std::endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int x = b->temp[i * 9 + j];
            if (x == 100)
            {
                x = 0;
            }
            std::cout << x;
        }
        std::cout << std::endl;
    }
    std::cout << b->min_length(39, 1) << std::endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int x = b->temp[i * 9 + j];
            if (x == 100)
            {
                x = 0;
            }
            std::cout << x;
        }
        std::cout << std::endl;
    }
    b->show();
    assert(!b->can_put(1, 0, 2));
    assert(!b->can_put(1, 0, 1));
    assert(b->can_put(5, 0, 1));
}