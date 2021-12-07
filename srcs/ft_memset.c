/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:52:49 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/11 11:21:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	value;

	i = 0;
	str = (unsigned char *)b;
	value = (unsigned char)c;
	while (i < len)
	{
		str[i] = value;
		i++;
	}
	return (str);
}
