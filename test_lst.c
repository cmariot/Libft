/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:11:04 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/21 10:43:27 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

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

t_list *ft_add_list(t_list *list, void *content)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = content;
		tmp->next = list;
	}
	return (tmp);
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

void ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

int ft_lstsize(t_list *lst)
{
	int size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_list *ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst)
			lst = lst->next;
	}
	return (lst);
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

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		del(*lst);
		*lst = tmp;
	}
}

int main()
{
	t_list	*list;

	list = NULL;
	list = ft_lstnew("tutu\n");
	ft_lstadd_front(&list, ft_add_list(list, "toto\n"));
	list = ft_add_list(list, "titi\n");
	list =ft_add_list(list, "DELONE\n");
//	delfirst(list);
	ft_lstclear(&list, &free);	
	print_list(list);
	printf("%d\n", ft_lstsize(list));
	return (0);
}


