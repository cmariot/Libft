/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:58:09 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/26 18:29:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	i;

	tab = malloc(size * count);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
