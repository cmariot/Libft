#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char	*str;
	int	i;

	str = (char *)s;
	i = ft_strlen(str); 
	if (str[i] == '\0' && c == '\0')
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	//DIFFERENCE DANS LE CAS NULL : moi renvoit vide ; fonction renvoit (null) ??
	return (NULL);

}
