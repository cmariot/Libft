/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isadirectory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:52:22 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/10 12:32:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if path is a directory */

bool	ft_isadirectory(char *path)
{
	DIR	*fd_dir;

	fd_dir = opendir(path);
	if (fd_dir == NULL)
	{
		return (FALSE);
	}
	else
	{
		closedir(fd_dir);
		return (TRUE);
	}
}
