/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 15:49:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	initialize_flags(t_flags *flags, int fd)
{
	flags->fd = fd;
	flags->minus = 0;
	flags->zero = 0;
	flags->star_for_field_width = 0;
	flags->field_width = 0;
	flags->dot = 0;
	flags->star_for_precision = 0;
	flags->precision = 0;
	flags->total_print = 0;
	flags->minus_printed = 0;
	flags->pointer = 0;
	flags->blank = 0;
	flags->hashtag = 0;
	flags->plus = 0;
}

void	reset_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->star_for_field_width = 0;
	flags->field_width = 0;
	flags->dot = 0;
	flags->star_for_precision = 0;
	flags->precision = 0;
	flags->minus_printed = 0;
	flags->pointer = 0;
	flags->blank = 0;
	flags->hashtag = 0;
	flags->plus = 0;
}

unsigned int	ft_set_plus(t_flags *flags)
{
	flags->plus = 1;
	flags->blank = 0;
	return (1);
}

unsigned int	ft_set_star(t_flags *flags)
{
	flags->star_for_field_width = 1;
	return (1);
}

unsigned int	ft_set_zero(t_flags *flags)
{
	flags->zero = 1;
	return (1);
}
