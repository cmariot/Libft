/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:25:02 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/20 09:00:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int nb)
{
	char	*str;
	int		i;

	if (nb < 0 || nb > 127)
		return (NULL);
	str = (char *)s;
	i = ft_strlen(str);
	if (nb == 0 && str[i] == nb)
		return (&str[i]);
	while (i > 0)
	{
		if (str[i - 1] == nb)
			return (&str[i - 1]);
		i--;
	}
	return (NULL);
}
