#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	while (i < src_size && i < dst_size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}
