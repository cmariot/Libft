/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:29:27 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/14 16:36:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	s1_size;
	int	i;

	s1_size = 0;
	while (*s1)
	{
		s1_size++;
		s1++;
	}
	if (!(str = malloc(sizeof(char) * s1_size + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == set[i] && i == 0)
			i++;
		else if (s1[s1_size - 1] == set && i == (s1_size - 1))
			i++;
		else
		{
			str[i] = s1[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
