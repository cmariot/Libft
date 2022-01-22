/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_putchar_ret_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

char	ft_c_is_zero(t_flags *flags, char *str, int fd)
{
	char	c;

	c = '0';
	if (*str == '-')
	{
		flags->total_print += ft_putchar_ret_fd('-', fd);
		flags->minus_printed = 1;
	}
	return (c);
}

void	ft_print_space(t_flags *flags, int len, int fd)
{
	char	c;

	if (flags->zero && !flags->minus)
		c = '0';
	else
		c = ' ';
	if (flags->field_width)
	{
		if (flags->dot)
		{
			if (flags->precision < flags->field_width)
			{
				if (len < flags->precision)
					while (flags->field_width-- - len)
						flags->total_print += write(fd, &c, 1);
				else
					while (flags->field_width-- - flags->precision)
						flags->total_print += write(fd, &c, 1);
			}
		}
		else if (len < flags->field_width)
			while (flags->field_width-- - len)
				flags->total_print += write(fd, &c, 1);
	}
	flags->field_width = 0;
}

void	ft_print_char(t_flags *flags, int fd)
{
	char	c;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	c = va_arg(flags->args, int);
	if (flags->field_width && !flags->minus)
		ft_print_space(flags, 1, fd);
	flags->total_print += write(fd, &c, 1);
	if (flags->field_width && flags->minus)
		ft_print_space(flags, 1, fd);
	reset_flags(flags);
}
