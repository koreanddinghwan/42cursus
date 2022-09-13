/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_make_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:27:25 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 21:34:45 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_make_right(t_tree *main, t_tree *sub, void (del)(void *))
{
	if (main->right != NULL)
		ft_btree_inordertrav(main->right, del);
	main->right = sub;
}
