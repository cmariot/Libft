/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:08:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/22 16:22:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;

	tmp = NULL;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}	
	return (tmp);
}

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

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = ft_lstlast(*(alst));
			tmp->next = new;
		}
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

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
	t_list *liste;
	t_list *new_list;
	
	liste = ft_lstnew("0\n");
	ft_lstadd_back(&liste, ft_lstnew("1\n"));
	ft_lstadd_back(&liste, ft_lstnew("2\n"));
	print_list(liste);
	new_list = ft_lstmap(liste, &free, &free); 
	print_list(new_list);
	return (0);
}
