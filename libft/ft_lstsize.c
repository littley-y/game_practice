#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*search;

	size = 0;
	search = lst;
	while (search != NULL)
	{
		search = search->next;
		size++;
	}
	return (size);
}
