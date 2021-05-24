/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:08:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/23 18:31:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_putstr(char *str)
{
	if (str)
		while (*str)
			write(1, str++, 1);
}

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->content);
		list = list->next;
	}
}

void *VOID(void *lol)
{
//	lol = NULL;
	return (lol);
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	tmp = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!(tmp->next))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_lst);
}

/*
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *tmp;
	int i;

	if (!lst || !f)
		return (NULL);
	i = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (i == 0)
			new_lst = ft_lstnew(tmp->content);
		else
			ft_lstadd_back(&new_lst, tmp);
		lst = (lst)->next;
		i++;
	}
	ft_lstclear(&tmp, del);
	return (new_lst);
}


int	main(void)
{
	t_list *liste;
	t_list *new_list;
	t_list *test;
	
	liste = ft_lstnew("0\n");
	ft_lstadd_back(&liste, ft_lstnew("1\n"));
	ft_lstadd_back(&liste, ft_lstnew("2\n"));
	ft_lstadd_back(&liste, ft_lstnew("3\n"));
	ft_putstr("ancienne liste\n");
	print_list(liste);
	new_list = ft_lstmap(liste, &VOID, &free);
	test = ft_lstmap2(liste, &VOID, &free);
	ft_putstr("\nnew liste\n");
	print_list(new_list);
	print_list(test);
	return (0);
}
*/
