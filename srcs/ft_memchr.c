/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:25:16 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/29 13:09:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The ft_memchr() function locates the first occurrence of c
 * (converted to an unsigned char) in string s. */

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	if (n == 0)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
