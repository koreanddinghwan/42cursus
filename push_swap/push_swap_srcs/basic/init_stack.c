/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:00:09 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 14:14:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	dupcheck(t_dlst **a, int t)
{
	t_dlst	*cur;

	cur = *a;
	while (cur)
	{
		if (*((int *)cur->content) == t)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	init_stack(int ac, char **av, t_dlst **a)
{
	int		i;
	int		*t;
	t_dlst	*new;

	i = 1;
	while (i < ac)
	{
		t = ft_calloc(1, sizeof(int *));
		if (!t)
			call_error_av_stack_clear(a, av);
		*t = ft_atoi(av[i]);
		new = ft_dlst_new((void *)t);
		if (!num_avail_check(av[i]) || !new || !dupcheck(a, *t))
			break ;
		ft_dlst_pushback(a, new);
		i++;
	}
	if (i != ac)
		call_error_av_stack_clear(a, av);
}
