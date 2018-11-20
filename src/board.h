#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <array>
#include <queue>

class board
{
private:
  std::vector<int> v;
  int size;
  int turn;
  std::array<int, 2> wall = {10, 10};
  std::array<int, 2> porn;
  char get_porn_exp(int, int);
  bool is_connect(int, int);
  bool can_put(int, int, int);

public:
  std::vector<int> temp;
  void show();
  board(int);
  void put_wall(int, int, int);
  int get_wall(int, int);
  void put_porn(int, int);
  int min_length(int, int);
};
#endif