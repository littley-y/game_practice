#ifndef __PARAM_H__
#define __PARAM_H__

#include "so_long.hpp"

struct objImg;
struct playerImg;
struct Window;
struct imgData;
class Map;

class Param {
 public:
  int x;
  int y;
  int ex;
  int ey;
  int count;
  Window& gameWindow;
  Map& gameMap;
  objImg& gameObjs;
  playerImg& players;

  Param(Window& window, Map& map, objImg& obj, playerImg& pl);
  Param();

  static int keyPress();
  void movePlayer(int x, int y);
  void moveEnemy(int dir);
  void putPlayerToWindow(imgData* data, int x, int y);
  void getStart();
};

#endif  // __PARAM_H__