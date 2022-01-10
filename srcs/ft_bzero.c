/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:08:10 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/29 01:28:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_bzero() writes n zeroed bytes to the string s. */

void	ft_bzero(void *str, size_t bytes_nb)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)str;
	while (i < bytes_nb)
	{
		dest[i] = 0;
		i++;
	}
}
