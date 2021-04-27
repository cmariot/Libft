/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:43:39 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/27 13:21:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	local_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
			c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	long_nb_return(int nb_len, int sign)
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
	int		i;
	int		sign;
	int		nb_len;

	result = 0;
	i = 0;
	sign = 1;
	nb_len = 0;
	while (local_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		nb_len++;
	}
	if (nb_len > 10)
		return (long_nb_return(nb_len, sign));
	return (sign * result);
}
