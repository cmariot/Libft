/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:08:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/23 10:16:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_elmt;
	t_list *new_lst;

	new_lst = NULL;
	while (lst)
	{
		new_elmt = ft_lstnew(f(lst));
		ft_lstadd_back(&new_lst, new_elmt);
		del(lst);
	}
	return (new_lst);
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

void *VOID(void *lol)
{
	return (lol);
}

int	main(void)
{
	t_list *liste;
	t_list *new_list;
	
	liste = ft_lstnew("0\n");
	ft_lstadd_back(&liste, ft_lstnew("1\n"));
	ft_lstadd_back(&liste, ft_lstnew("2\n"));
	print_list(liste);
	new_list = ft_lstmap(liste, &VOID, &free); 
	print_list(new_list);
	return (0);
}
