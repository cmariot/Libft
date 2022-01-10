/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:25:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/13 09:51:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strrchr() function locates the last occurrence of nb 
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered to be part of the string ;
 * therefore if c is ‘\0’, the functions locate the terminating ‘\0’.*/

char	*ft_strrchr(const char *s, int nb)
{
	char	*str;
	int		i;

	if (!(char)nb)
		return (NULL);
	str = (char *)s;
	i = ft_strlen(str);
	if ((char)nb == 0 && str[i] == (char)nb)
		return (&str[i]);
	while (i > 0)
	{
		if (str[i - 1] == (char)nb)
			return (&str[i - 1]);
		i--;
	}
	return (NULL);
}
