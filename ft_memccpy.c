/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:57:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/26 17:49:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	stop;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	stop = (unsigned char)c;
	while (i < n)
	{
		dest[i] = source[i];
		if (dest[i] == stop)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
