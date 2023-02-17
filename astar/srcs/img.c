#include "astar.h"

void img_to_win(t_var* var, void* img, int x, int y) {
  mlx_put_image_to_window(var->mlx, var->win, img, x * 64, y * 64);
}

void put_imgs(t_param* main, int p_x, int p_y) {
  mlx_clear_window(main->var.mlx, main->var.win);
  for (int i = 0; i != main->var.height; i++) {
    for (int j = 0; j != main->var.width; j++) {
      img_to_win(&main->var, main->pic.bg.img, j, i);
      if (main->map[i][j] == '1')
        img_to_win(&main->var, main->pic.wall.img, j, i);
      else if (main->map[i][j] == 'E')
        img_to_win(&main->var, main->pic.exit.img, j, i);
    }
  }
  img_to_win(&main->var, main->pic.player.img, p_x, p_y);
}

void get_images(t_var* var, t_pic* pic) {
  int dummy1;
  int dummy2;

  pic->bg.img =
      mlx_xpm_file_to_image(var->mlx, "images/bg.xpm", &dummy1, &dummy2);
  pic->player.img =
      mlx_xpm_file_to_image(var->mlx, "images/player.xpm", &dummy1, &dummy2);
  pic->ticket.img =
      mlx_xpm_file_to_image(var->mlx, "images/ticket.xpm", &dummy1, &dummy2);
  pic->exit.img =
      mlx_xpm_file_to_image(var->mlx, "images/exit_x.xpm", &dummy1, &dummy2);
  pic->wall.img =
      mlx_xpm_file_to_image(var->mlx, "images/wall.xpm", &dummy1, &dummy2);
}
