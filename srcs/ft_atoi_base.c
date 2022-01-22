/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:23:55 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/22 00:29:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == 32)
		return (1);
	else
		return (0);
}

int	ft_count_minus(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	ft_atoi_for_atoibase(char *str)
{
	int	i;
	int	minus_counter;
	int	nb;

	i = 0;
	nb = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	minus_counter = 0;
	while (ft_count_minus(str[i]) == 1)
	{
		if (str[i] == '-')
			minus_counter++;
		i++;
	}
	if (minus_counter % 2 != 0)
		minus_counter = -1;
	else
		minus_counter = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * minus_counter);
}

int	ft_check_base(char *base)
{
	int		base_len;
	int		j;

	base_len = 0;
	while (base[base_len] != '\0')
	{
		if (base[base_len] == '+' || base[base_len] == '-')
			return (0);
		j = base_len + 1;
		while (base[j] != '\0')
		{
			if (base[base_len] == base[j])
				return (0);
			j++;
		}
		base_len++;
	}
	if (base_len <= 1)
		return (0);
	return (1);
}

void	ft_atoi_base(char *str, char *base)
{
	int			diviseur;
	int			result;
	int			base_len;
	long int	long_nb;

	if (ft_check_base(base) == 0)
		return ;
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	long_nb = ft_atoi_for_atoibase(str) + 0;
	if (long_nb < 0)
	{
		ft_putchar('-');
		long_nb = -(long_nb);
	}
	diviseur = 1;
	while ((long_nb / diviseur) >= base_len)
		diviseur = diviseur * base_len;
	while (diviseur > 0)
	{
		result = (long_nb / diviseur) % base_len;
		ft_putchar(base[result]);
		diviseur = diviseur / base_len;
	}
}
