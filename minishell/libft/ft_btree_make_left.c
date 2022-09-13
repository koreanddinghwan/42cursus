/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_make_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:27:26 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 21:34:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_make_left(t_tree *main, t_tree *sub, void (del)(void *))
{
	if (main->left != NULL)
		ft_btree_inordertrav(main->left, del);
	main->left = sub;
}
