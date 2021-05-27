/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:09:57 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/26 18:59:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = NULL;
	if (lst != NULL && lst->content != NULL && del != NULL)
	{
		tmp = lst;
		del(lst->content);
		lst = tmp->next;
	}
	del(tmp);
}
