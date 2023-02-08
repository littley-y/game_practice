#include "so_long.h"

void	puterror_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

int	putmsg_exit(char *str, t_var *var)
{
	ft_putendl_fd(str, 1);
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
	return (0);
}

int	exit_hook(t_var *var)
{
	ft_putendl_fd("Bye!", 1);
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
	return (0);
}

void	get_location(int *x, int *y, int lx, int ly)
{
	*x = lx;
	*y = ly;
}

int	put_string(t_var *var, int count)
{
	char	*num;

	num = ft_itoa(count);
	mlx_string_put(var->mlx, var->win, (var->width / 2) - 16, \
	var->height / 2 - 10, 0xFF000000, "MOVE");
	mlx_string_put(var->mlx, var->win, \
	(var->width / 2) - (ft_strlen(num) + 5), \
	var->height / 2, 0xFF000000, num);
	free(num);
	num = NULL;
	return (0);
}
