/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:13:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/06 15:44:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char			*new;
	unsigned int	end;

	if (!str)
		return (NULL);
	while (*str && ft_strchr(set, *str))
		str++;
	if (*str == '\0')
		return (ft_strdup(""));
	end = ft_strlen(str);
	while (end != 0 && ft_strchr(set, str[end]))
		end--;
	new = ft_substr((char *)str, 0, end + 1);
	if (!new)
		return (NULL);
	return (new);
}
