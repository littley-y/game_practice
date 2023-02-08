#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb)
		nmemb = 1;
	if ((size * nmemb) / nmemb != size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	if (!size)
		ft_bzero(ptr, 1);
	else
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
