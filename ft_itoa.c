/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:17:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/26 18:41:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include <stdlib.h>

char	*special_case_itoa(int n)
{
	char	*special_cas;

	if (n == 0)
	{
		special_cas = malloc(sizeof(char) * 2);
		if (special_cas == NULL)
			return (NULL);
		special_cas = ft_memcpy(special_cas, "0", 1);
		return (special_cas);
	}
	else if (n == -2147483648)
	{
		special_cas = malloc(sizeof(char) * 12);
		if (special_cas == NULL)
			return (NULL);
		special_cas = ft_memcpy(special_cas, "-2147483648", 11);
		return (special_cas);
	}
	else
		return (NULL);
}

int	int_len(int n)
{
	int	n_len;

	n_len = 0;
	while (n != 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

char	*int_to_array(int signe, char *nombre, int n, int n_len)
{
	nombre[n_len] = '\0';
	if (signe == 1)
		nombre[0] = '-';
	while (n != 0)
	{
		nombre[n_len - 1] = '0' + n % 10;
		n = n / 10;
		n_len--;
	}
	return (nombre);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*nombre;
	int		signe;
	char	*special_case;

	special_case = special_case_itoa(n);
	if (special_case != NULL)
		return (special_case);
	n_len = int_len(n);
	signe = 0;
	if (n < 0)
	{
		n = -n;
		signe++;
		n_len++;
	}
	nombre = malloc(sizeof(char) * (n_len + signe));
	if (nombre == NULL)
		return (NULL);
	nombre = int_to_array(signe, nombre, n, n_len);
	return (nombre);
}
