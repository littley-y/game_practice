#ifndef __SO_LONG_H__
#define __SO_LONG_H__

#include <fstream>
#include <iostream>
#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../containers/vector.hpp"
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

void putErrExit(std::string str);
bool isElem(char c);
void getLocation(int* x, int* y, int lx, int ly);
char* ch(const char* str);

#endif  // __SO_LONG_H__