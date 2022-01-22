/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_and_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:12:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_space_before(t_flags *flags, int len, char *str, int fd)
{
	char	c;
	int		i;

	c = ' ';
	if (flags->zero && ((!flags->dot) || (flags->precision < 0)))
		c = ft_c_is_zero(flags, str, fd);
	i = 0;
	if (flags->plus && ft_isdigit(*str))
		len++;
	if (flags->field_width > flags->precision)
	{
		if (flags->dot && !flags->precision)
			if (flags->field_width > len)
				if (flags->minus_printed)
					len--;
		if (flags->precision >= len)
			ft_print_fw(flags, str, i, c);
		else if (flags->field_width > len)
			while (flags->field_width-- - len)
				flags->total_print += ft_putchar_ret_fd(c, fd);
		if (flags->precision >= len || flags->field_width > len)
			flags->blank = 0;
	}
	flags->field_width = 0;
}

void	ft_space_after(t_flags *flags, int len, int fd)
{
	int		i;
	char	c;

	c = ' ';
	i = 0;
	if (flags->field_width > flags->precision)
	{
		if (flags->dot && (flags->field_width > len) && !flags->precision)
			while (flags->field_width-- - len)
				flags->total_print += ft_putchar_ret_fd(c, fd);
		else if (flags->precision > len)
		{
			if (flags->minus_printed)
				i++;
			while ((flags->field_width - flags->precision) - i++)
				flags->total_print += ft_putchar_ret_fd(c, fd);
		}
		else if (flags->field_width > len)
		{
			if (flags->minus_printed)
				len++;
			while (flags->field_width-- - len)
				flags->total_print += ft_putchar_ret_fd(c, fd);
		}
	}
}

int	ft_len_of_print(char *str, t_flags *flags)
{
	int	len;

	len = ft_strlen(str);
	if (flags->dot)
	{
		if (flags->precision)
		{
			if (flags->precision > len)
			{
				while (flags->precision - len)
					len++;
				if (*str == '-')
					len--;
			}
		}
		else if (!flags->precision && !flags->hashtag)
			while (*str++ == '0')
				len--;
	}
	if (flags->hashtag && flags->precision >= len)
		len += 2;
	if (flags->blank && flags->field_width > len)
		len += 1;
	return (len);
}

int	ft_print_minus(t_flags *flags, int fd)
{
	if (!flags->minus_printed)
		flags->total_print += ft_putchar_ret_fd('-', fd);
	flags->minus_printed = 1;
	return (1);
}

void	ft_print_precision(t_flags *flags, char **str, int initial_len, int fd)
{
	int	i;

	i = 0;
	if (flags->hashtag)
		initial_len -= ft_print_0x(flags, &str, fd);
	if (flags->precision >= initial_len)
	{
		if (flags->pointer)
			initial_len -= ft_print_0x(flags, &str, fd);
		if (**str == '-')
			initial_len -= ft_print_minus(flags, fd);
		while (flags->precision - initial_len - i++)
			flags->total_print += ft_putchar_ret_fd('0', fd);
	}
	else if (flags->precision == 0)
	{
		if (flags->pointer)
			ft_print_0x(flags, &str, fd);
		while (**str == '0')
			(*str)++;
	}
}
