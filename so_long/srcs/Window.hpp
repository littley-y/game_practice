#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <cstdlib>
#include "so_long.hpp"

class Window {
 private:
  void* mlx;
  void* win;
  int width;
  int height;

 public:
  Window();
  ~Window();

  void imgToWin(void* img, int x, int y);
  void putImages(const Map& map, objImg& pic);
  void getImages(objImg& pic);
  void getPlayerImages(playerImg& pl);
  int exitHook();
  int putString(int count);
  int putMsgExit(char* str);
};

#endif  // __WINDOW_HPP__