/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_postordertrav.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:02:06 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 21:34:14 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_postordertrav(t_tree *node, void (action)(void *))
{
	if (node == NULL)
		return ;
	ft_btree_inordertrav(node->left, action);
	ft_btree_inordertrav(node->right, action);
	action(node->content);
}
