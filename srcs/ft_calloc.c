/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:58:09 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/14 19:17:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The calloc() function contiguously allocates enough
 * space for count objects that are size bytes of memory each
 * and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero. */

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	size_t	i;

	new = malloc(size * count);
	if (!new)
		return (NULL);
	i = 0;
	while (i < count * size)
		new[i++] = 0;
	return (new);
}
