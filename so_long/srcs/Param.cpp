#include "Param.hpp"

Param::Param() {}

Param::~Param() {}

int Param::keyPress(int keycode) {
  window.imgToWin(pic.wall.img, 0, 0);
  moveEnemy(count % 6);
  if (map[y][x] == 'X')
    window.putMsgExit("Enemy faced!");
  if (keycode == KEY_W) {
    movePlayer(x, y - 1);
    putPlayerToWindow(pl.pb, x, y);
  } else if (keycode == KEY_A) {
    movePlayer(x - 1, y);
    putPlayerToWindow(pl.pl, x, y);
  } else if (keycode == KEY_S) {
    movePlayer(x, y + 1);
    putPlayerToWindow(pl.pf, x, y);
  } else if (keycode == KEY_D) {
    movePlayer(x + 1, y);
    putPlayerToWindow(pl.pr, x, y);
  } else if (keycode == KEY_ESC)
    window.putMsgExit("Bye!");
  if (map[y][x] == 'X')
    window.putMsgExit("Enemy faced!");
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
  if (map[my][mx] == 'C' || map[my][mx] == 'E' || map[my][mx] == '1')
    return;
  window.imgToWin(pic.bg.img, ex, ey);
  window.imgToWin(pic.enemy.img, mx, my);
  map[ey][ex] = '0';
  map[my][mx] = 'X';
  ex = mx;
  ey = my;
}

void Param::movePlayer(int mx, int my) {
  if (map[my][mx] == '1' || (map[my][mx] == 'E' && map.getTicketCnt()))
    return;
  else if (map[my][mx] == 'C') {
    map.decreaseTicketCnt();
    map[my][mx] = '0';
    window.imgToWin(pic.bg.img, mx, my);
  } else if (map[my][mx] == 'E')
    window.putMsgExit("Nice!");
  window.putString(++count);
  window.imgToWin(pic.bg.img, x, y);
  x = mx;
  y = my;
}

void Param::putPlayerToWindow(imgData* data, int x, int y) {
  if (count % 2 == 0)
    window.imgToWin(data[0].img, x, y);
  else if (count % 4 == 1)
    window.imgToWin(data[1].img, x, y);
  else
    window.imgToWin(data[2].img, x, y);
}
