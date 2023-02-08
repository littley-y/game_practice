#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*temp;
	int				i;

	i = 0;
	temp = (unsigned char *)s;
	while (temp[i] != (unsigned char)c && temp[i])
		i++;
	if ((unsigned char)c && !temp[i])
		return (NULL);
	else
		return ((char *)temp + i);
}
