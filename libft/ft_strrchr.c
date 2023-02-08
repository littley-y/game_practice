#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*temp;
	int				i;

	temp = (unsigned char *)s;
	i = ft_strlen(s);
	while (temp[i] != (unsigned char)c && i)
		i--;
	if (temp[i] == (unsigned char)c)
		return ((char *)&temp[i]);
	else
		return (NULL);
}
