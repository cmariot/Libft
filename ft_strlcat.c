/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:27:12 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 14:30:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{	
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i + dest_len < dest_size - 1)
	{
		dest[i + dest_len] = (char)src[i];
		i++;
	}
	if (dest_size < dest_len)
		return (dest_size + src_len);
	dest[i + dest_len] = '\0';
	return (src_len + dest_len);
}
