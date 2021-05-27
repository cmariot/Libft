/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:55:01 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/26 18:50:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	char	*ret;

	str = malloc(sizeof(char) * (len + 1));
	if (s == NULL || str == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	ret = ft_strdup(str);
	free(str);
	return (ret);
}
