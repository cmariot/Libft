/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/10 09:51:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_return;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_return = 1;
	while (read_return)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
			return (NULL);
		buf[read_return] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else if (str != NULL)
			ft_add_buf_to_str(&str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (gnl_outpout(read_return, &str));
}

void	ft_add_buf_to_str(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	ft_strdel(str);
	*str = tmp;
	return ;
}

char	*ft_strdel(char **adr_str)
{
	if (adr_str != NULL && *adr_str != NULL)
	{
		free(*adr_str);
		*adr_str = NULL;
	}
	return (NULL);
}

char	*gnl_outpout(ssize_t read_return, char **str_input)
{
	int		len;
	char	*tmp;
	char	*str_return;

	if (read_return == 0 && **str_input == '\0')
	{
		ft_strdel(str_input);
		return (NULL);
	}
	len = 0;
	while ((*str_input)[len] != '\n' && (*str_input)[len] != '\0')
		len++;
	if ((*str_input)[len] == '\n')
	{
		str_return = ft_substr(*str_input, 0, len + 1);
		tmp = ft_strdup(&(*str_input)[len + 1]);
		ft_strdel(str_input);
		*str_input = tmp;
		return (str_return);
	}
	str_return = ft_substr(*str_input, 0, len);
	ft_strdel(str_input);
	return (str_return);
}
