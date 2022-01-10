/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:43:39 by cmariot           #+#    #+#             */
/*   Updated: 2021/12/12 11:51:53 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_atoi converts an array of char into an integer */

static int	long_nb_return(int nb_len, int sign)
{
	if (nb_len > 10 && sign != -1)
		return (-1);
	else if (nb_len > 10 && sign == -1)
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		result_len;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	result = 0;
	result_len = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		result_len++;
	}
	if (result_len > 10)
		return (long_nb_return(result_len, sign));
	return (sign * result);
}
