/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:34:02 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/21 23:40:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

unsigned int	ft_set_prec(unsigned int i, t_flags *flgs, const char *frmt)
{
	flgs->dot = 1;
	i++;
	flgs->precision = 0;
	if (ft_isdigit(frmt[i]))
		while (ft_isdigit(frmt[i]))
			flgs->precision = flgs->precision * 10 + frmt[i++] - '0';
	else if (frmt[i] == '*')
	{
		flgs->star_for_precision = 1;
		i++;
	}
	return (i);
}

unsigned int	ft_set_minus(t_flags *flags)
{
	flags->minus = 1;
	return (1);
}

unsigned int	ft_set_blank(t_flags *flags)
{
	flags->blank = 1;
	return (1);
}

unsigned int	ft_set_hashtag(t_flags *flags)
{
	flags->hashtag = 1;
	return (1);
}

int	get_flags(const char *frmt, t_flags *flgs, unsigned int i)
{
	while (!ft_is_in_type_list(frmt[i]))
	{
		if (frmt[i] == '-')
			i += ft_set_minus(flgs);
		else if (frmt[i] == '0')
			i += ft_set_zero(flgs);
		else if (frmt[i] == '*')
			i += ft_set_star(flgs);
		else if (ft_isdigit(frmt[i]))
			while (ft_isdigit(frmt[i]))
				flgs->field_width = flgs->field_width * 10 + (frmt[i++] - '0');
		else if (frmt[i] == '.')
			i = ft_set_prec(i, flgs, frmt);
		else if (frmt[i] == ' ' && !flgs->plus)
			i += ft_set_blank(flgs);
		else if (frmt[i] == '#')
			i += ft_set_hashtag(flgs);
		else if (frmt[i] == '+')
			i += ft_set_plus(flgs);
		else
			return (-1);
	}
	return (i);
}
