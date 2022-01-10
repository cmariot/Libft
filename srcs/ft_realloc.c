/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:23:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/06 15:45:17 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(void *previous, char *new)
{
	char	*str;

	str = NULL;
	if (previous != NULL && new != NULL)
	{
		free(previous);
		str = ft_strdup(new);
	}
	return (str);
}
