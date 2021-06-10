/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:17:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/10 18:14:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*special_case_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	else if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
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
