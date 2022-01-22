/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:23:50 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_print_fw(t_flags *flags, char *str, int i, char c)
{
	if (*str == '-')
		i++;
	while ((flags->field_width - flags->precision) - i++)
		flags->total_print += ft_putchar_ret_fd(c, flags->fd);
}

int	ft_flags_blank_or_plus(t_flags *flags, int fd)
{
	if (flags->blank)
	{
		flags->total_print += ft_putchar_ret_fd(' ', fd);
		return (1);
	}
	else if (flags->plus)
	{
		flags->total_print += ft_putchar_ret_fd('+', fd);
		return (1);
	}
	else
		return (0);
}

void	ft_print(char *str, t_flags *flags, int fd)
{
	int	initial_len;
	int	final_len;

	initial_len = ft_strlen(str);
	final_len = ft_len_of_print(str, flags);
	if (flags->field_width && !flags->minus)
		ft_space_before(flags, final_len, str, fd);
	if (ft_isdigit(*str) && !flags->minus_printed)
		final_len += ft_flags_blank_or_plus(flags, fd);
	if (flags->dot)
		ft_print_precision(flags, &str, initial_len, fd);
	if (flags->minus_printed)
		str++;
	while (*str)
		flags->total_print += ft_putchar_ret_fd(*str++, fd);
	if (flags->field_width && flags->minus)
		ft_space_after(flags, final_len, fd);
	reset_flags(flags);
	return ;
}

void	ft_print_integer(t_flags *flags, int fd)
{
	int		d;
	char	*str;

	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->star_for_precision)
		ft_precision_star(flags);
	d = va_arg(flags->args, int);
	str = ft_itoa(d);
	ft_print(str, flags, fd);
	free(str);
}
