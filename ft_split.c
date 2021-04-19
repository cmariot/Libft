/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:08 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/18 22:33:46 by cmariot          ###   ########.fr       */
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
		{
			while (s[i] == c)
				i++;
			words++;	
		}
		i++;
	}
	if (!(strs = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
//	printf("chaine a couper : %s\n", s);
//	printf("nombre de mots : %d\n", words);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
		 	if (!(strs[j] = malloc(sizeof(char *) * (k + 1))))
				return (NULL);
//		 	printf("longueur mot %d : %d\n", j, k + 1);
			while (s[i] == c)
				i++;
			j++;
			k = 0;
		}
		i++;
		k++;
	}
	if (!(strs[j] = malloc(sizeof(char *) * (k + 1))))
		return (NULL);
//	printf("longueur mot %d : %d\n", j, k + 1);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			strs[j][k] = '\0';
//			printf("\n");
			j++;
			k = 0;
		}
		strs[j][k] = (unsigned char)s[i];
//		printf("%c", strs[j][k]);
		i++;
		k++;
	}
	strs[j][k] = '\0';
//	printf("\n");
	return (strs);
}
