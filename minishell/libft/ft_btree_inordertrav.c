/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_inordertrav.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:53:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 21:33:47 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_inordertrav(t_tree *node, void (action)(void *))
{
	if (node == NULL)
		return ;
	ft_btree_inordertrav(node->left, action);
	action(node->content);
	ft_btree_inordertrav(node->right, action);
}
