#include "Param.hpp"

Param::Param(Window& window, Map& map, objImg& obj, playerImg& players)
    : x(0),
      y(0),
      ex(0),
      ey(0),
      count(0),
      gameWindow(window),
      gameMap(map),
      gameObjs(obj),
      players(players) {}

int Param::keyPress() {
  Param pm;
  int keycode = 0;

  pm.gameWindow.imgToWin(pm.gameObjs.wall.img, 0, 0);
  pm.moveEnemy(pm.count % 6);
  if (pm.gameMap[pm.y][pm.x] == 'X')
    pm.gameWindow.putMsgExit("Enemy faced!");
  if (keycode == KEY_W) {
    pm.movePlayer(pm.x, pm.y - 1);
    pm.putPlayerToWindow(pm.players.pb, pm.x, pm.y);
  } else if (keycode == KEY_A) {
    pm.movePlayer(pm.x - 1, pm.y);
    pm.putPlayerToWindow(pm.players.pl, pm.x, pm.y);
  } else if (keycode == KEY_S) {
    pm.movePlayer(pm.x, pm.y + 1);
    pm.putPlayerToWindow(pm.players.pf, pm.x, pm.y);
  } else if (keycode == KEY_D) {
    pm.movePlayer(pm.x + 1, pm.y);
    pm.putPlayerToWindow(pm.players.pr, pm.x, pm.y);
  } else if (keycode == KEY_ESC)
    pm.gameWindow.putMsgExit("Bye!");
  if (pm.gameMap[pm.y][pm.x] == 'X')
    pm.gameWindow.putMsgExit("Enemy faced!");
  return (0);
}

void Param::moveEnemy(int dir) {
  int mx = ex;
  int my = ey;

  if (dir < 2)
    mx = ex - 1;
  else if (dir == 2)
    my = ey - 1;
  else if (dir < 5)
    mx = ex + 1;
  else if (dir == 5)
    my = ey + 1;
  if (gameMap[my][mx] == 'C' || gameMap[my][mx] == 'E' ||
      gameMap[my][mx] == '1')
    return;
  gameWindow.imgToWin(gameObjs.bg.img, ex, ey);
  gameWindow.imgToWin(gameObjs.enemy.img, mx, my);
  gameMap[ey][ex] = '0';
  gameMap[my][mx] = 'X';
  ex = mx;
  ey = my;
}

void Param::movePlayer(int mx, int my) {
  if (gameMap[my][mx] == '1' ||
      (gameMap[my][mx] == 'E' && gameMap.getTicketCnt()))
    return;
  else if (gameMap[my][mx] == 'C') {
    gameMap.decreaseTicketCnt();
    gameMap[my][mx] = '0';
    gameWindow.imgToWin(gameObjs.bg.img, mx, my);
  } else if (gameMap[my][mx] == 'E')
    gameWindow.putMsgExit("Nice!");
  gameWindow.putString(++count);
  gameWindow.imgToWin(gameObjs.bg.img, x, y);
  x = mx;
  y = my;
}

void Param::putPlayerToWindow(imgData* data, int x, int y) {
  if (count % 2 == 0)
    gameWindow.imgToWin(data[0].img, x, y);
  else if (count % 4 == 1)
    gameWindow.imgToWin(data[1].img, x, y);
  else
    gameWindow.imgToWin(data[2].img, x, y);
}

void Param::getStart() {
  for (size_t i = 0; i != gameMap.height(); i++) {
    for (size_t j = 0; j != gameMap.width() - 1; j++) {
      if (gameMap[i][j] == 'P') {
        getLocation(&x, &y, j, i);
        gameMap[i][j] = '0';
      } else if (gameMap[i][j] == 'X') {
        getLocation(&ex, &ey, j, i);
      }
    }
  }
}