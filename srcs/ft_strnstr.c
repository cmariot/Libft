/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:27:33 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/13 11:17:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The ft_strnstr() function locates the first occurrence of the null-terminated
 * string to_find in the string str, where not more than len characters
 * are searched.
 * Characters that appear after a ‘\0’ character are not searched. */

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char			*haystack;
	unsigned int	i;
	unsigned int	to_find_len;
	int				comparaison;

	haystack = (char *)str;
	i = 0;
	to_find_len = ft_strlen(to_find);
	if (to_find_len == 0)
		return (haystack);
	while (str[i] != '\0' && i <= len)
	{
		comparaison = ft_strncmp(&str[i], to_find, to_find_len);
		if (comparaison == 0 && (i + to_find_len <= len))
			return (&haystack[i]);
		i++;
	}
	return (0);
}
