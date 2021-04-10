#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	
	if (dst_size > 0)
	{
		while (src[i] && (i < (dst_size - 1)))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
