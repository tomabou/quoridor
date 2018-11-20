#include "../src/board.h"

int main()
{
    auto b = new board(9);
    b->put_wall(2, 3, 1);
    b->put_wall(5, 5, 2);
    b->show();
}