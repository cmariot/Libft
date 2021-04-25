/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:17:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/25 17:20:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		n_cpy;
	int		n_len;
	char	*nombre;
	int		signe;
	char	*special_cas;

	if (n == 0)
	{
		special_cas = malloc(sizeof(char) * 2);
		if (special_cas == NULL)
			return (NULL);
		special_cas = ft_memcpy(special_cas, "0", 1);
		return (special_cas);
	}
	if (n == -2147483648)
	{
		special_cas = malloc(sizeof(char) * 12);
		if (special_cas == NULL)
			return (NULL);
		special_cas = ft_memcpy(special_cas, "-2147483648", 11);
		return (special_cas);
	}
	n_len = 0;
	signe = 1;
	if (n < 0)
	{
		n = -n;
		signe++;
		n_len++;
	}
	n_cpy = n;
	while (n_cpy != 0)
	{
		n_cpy = n_cpy / 10;
		n_len++;
	}
	nombre = malloc(sizeof(char) * (n_len + signe));
	if (nombre == NULL)
		return (NULL);
	nombre[n_len] = '\0';
	if (signe == 2)
		nombre[0] = '-';
	while (n != 0)
	{
		nombre[n_len - 1] = '0' + n % 10;
		n = n / 10;
		n_len--;
	}
	return (nombre);
}
