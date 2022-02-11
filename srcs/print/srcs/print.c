/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:26:05 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/22 17:56:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

/* Print format on fd, format is formated like the printf function */

int	print(int fd, const char *format, ...)
{
	t_flags			flags;
	int				i;

	va_start(flags.args, format);
	initialize_flags(&flags, fd);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			flags.total_print += ft_putchar_ret_fd(format[i], fd);
		else if (format[i++] == '%')
		{
			i = get_flags(format, &flags, i);
			if (i == -1)
				return (-1);
			print_type(format, i, &flags, fd);
		}
		i++;
	}
	va_end(flags.args);
	return (flags.total_print);
}
