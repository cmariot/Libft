/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:32:40 by cmariot           #+#    #+#             */
/*   Updated: 2022/02/03 19:19:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_new_str_len(char *sep, char **array)
{
	int		str_len;
	int		i;

	str_len = -ft_strlen(sep);
	i = 0;
	while (array[i] != NULL)
		str_len += ft_strlen(array[i++]) + ft_strlen(sep);
	return (str_len);
}

char	*join_array(char **array, char *sep)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	str = ft_calloc(get_new_str_len(sep, array) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (array[i] != NULL)
	{
		k = 0;
		while (array[i][k] != '\0')
			str[j++] = array[i][k++];
		if (array[i + 1] == NULL)
			break ;
		k = 0;
		while (sep[k] != '\0')
			str[j++] = sep[k++];
		i++;
	}
	return (str);
}
