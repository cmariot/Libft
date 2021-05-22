/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:19:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/22 13:02:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
/*
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

t_list *ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
		return (tmp);
	}
	else
		return (NULL);
}
*/
void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->content);
		list = list->next;
	}
}

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list *tmp;

	if (lst)
	{
		tmp = (lst)->next;
		del(lst);
		lst = tmp;
	}
}

int	main(void)
{
	t_list *liste = NULL;

	t_list *(*f)(void *);
	f = &ft_lstnew;
	ft_lstadd_back(&liste, ft_lstnew("1\n"));
	ft_lstadd_back(&liste, ft_lstnew("2\n"));
	ft_lstadd_back(&liste, f("3\n"));
	print_list(liste);
	ft_lstiter(liste, &free);
	print_list(liste);
	return (0);
} */
