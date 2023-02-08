#include "so_long.h"

void	img_to_win(t_var *var, void *img, int x, int y)
{
	mlx_put_image_to_window(var->mlx, var->win, img, x * 64, y * 64);
}

void	put_imges(t_var *var, t_list *map, t_pic pic)
{
	int		i;
	t_list	*lst;

	lst = map;
	while (lst != NULL)
	{
		i = -1;
		while (lst->content[++i] != '\n')
		{
			img_to_win(var, pic.bg.img, i, lst->index - 1);
			if (lst->content[i] == '1')
				img_to_win(var, pic.wall.img, i, lst->index - 1);
			else if (lst->content[i] == 'P')
				img_to_win(var, pic.pf.img, i, lst->index - 1);
			else if (lst->content[i] == 'C')
				img_to_win(var, pic.ticket.img, i, lst->index - 1);
			else if (lst->content[i] == 'E')
				img_to_win(var, pic.exit.img, i, lst->index - 1);
			else if (lst->content[i] == 'X')
				img_to_win(var, pic.enemy.img, i, lst->index - 1);
		}
		lst = lst->next;
	}
}

void	get_player_images(t_var *var, t_pl *pl)
{
	pl->pl.img = mlx_xpm_file_to_image(var->mlx, "images/pl0.xpm", \
	&var->width, &var->height);
	pl->pl1.img = mlx_xpm_file_to_image(var->mlx, "images/pl1.xpm", \
	&var->width, &var->height);
	pl->pl2.img = mlx_xpm_file_to_image(var->mlx, "images/pl2.xpm", \
	&var->width, &var->height);
	pl->pf.img = mlx_xpm_file_to_image(var->mlx, "images/pf0.xpm", \
	&var->width, &var->height);
	pl->pf1.img = mlx_xpm_file_to_image(var->mlx, "images/pf1.xpm", \
	&var->width, &var->height);
	pl->pf2.img = mlx_xpm_file_to_image(var->mlx, "images/pf2.xpm", \
	&var->width, &var->height);
	pl->pb.img = mlx_xpm_file_to_image(var->mlx, "images/pb0.xpm", \
	&var->width, &var->height);
	pl->pb1.img = mlx_xpm_file_to_image(var->mlx, "images/pb1.xpm", \
	&var->width, &var->height);
	pl->pb2.img = mlx_xpm_file_to_image(var->mlx, "images/pb2.xpm", \
	&var->width, &var->height);
	pl->pr.img = mlx_xpm_file_to_image(var->mlx, "images/pr0.xpm", \
	&var->width, &var->height);
	pl->pr1.img = mlx_xpm_file_to_image(var->mlx, "images/pr1.xpm", \
	&var->width, &var->height);
	pl->pr2.img = mlx_xpm_file_to_image(var->mlx, "images/pr2.xpm", \
	&var->width, &var->height);
}

void	get_images(t_var *var, t_pic *pic)
{
	pic->bg.img = mlx_xpm_file_to_image(var->mlx, "images/bg.xpm", \
	&var->width, &var->height);
	pic->ticket.img = mlx_xpm_file_to_image(var->mlx, "images/ticket.xpm", \
	&var->width, &var->height);
	pic->exit.img = mlx_xpm_file_to_image(var->mlx, "images/exit_x.xpm", \
	&var->width, &var->height);
	pic->pf.img = mlx_xpm_file_to_image(var->mlx, "images/pf0.xpm", \
	&var->width, &var->height);
	pic->wall.img = mlx_xpm_file_to_image(var->mlx, "images/wall.xpm", \
	&var->width, &var->height);
	pic->enemy.img = mlx_xpm_file_to_image(var->mlx, "images/enemy.xpm", \
	&var->width, &var->height);
	pic->enemy2.img = mlx_xpm_file_to_image(var->mlx, "images/enemy2.xpm", \
	&var->width, &var->height);
}
