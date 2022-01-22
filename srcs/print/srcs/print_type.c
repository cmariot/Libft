/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:26:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:41:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_is_in_type_list(int c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == '%')
		return (9);
	else
		return (0);
}

void	print_type(const char *frmt, unsigned int i, t_flags *flgs, int fd)
{
	if (frmt[i] == 'c')
		ft_print_char(flgs, fd);
	else if (frmt[i] == 'd' || frmt[i] == 'i')
		ft_print_integer(flgs, fd);
	else if (frmt[i] == 's')
		ft_print_str(flgs, fd);
	else if (frmt[i] == 'p')
		ft_print_addr(flgs, fd);
	else if (frmt[i] == 'u')
		ft_print_unsigned_int(flgs, fd);
	else if (frmt[i] == 'x')
		ft_print_hexa(flgs, fd);
	else if (frmt[i] == 'X')
		ft_print_hexa_maj(flgs, fd);
	else if (frmt[i] == '%')
		ft_print_percent(flgs, fd);
	return ;
}
