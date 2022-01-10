/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:07:53 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/29 12:58:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return the len of an integer, if it's negative it will have +1 to its len */
size_t	ft_intlen(int n)
{
	int	n_len;

	if (n == 0)
		return (1);
	n_len = 0;
	if (n < 0)
		n_len++;
	while (n != 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}
