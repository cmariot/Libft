/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:22:57 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/06 22:03:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Free an array of char *, and free the array itself */
void	ft_free_array(char **array)
{
	size_t	i;

	if (array != NULL)
	{
		i = 0;
		while (array[i] != NULL)
		{
			if (array[i])
				free(array[i]);
			array[i] = NULL;
			i++;
		}
		if (array)
			free(array);
		array = NULL;
		return ;
	}
}
