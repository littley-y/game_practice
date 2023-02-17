#ifndef ASTAR_H
#define ASTAR_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../libft/libft.h"
#include "../../mlx/mlx.h"

#define ERROR -1
#define KEY_PRESS 2
#define MOUSE_CLICK 4
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53
#define RED_BUTTON 17

typedef struct s_data {
  void* img;
  char* addr;
  int bpp;
  int line_length;
  int endian;
} t_data;

typedef struct s_var {
  void* mlx;
  void* win;
  int width;
  int height;
} t_var;

typedef struct s_pic {
  t_data bg;
  t_data wall;
  t_data player;
  t_data ticket;
  t_data exit;
} t_pic;

typedef struct s_param {
  int x;
  int y;
  int ex;
  int ey;
  t_var var;
  t_pic pic;
  char** map;
} t_param;

typedef struct s_node {
  int x;
  int y;
  int f;
  int g;
  int h;
  struct s_node* parent;
} t_node;

void puterror_exit(char* str);
int mlx_game(t_list** map);
int putmsg_exit(char* str, t_var* var);
void put_imgs(t_param* main, int p_x, int p_y);
void get_images(t_var* var, t_pic* pic);
void img_to_win(t_var* var, void* img, int x, int y);
void get_map(t_list** map, int fd);
int exit_hook(t_var* var);
int key_press(int keycode, t_param* param);
int mouse_click(int mouse_code, int x, int y, t_param* main);
void a_star(t_param* main, int width, int height);

#endif