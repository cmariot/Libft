/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:13:45 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/20 20:04:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	int		s1_len;
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	if (ft_memcmp(s1, set, ft_strlen(set)) == 0)
		start = ft_strlen(set);
	end = ft_strlen(s1);
	while (end != 0 && ft_strchr(set, s1[end]))
		end--;
	str = ft_substr((char*)s1, (0 + start), (end + 1));
	return (str);
}
