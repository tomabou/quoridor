#include <iostream>
#include <vector>
#include <array>

class board
{
  private:
    std::vector<int> v;
    int size;
    int turn;
    std::array<int, 2> wall;
    std::array<int, 2> porn;

  public:
    void show();
    board(int);
    void put_wall(int, int, int);
    int get_wall(int, int);
};