#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	unsigned const char	*str;

	temp = (unsigned char *)dest;
	str = (unsigned const char *)src;
	if (dest <= src)
	{
		if (dest == 0 && src == 0)
			return (dest);
		while (n--)
			*(temp++) = *(str++);
	}
	else
	{
		temp += n;
		str += n;
		while (n--)
			*(--temp) = *(--str);
	}
	return (dest);
}
