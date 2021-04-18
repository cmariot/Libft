/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:58:09 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/18 15:07:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	i;

	if (!(tab = malloc(size * count)))
		return (NULL);
	i = 0;
	while (i < count)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
