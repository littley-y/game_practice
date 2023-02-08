#include "so_long.h"

static int	iselem(int c)
{
	if (c == 'E' || c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'X')
		return (1);
	else
		return (0);
}

static int	check_elem(char *line, t_elem *check, size_t width)
{
	size_t	i;

	i = 0;
	while (++i < width)
	{
		if (!iselem(line[i]))
			return (ERROR);
		if (line[i] == 'E')
			check->exit++;
		else if (line[i] == 'C')
			check->tic++;
		else if (line[i] == 'P')
			check->start++;
		else if (line[i] == 'X')
			check->enemy++;
	}
	return (0);
}

static int	check_line(char *line, int index, int height, size_t width)
{
	int	i;

	i = -1;
	if (index == 1 || index == height)
	{
		while (++i < (int)width)
		{
			if (line[i] != '1')
				return (ERROR);
		}
	}
	else
	{
		if (line[++i] != '1' || line[width - 1] != '1')
			return (ERROR);
	}
	return (0);
}

static t_elem	check_map(t_list *map)
{
	t_list	*line;
	size_t	width;
	t_elem	check;

	line = map;
	width = strlen(line->content) - 1;
	memset(&check, 0, sizeof(t_elem));
	while (line != NULL)
	{
		if (strlen(line->content) - 1 != width)
			puterror_exit("Not stable line!");
		if (check_line(line->content, line->index, ft_lstsize(map), width))
			puterror_exit("Wall problem!");
		if (check_elem(line->content, &check, width))
			puterror_exit("Wrong elements!");
		line = line->next;
	}
	if (!check.exit || !check.start || !check.tic || !check.enemy)
		puterror_exit("Not enough elements!");
	else if (check.start > 1)
		puterror_exit("Too many starting points!");
	else if (check.enemy > 1)
		puterror_exit("Too many enemy!");
	return (check);
}

void	get_map(t_list **map, t_elem *elem, int fd)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (++i)
	{
		temp = ft_lstnew(i);
		temp->content = get_next_line(fd);
		if (!temp->content || !temp->content[0])
		{
			ft_lstdelone(temp, &free);
			temp = NULL;
			break ;
		}
		ft_lstadd_back(map, temp);
	}
	if (!*map)
		puterror_exit("Empty map!");
	*elem = check_map(*map);
}
