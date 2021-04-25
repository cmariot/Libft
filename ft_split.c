/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:08 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/25 17:10:56 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int	i;
	int	j;
	int	k;
	int	words;

	i = 0;
	words = 1;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			words++;	
		}
		i++;
	}
	if (!(strs = malloc(sizeof(char *) * (words))))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == c || s[i] == '\0')
		{
		 	if (!(strs[j] = malloc(sizeof(unsigned char) * (k + 1))))
				return (NULL);
			while (s[i] == c)
				i++;
			j++;
			k = 0;
		}
		k++;
	}
	i = 0;
	j = 0;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && j != words)
	{
		strs[j][k] = (unsigned char)s[i];
		i++;
		k++;
		if (s[i] == c || s[i] == '\0')
		{
			while (s[i] == c)
				i++;
			strs[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	
	return (strs);
}
