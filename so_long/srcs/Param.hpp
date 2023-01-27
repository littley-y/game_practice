#ifndef __PARAM_HPP__
#define __PARAM_HPP__

#include "so_long.hpp"

class Param {
 private:
  int x;
  int y;
  int ex;
  int ey;
  int count;
  Window window;
  objImg pic;
  playerImg pl;
  ft::vector<std::string> map;
  char* display;

 public:
  Param();
  ~Param();

  int keyPress(int keycode);
  void movePlayer(int x, int y);
  void moveEnemy(int dir);
  void putPlayerToWindow(imgData* data, int x, int y);
};

#endif  // __PARAM_HPP__