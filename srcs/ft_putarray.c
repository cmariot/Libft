/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:10:31 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/31 14:37:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Print an array of char * like this :
// name[i] = array[i]

void	ft_putarray(char *name, char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putstr(name);
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] = [");
		ft_putstr(array[i]);
		ft_putstr("]\n");
		i++;
	}
}
