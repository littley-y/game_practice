#include "astar.h"

static void get_start(t_param* main, t_list** map) {
  t_list* search;
  int i;

  search = *map;
  main->map = ft_calloc(ft_lstsize(*map) + 1, sizeof(char*));
  while (search != NULL) {
    i = -1;
    main->map[search->index - 1] = ft_calloc(ft_strlen(search->content), 1);
    while (search->content[++i] != '\n') {
      main->map[search->index - 1][i] = search->content[i];
      if (search->content[i] == 'P') {
        main->x = i;
        main->y = search->index - 1;
        main->map[search->index - 1][i] = '0';
      } else if (search->content[i] == 'E') {
        main->ex = i;
        main->ey = search->index - 1;
      }
    }
    search = search->next;
    if (search != NULL && search->next == NULL)
      main->var.height = search->index;
  }
  main->var.width = i;
}

int mlx_game(t_list** map) {
  t_param main;

  ft_memset(&main, 0, sizeof(t_param));
  main.var.mlx = mlx_init();
  main.var.width = (ft_strlen((*map)->content) - 1) * 64;
  main.var.height = ft_lstsize(*map) * 64;
  main.var.win =
      mlx_new_window(main.var.mlx, main.var.width, main.var.height, "astar");
  get_images(&main.var, &main.pic);
  get_start(&main, map);
  ft_lstclear(map, &free);
  put_imgs(&main, main.x, main.y);
  mlx_hook(main.var.win, KEY_PRESS, 0, &key_press, &main);
  mlx_hook(main.var.win, MOUSE_CLICK, 0, &mouse_click, &main);
  mlx_hook(main.var.win, RED_BUTTON, 0, &exit_hook, &main.var);
  mlx_loop(main.var.mlx);
  return (0);
}
