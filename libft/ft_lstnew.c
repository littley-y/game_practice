#include "libft.h"

t_list	*ft_lstnew(int index)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->index = index;
	new_list->content = NULL;
	new_list->next = NULL;
	return (new_list);
}
