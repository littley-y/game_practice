#include "astar.h"

int mouse_click(int mouse_code, int x, int y, t_param* main) {
  x /= 32;
  y /= 32;

  if (mouse_code != 1 || (x == main->x && y == main->y))
    return (0);

  if (main->map[y][x] == '0') {
    main->map[y][x] = '1';
    put_imgs(main);
    a_star(main, main->var.width, main->var.height);
  } else if (main->map[y][x] == '1') {
    if (x && x != main->var.width - 1 && y && y != main->var.height - 1) {
      main->map[y][x] = '0';
      put_imgs(main);
      a_star(main, main->var.width, main->var.height);
    }
  }
  return (0);
}

int key_press(int keycode, t_param* main) {
  int mx = main->x;
  int my = main->y;

  if (keycode == KEY_ESC)
    putmsg_exit("Bye!", &main->var);
  else if (keycode == KEY_W)
    my = main->y - 1;
  else if (keycode == KEY_A)
    mx = main->x - 1;
  else if (keycode == KEY_S)
    my = main->y + 1;
  else if (keycode == KEY_D)
    mx = main->x + 1;

  if (main->map[my][mx] == 'E') {
    putmsg_exit("Finished!", &main->var);
  } else if (main->map[my][mx] != '1') {
    main->x = mx;
    main->y = my;
    put_imgs(main);
    a_star(main, main->var.width, main->var.height);
  }
  return (0);
}
