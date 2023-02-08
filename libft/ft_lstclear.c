#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		(*del)(temp->content);
		temp->content = NULL;
		*lst = (*lst)->next;
		free(temp);
		temp = NULL;
	}
}
