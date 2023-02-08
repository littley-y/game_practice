#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*temp;
	char	*start;

	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	start = temp;
	if (!temp)
		return (NULL);
	while (len--)
		*(temp++) = *(s++);
	*temp = '\0';
	return (start);
}
