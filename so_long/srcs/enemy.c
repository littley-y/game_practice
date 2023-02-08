#include "so_long.h"

static void	move_up(t_param *main)
{
	const int	mx = main->ex;
	const int	my = main->ey - 1;

	if (main->map[my][mx] == 'C' || main->map[my][mx] == 'E'
		|| main->map[my][mx] == '1')
		return ;
	img_to_win(&main->var, main->pic.bg.img, main->ex, main->ey);
	img_to_win(&main->var, main->pic.enemy2.img, mx, my);
	main->map[main->ey][main->ex] = '0';
	main->map[my][mx] = 'X';
	main->ey--;
}

static void	move_down(t_param *main)
{
	const int	mx = main->ex;
	const int	my = main->ey + 1;

	if (main->map[my][mx] == 'C' || main->map[my][mx] == 'E'
		|| main->map[my][mx] == '1')
		return ;
	img_to_win(&main->var, main->pic.bg.img, main->ex, main->ey);
	img_to_win(&main->var, main->pic.enemy.img, mx, my);
	main->map[main->ey][main->ex] = '0';
	main->map[my][mx] = 'X';
	main->ey++;
}

static void	move_left(t_param *main)
{
	const int	mx = main->ex - 1;
	const int	my = main->ey;

	if (main->map[my][mx] == 'C' || main->map[my][mx] == 'E'
		|| main->map[my][mx] == '1')
		return ;
	img_to_win(&main->var, main->pic.bg.img, main->ex, main->ey);
	img_to_win(&main->var, main->pic.enemy2.img, mx, my);
	main->map[main->ey][main->ex] = '0';
	main->map[my][mx] = 'X';
	main->ex--;
}

static void	move_right(t_param *main)
{
	const int	mx = main->ex + 1;
	const int	my = main->ey;

	if (main->map[my][mx] == 'C' || main->map[my][mx] == 'E'
		|| main->map[my][mx] == '1')
		return ;
	img_to_win(&main->var, main->pic.bg.img, main->ex, main->ey);
	img_to_win(&main->var, main->pic.enemy.img, mx, my);
	main->map[main->ey][main->ex] = '0';
	main->map[my][mx] = 'X';
	main->ex++;
}

void	move_enemy(t_param *main, int dir)
{
	if (dir == 0 || dir == 1)
		move_left(main);
	else if (dir == 2)
		move_up(main);
	else if (dir == 3 || dir == 4)
		move_right(main);
	else if (dir == 5)
		move_down(main);
}
