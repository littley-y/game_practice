#include "so_long.h"

void	put_pb(t_param *main, int x, int y)
{
	if (main->count % 2 == 0)
		img_to_win(&main->var, main->pl.pb.img, x, y);
	else if (main->count % 4 == 1)
		img_to_win(&main->var, main->pl.pb1.img, x, y);
	else
		img_to_win(&main->var, main->pl.pb2.img, x, y);
}

void	put_pf(t_param *main, int x, int y)
{
	if (main->count % 2 == 0)
		img_to_win(&main->var, main->pl.pf.img, x, y);
	else if (main->count % 4 == 1)
		img_to_win(&main->var, main->pl.pf1.img, x, y);
	else
		img_to_win(&main->var, main->pl.pf2.img, x, y);
}

void	put_pl(t_param *main, int x, int y)
{
	if (main->count % 2 == 0)
		img_to_win(&main->var, main->pl.pl.img, x, y);
	else if (main->count % 4 == 1)
		img_to_win(&main->var, main->pl.pl1.img, x, y);
	else
		img_to_win(&main->var, main->pl.pl2.img, x, y);
}

void	put_pr(t_param *main, int x, int y)
{
	if (main->count % 2 == 0)
		img_to_win(&main->var, main->pl.pr.img, x, y);
	else if (main->count % 4 == 1)
		img_to_win(&main->var, main->pl.pr1.img, x, y);
	else
		img_to_win(&main->var, main->pl.pr2.img, x, y);
}
