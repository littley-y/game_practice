#include "libft.h"

void	ft_strrev(char *str)
{
	int		i;
	int		size;
	char	temp;

	i = 0;
	size = ft_strlen(str);
	while (i < size / 2)
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
}
