/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:08 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/17 11:36:47 by cmariot          ###   ########.fr       */
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
	while (s[i] != '\0')
	{
		if (s[i] == c)
			words++;	
		i++;
	}
	if (!(strs = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
		 	if (!(strs[j] = malloc(sizeof(char *) * (k + 1))))
				return (NULL);
		 	i++;
			j++;
			k = 0;
		}
		strs[j][k] = s[i];
		i++;
		k++;
	}
	//Compter le nombres de lettres + 1
	//Creer les mots avec malloc
	//Initialiser



	strs = NULL;
	return (strs);
}
