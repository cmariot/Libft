#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char	*str;
	int	i;

	str = (char *)s;
	i = 0; 
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return (&str[i]);
	return (NULL);

}
