/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:27:33 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/28 15:31:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	to_find_len;
	char			*haystack;
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
