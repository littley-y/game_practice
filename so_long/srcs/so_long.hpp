#ifndef __SO_LONG_HPP__
#define __SO_LONG_HPP__

#include <fstream>
#include <iostream>
#include "../../containers/vector.hpp"
#include "../../mlx/mlx.h"
#include "Map.hpp"
#include "Param.hpp"
#include "Window.hpp"

#define ERROR -1
#define PRESS 2
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53
#define RED_BUTTON 17

struct imgData {
  void* img;
  char* addr;
  int bpp;
  int line_length;
  int endian;
};

struct objImg {
  imgData bg;
  imgData wall;
  imgData enemy;
  imgData enemy2;
  imgData ticket;
  imgData exit;
  imgData pf;
};

struct playerImg {
  imgData pf[3];
  imgData pb[3];
  imgData pl[3];
  imgData pr[3];
};

struct mapElements {
  int exit;
  int tic;
  int start;
  int enemy;
};

void putErrExit(char* str);
bool isElem(char c);
int mlx_game(Map& map, t_elem game);
Map move_line(Map map, int move_index);
void get_location(int* x, int* y, int lx, int ly);

#endif  // __SO_LONG_HPP__