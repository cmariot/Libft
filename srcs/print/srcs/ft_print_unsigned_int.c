/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:24 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

unsigned int	uint_len(unsigned int n)
{
	int	n_len;

	n_len = 0;
	while (n != 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_u_itoa(unsigned int n)
{
	unsigned int	n_len;
	char			*nombre;

	if (n == 0)
		return (ft_strdup("0"));
	n_len = uint_len(n);
	nombre = malloc(sizeof(char) * (n_len + 1));
	if (nombre == NULL)
		return (NULL);
	nombre[n_len] = '\0';
	while (n != 0)
	{
		nombre[n_len - 1] = '0' + n % 10;
		n = n / 10;
		n_len--;
	}
	return (nombre);
}

void	ft_print_unsigned_int(t_flags *flags, int fd)
{
	unsigned int	u;
	char			*str;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	u = va_arg(flags->args, unsigned int);
	str = ft_u_itoa(u);
	ft_print(str, flags, fd);
	free(str);
}
