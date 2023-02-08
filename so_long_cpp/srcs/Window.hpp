#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <cstdlib>
#include "so_long.hpp"

struct objImg;
struct playerImg;
class Map;

struct Window {
  static void* mlx;
  static void* win;
  int width;
  int height;

  Window(int newWidth, int newHeight);
  ~Window();

  void imgToWin(void* img, int x, int y);
  void putImages(const Map& map, objImg& pic);
  void setImages(objImg& pic);
  void setPlayerImages(playerImg& pl);
  int putString(int count);
  int putMsgExit(std::string str);
  static int exitHook();
};

#endif  // __WINDOW_H__