/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_without_bn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:35:22 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/02 21:26:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_without_bn(int fd)
{
	char	*gnl_line;
	char	*new_line;

	gnl_line = get_next_line(fd);
	if (gnl_line)
	{
		new_line = ft_substr(gnl_line, 0, ft_strlen(gnl_line) - 1);
		free(gnl_line);
		return (new_line);
	}
	else
	{
		return (NULL);
	}
}
