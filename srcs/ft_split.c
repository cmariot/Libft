/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:14:08 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/11 11:37:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			i = 1;
			words++;
		}
		s++;
	}
	return (words);
}

static void	get_next_len_str(char **strs, unsigned int *str_len, char c)
{
	unsigned int	i;

	*strs = *strs + *str_len;
	*str_len = 0;
	i = 0;
	while (**strs && **strs == c)
		(*strs)++;
	while ((*strs)[i])
	{
		if ((*strs)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	int				words;
	int				i;
	char			*str;
	unsigned int	str_len;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	strs = malloc(sizeof(char *) * (words + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	str = (char *)s;
	str_len = 0;
	while (i < words)
	{
		get_next_len_str(&str, &str_len, c);
		strs[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (strs[i] == NULL)
			return (NULL);
		ft_strlcpy(strs[i++], str, str_len + 1);
	}
	strs[i] = NULL;
	return (strs);
}
