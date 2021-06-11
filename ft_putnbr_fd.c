/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:26:31 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/28 10:52:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		*base_dec;

	nb = n;
	base_dec = "0123456789";
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if ((nb >= 0) && (nb <= 9))
	{
		write(fd, &base_dec[nb], 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		write(fd, &base_dec[nb % 10], 1);
	}
}
