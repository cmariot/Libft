/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:32:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_print_field_width(t_flags *flags, int len, char c, int fd)
{
	int	i;

	i = 0;
	if (flags->precision < len)
		while ((flags->field_width - flags->precision) - i++)
			flags->total_print += ft_putchar_ret_fd(c, fd);
	else if (flags->field_width > len)
		while (flags->field_width-- - len)
			flags->total_print += ft_putchar_ret_fd(c, fd);
}

void	ft_space_str(t_flags *flags, int len, int fd)
{
	char	c;

	if (flags->zero && !flags->minus)
		c = '0';
	else
		c = ' ';
	if (!flags->dot && (flags->field_width >= len))
		while (flags->field_width-- - len)
			flags->total_print += ft_putchar_ret_fd(c, fd);
	else if (flags->dot && (flags->precision >= 0))
	{
		if (flags->field_width >= flags->precision)
			ft_print_field_width(flags, len, c, fd);
		else if (flags->precision >= len)
			if (flags->field_width > len)
				while (flags->field_width-- - len)
					flags->total_print += ft_putchar_ret_fd(c, fd);
	}
	else if (flags->field_width > len)
		while (flags->field_width-- - len)
			flags->total_print += ft_putchar_ret_fd(c, fd);
	flags->field_width = 0;
}

void	ft_print_str(t_flags *flags, int fd)
{
	char	*str;
	int		len;
	int		backup_precision;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	str = va_arg(flags->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->field_width && !flags->minus)
		ft_space_str(flags, len, fd);
	backup_precision = flags->precision;
	if (flags->dot && (flags->precision >= 0))
		while (*str && backup_precision--)
			flags->total_print += ft_putchar_ret_fd(*str++, fd);
	else
		while (*str)
			flags->total_print += ft_putchar_ret_fd(*str++, fd);
	if (flags->field_width && flags->minus)
		ft_space_str(flags, len, fd);
	reset_flags(flags);
}
