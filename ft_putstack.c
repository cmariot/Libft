/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:04:41 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/12 18:16:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstack(int *a, char c, int stack_size)
{
	int	i;
	int	len;

	ft_putstr_fd("\n --- Stack ", 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd(" ---\n", 1);
	i = 0;
	len = 0;
	while (stack_size--)
	{
		ft_putchar_fd(c, 1);
		ft_putchar_fd('[', 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("] = ", 1);
		len = ft_intlen(a[i]);
		while (len++ != 11)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(a[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
