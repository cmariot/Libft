/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:08:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/23 13:18:24 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	ft_putstr("\nDebut fonction\n");
	t_list *new_lst;
	t_list *tmp;
	int i;

	if (!lst || !f || !del)
		return (NULL);
	i = 0;
	while (lst)
	{
		ft_putstr("iteration\n");
		tmp = ft_lstnew(f(lst->content));
		ft_putstr("f applique au contenu de lst\n");
		if (i == 0)
		{
			new_lst = ft_lstnew(tmp->content);
			ft_putstr("nouvelle liste\n");
		}
		else
		{
			ft_lstadd_back(&new_lst, tmp);
			ft_putstr("ajout element\n");
		}
		ft_lstclear(&tmp, del);
		lst = (lst)->next;
		i++;
	}
	ft_putstr("Liste new_list\n");
	print_list(new_lst);
	ft_putstr("Liste tmp\n");
	print_list(tmp);
	ft_putstr("fin fonction\n");
	return (new_lst);
}


int	main(void)
{
	t_list *liste;
	t_list *new_list;
	
	liste = ft_lstnew("0\n");
	ft_lstadd_back(&liste, ft_lstnew("1\n"));
	ft_lstadd_back(&liste, ft_lstnew("2\n"));
	ft_lstadd_back(&liste, ft_lstnew("3\n"));
	ft_putstr("ancienne liste\n");
	print_list(liste);
	new_list = ft_lstmap(liste, &VOID, &free); 
	ft_putstr("\nnew liste\n");
	print_list(new_list);
	return (0);
}

