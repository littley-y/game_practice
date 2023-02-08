#include "so_long.h"

static void	press_key_w(t_param *main)
{
	const int	mx = main->x;
	const int	my = main->y - 1;

	if (main->map[my][mx] == 49 || (main->map[my][mx] == 69 && main->game.tic))
		return ;
	if (main->map[my][mx] == 'C')
	{
		main->game.tic--;
		main->map[my][mx] = '0';
		img_to_win(&main->var, main->pic.bg.img, mx, my);
	}
	else if (main->map[my][mx] == 'E')
		putmsg_exit("Congraturation!", &main->var);
	put_string(&main->var, ++main->count);
	img_to_win(&main->var, main->pic.bg.img, mx, my + 1);
	put_pb(main, mx, my);
	main->y--;
}

static void	press_key_s(t_param *main)
{
	const int	mx = main->x;
	const int	my = main->y + 1;

	if (main->map[my][mx] == 49 || (main->map[my][mx] == 69 && main->game.tic))
		return ;
	if (main->map[my][mx] == 'C')
	{
		main->game.tic--;
		main->map[my][mx] = '0';
		img_to_win(&main->var, main->pic.bg.img, mx, my);
	}
	else if (main->map[my][mx] == 'E')
		putmsg_exit("Congraturation!", &main->var);
	put_string(&main->var, ++main->count);
	img_to_win(&main->var, main->pic.bg.img, mx, my - 1);
	put_pf(main, mx, my);
	main->y++;
}

static void	press_key_a(t_param *main)
{
	const int	mx = main->x - 1;
	const int	my = main->y;

	if (main->map[my][mx] == 49 || (main->map[my][mx] == 69 && main->game.tic))
		return ;
	if (main->map[my][mx] == 'C')
	{
		main->game.tic--;
		main->map[my][mx] = '0';
		img_to_win(&main->var, main->pic.bg.img, mx, my);
	}
	else if (main->map[my][mx] == 'E')
		putmsg_exit("Congraturation!", &main->var);
	put_string(&main->var, ++main->count);
	img_to_win(&main->var, main->pic.bg.img, mx + 1, my);
	put_pl(main, mx, my);
	main->x--;
}

static void	press_key_d(t_param *main)
{
	const int	mx = main->x + 1;
	const int	my = main->y;

	if (main->map[my][mx] == 49 || (main->map[my][mx] == 69 && main->game.tic))
		return ;
	if (main->map[my][mx] == 'C')
	{
		main->game.tic--;
		main->map[my][mx] = '0';
		img_to_win(&main->var, main->pic.bg.img, mx, my);
	}
	else if (main->map[my][mx] == 'E')
		putmsg_exit("Congraturation!", &main->var);
	put_string(&main->var, ++main->count);
	img_to_win(&main->var, main->pic.bg.img, mx - 1, my);
	put_pr(main, mx, my);
	main->x++;
}

int	key_press(int keycode, t_param *main)
{
	img_to_win(&main->var, main->pic.wall.img, 0, 0);
	move_enemy(main, main->em++ % 6);
	if (main->map[main->y][main->x] == 'X')
		putmsg_exit("Enemy faced!", &main->var);
	if (keycode == KEY_W)
		press_key_w(main);
	else if (keycode == KEY_A)
		press_key_a(main);
	else if (keycode == KEY_S)
		press_key_s(main);
	else if (keycode == KEY_D)
		press_key_d(main);
	else if (keycode == KEY_ESC)
		putmsg_exit("Bye!", &main->var);
	if (main->map[main->y][main->x] == 'X')
		putmsg_exit("Enemy faced!", &main->var);
	return (0);
}
