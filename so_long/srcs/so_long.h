#ifndef SO_LONG
# define SO_LONG

# include "../../mlx/mlx.h"
# include "../../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define ERROR -1
# define PRESS 2
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define RED_BUTTON 17

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_var;

typedef struct s_elem
{
	int	exit;
	int	tic;
	int	start;
	int	enemy;
}	t_elem;

typedef struct s_pic
{
	t_data	bg;
	t_data	wall;
	t_data	enemy;
	t_data	enemy2;
	t_data	ticket;
	t_data	exit;
	t_data	pf;
}	t_pic;

typedef struct s_pl
{
	t_data	pf;
	t_data	pf1;
	t_data	pf2;
	t_data	pb;
	t_data	pb1;
	t_data	pb2;
	t_data	pl;
	t_data	pl1;
	t_data	pl2;
	t_data	pr;
	t_data	pr1;
	t_data	pr2;
}	t_pl;

typedef struct s_param
{
	int		x;
	int		y;
	int		ex;
	int		ey;
	int		em;
	int		count;
	t_elem	game;
	t_var	var;
	t_pic	pic;
	t_pl	pl;
	char	**map;
	char	*display;
}	t_param;


// games
int		mlx_game(t_list **map, t_elem game);
void	img_to_win(t_var *var, void *img, int x, int y);
void	get_map(t_list **map, t_elem *elem, int fd);
void	get_location(int *x, int *y, int lx, int ly);

// images
void	get_images(t_var *var, t_pic *pic);
void	get_player_images(t_var *var, t_pl *pl);
void	put_imges(t_var *var, t_list *map, t_pic pic);
void	put_pb(t_param *main, int x, int y);
void	put_pf(t_param *main, int x, int y);
void	put_pl(t_param *main, int x, int y);
void	put_pr(t_param *main, int x, int y);
int		put_string(t_var *var, int count);

// key press
int		key_press(int keycode, t_param *param);
void	move_enemy(t_param *main, int dir);
int		exit_hook(t_var *var);

// utils
void	puterror_exit(char *str);
int		putmsg_exit(char *str, t_var *var);

#endif