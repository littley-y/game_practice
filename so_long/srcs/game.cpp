/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:11:46 by yehyun            #+#    #+#             */
/*   Updated: 2023/01/27 12:37:13 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.hpp"

static void get_start(t_param* main, t_list* map) {
  t_list* search;
  int i;

  search = map;
  main->map = ft_calloc(ft_lstsize(map) + 1, sizeof(char*));
  while (search != NULL) {
    i = -1;
    main->map[search->index - 1] = ft_calloc(ft_strlen(search->line), 1);
    while (search->line[++i] != '\n') {
      main->map[search->index - 1][i] = search->line[i];
      if (search->line[i] == 'P') {
        get_location(&main->x, &main->y, i, search->index - 1);
        main->map[search->index - 1][i] = '0';
      } else if (search->line[i] == 'X')
        get_location(&main->ex, &main->ey, i, search->index - 1);
    }
    search = search->next;
  }
}

int mlx_game(t_list** map, t_elem game) {
  t_param main;

  ft_memset(&main, 0, sizeof(t_param));
  main.var.mlx = mlx_init();
  main.var.width = (ft_strlen((*map)->line) - 1) * 64;
  main.var.height = ft_lstsize(*map) * 64;
  main.var.win = mlx_new_window(main.var.mlx, main.var.width, main.var.height,
                                "so_long_bonus");
  get_images(&main.var, &main.pic);
  get_player_images(&main.var, &main.pl);
  put_imges(&main.var, *map, main.pic);
  main.game = game;
  get_start(&main, *map);
  ft_lstclear(map, &free);
  mlx_hook(main.var.win, PRESS, 0, &key_press, &main);
  mlx_hook(main.var.win, RED_BUTTON, 0, &exit_hook, &main.var);
  mlx_loop(main.var.mlx);
  return (0);
}
