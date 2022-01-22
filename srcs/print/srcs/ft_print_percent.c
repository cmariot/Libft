/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:30:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_print_percent(t_flags *flags, int fd)
{
	if (flags->star_for_field_width)
		ft_field_width_star(flags);
	if (flags->field_width && !flags->minus)
		ft_print_space(flags, 1, fd);
	flags->total_print += ft_putchar_ret_fd('%', fd);
	if (flags->field_width && flags->minus)
		ft_print_space(flags, 1, fd);
	reset_flags(flags);
}
