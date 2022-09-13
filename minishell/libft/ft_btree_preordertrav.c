/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_preordertrav.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:00:33 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 21:34:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_preordertrav(t_tree *node, void (action)(void *))
{
	if (node == NULL)
		return ;
	action(node->content);
	ft_btree_preordertrav(node->left, action);
	ft_btree_preordertrav(node->right, action);
}
