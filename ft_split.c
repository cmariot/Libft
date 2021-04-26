/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:08 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/26 17:02:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	if (s[i - 1] != c)
		words++;
	return (words);
}

char	**malloc_strs(char const *s, char c, char **strs)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == c || s[i] == '\0')
		{
			strs[j] = malloc(sizeof(char) * (word_len + 1));
			if (strs[j] == NULL)
				return (NULL);
			while (s[i] == c)
				i++;
			j++;
			word_len = 0;
		}
		word_len++;
	}
	return (strs);
}

char	**fill_strs(char const *s, char c, char **strs, int words)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && j != words)
	{
		strs[j][word_len] = (unsigned char)s[i];
		i++;
		word_len++;
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			strs[j][word_len] = '\0';
			j++;
			word_len = 0;
		}
	}	
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		words;

	i = 0;
	words = count_words(s, c);
	strs = malloc(sizeof(char *) * (words + 1));
	if (strs == NULL)
		return (NULL);
	strs = malloc_strs(s, c, strs);
	strs = fill_strs(s, c, strs, words);
	return (strs);
}
