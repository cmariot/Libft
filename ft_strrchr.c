/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:25:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/28 13:30:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int nb)
{
	char	*str;
	int		i;
	char	c;

	c = (char)nb;
	if (c < 0 || c > 127)
		return (NULL);
	str = (char *)s;
	i = ft_strlen(str);
	if (c == '\0' && str[i] == c)
		return (&str[i]);
	while (i > 0)
	{
		if (str[i - 1] == c)
		{
			return (&str[i - 1]);
		}
		i--;
	}
	return (NULL);
}
