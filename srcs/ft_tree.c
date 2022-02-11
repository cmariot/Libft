/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 00:47:57 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/13 10:09:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_tree
{
	int				value;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*create_node(int value)
{
	t_tree	*new;

	new = ft_calloc(1, sizeof(t_tree));
	if (!new)
		return (NULL);
	else
	{
		new->value = value;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}

void	print_tabs(int numtab)
{
	int	i;

	i = 0;
	while (i < numtab)
	{
		printf("\t");
		i++;
	}
}

void	print_tree_rec(t_tree *root, int level)
{
	if (root == NULL)
	{
		printf("empty\n");
		return ;
	}
	if (level == 0)
		printf("Root ");
	printf("value = %d\n", root->value);
	print_tabs(level + 1);
	printf("Left ");
	print_tree_rec(root->left, level + 1);
	print_tabs(level + 1);
	printf("Right ");
	print_tree_rec(root->right, level + 1);
}

void	print_tree(t_tree *root)
{
	print_tree_rec(root, 0);
}

/*int	main(int argc, char **argv, char **env)
{
	t_tree	*t1;
	t_tree	*t2;
	t_tree	*t3;
	t_tree	*t4;
	t_tree	*t5;

	if (argc && *argv && *env)
	{
		t1 = create_node(10);
		t2 = create_node(11);
		t3 = create_node(13);
		t4 = create_node(14);
		t5 = create_node(18);
		t1->left = t2;
		t1->right = t3;
		t3->left = t4;
		t3->right = t5;
		print_tree(t1);
		free(t1);
		free(t2);
		free(t3);
		free(t4);
		free(t5);
	}
	return (0);
}*/
