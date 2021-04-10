#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	to_find_len;
	char 		*haystack;

	haystack = (char *)str;
	i = 0;
	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0)
		return (haystack);
	while (str[i] != '\0' && i < len - 1)
	{
		if (ft_strncmp(&str[i], to_find, to_find_len) == 0 && (i + to_find_len <= len))
			return (&haystack[i]);
		i++;
	}
	return (0);
}
