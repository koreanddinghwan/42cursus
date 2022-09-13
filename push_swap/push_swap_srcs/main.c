/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:56:43 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 15:03:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_av(char **av)
{
	int	i;

	i = 1;
	while (av[i] != 0)
		free(av[i++]);
}

int	main(int ac, char **av)
{
	t_dlst	*a;
	int		*list;
	int		changed_ac;

	a = 0;
	list = 0;
	if (ac == 1)
		exit(1);
	changed_ac = init_argv(ac, &av);
	init_stack(changed_ac, av, &a);
	init_list(&list, &a, ft_dlst_size(a), av);
	sort_stack(list, &a, list_sort_check(list, ft_dlst_size(a)), av);
	ft_dlst_clear(&a, free);
	free(list);
	free_av(av);
	exit(0);
}
