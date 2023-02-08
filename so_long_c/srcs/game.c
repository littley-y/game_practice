#include "so_long.h"

static void	get_start(t_param *main, t_list *map)
{
	t_list	*search;
	int		i;

	search = map;
	main->map = calloc(ft_lstsize(map) + 1, sizeof(char *));
	while (search != NULL)
	{
		i = -1;
		main->map[search->index - 1] = calloc(strlen(search->content), 1);
		while (search->content[++i] != '\n')
		{
			main->map[search->index - 1][i] = search->content[i];
			if (search->content[i] == 'P')
			{
				get_location(&main->x, &main->y, i, search->index - 1);
				main->map[search->index - 1][i] = '0';
			}
			else if (search->content[i] == 'X')
				get_location(&main->ex, &main->ey, i, search->index - 1);
		}
		search = search->next;
	}
}

int	mlx_game(t_list **map, t_elem game)
{
	t_param	main;

	memset(&main, 0, sizeof(t_param));
	main.var.mlx = mlx_init();
	main.var.width = (strlen((*map)->content) - 1) * 64;
	main.var.height = ft_lstsize(*map) * 64;
	main.var.win = mlx_new_window(main.var.mlx, main.var.width, \
	main.var.height, "so_long");
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
