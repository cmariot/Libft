/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:27:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_field_width_star(t_flags *flags)
{
	flags->field_width = va_arg(flags->args, int);
	if (flags->field_width < 0)
	{
		flags->field_width = -(flags->field_width);
		flags->minus = 1;
	}
	flags->star_for_field_width = 0;
}

void	ft_precision_star(t_flags *flags)
{
	flags->precision = va_arg(flags->args, int);
	flags->star_for_precision = 0;
}
