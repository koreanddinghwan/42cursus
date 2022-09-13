/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:27:43 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 16:46:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * case1 : start with | command
 * case2 : multiline pipe 'cmd |'
 * case3 : double pipe list cmd || cmd and cmd | | cmd
 * */

#include "syntax_analyzer.h"

int	startwith_pipe(t_dlst *lst)
{
	enum e_word_type	type;

	type = get_ltok_type(lst);
	if (type == W_SPACE || type == W_PIPE)
	{
		while (lst && get_ltok_type(lst) == W_SPACE)
			lst = lst->next;
		if (lst && get_ltok_type(lst) == W_PIPE)
			return (TRUE);
	}
	return (FALSE);
}

int	double_pipe(t_dlst *lst)
{
	while (lst)
	{
		if (get_ltok_type(lst) == W_PIPE)
		{
			lst = lst->next;
			if (lst)
			{
				while (lst && get_ltok_type(lst) == W_SPACE)
					lst = lst->next;
				if (lst && get_ltok_type(lst) == W_PIPE)
					return (TRUE);
			}
		}
		if (lst)
			lst = lst->next;
	}
	return (FALSE);
}

int	endwith_pipe(t_dlst *lst)
{
	t_dlst	*last;

	last = ft_dlst_last(lst);
	if (get_ltok_type(lst) == W_SPACE)
	{
		while (get_ltok_type(lst) == W_SPACE)
		{
			if (last)
				last = last->back;
			lst = lst->next;
		}
		if (get_ltok_type(lst) == W_PIPE)
			return (TRUE);
	}
	else if (get_ltok_type(lst) == W_PIPE)
		return (TRUE);
	return (FALSE);
}

int	pipe_err(t_dlst *lst)
{
	if (startwith_pipe(lst) == TRUE)
		return (syntax_error_printer(ERR_PIPE));
	if (double_pipe(lst) == TRUE)
		return (syntax_error_printer(ERR_PIPE));
	if (endwith_pipe(lst) == TRUE)
		return (syntax_error_printer(ERR_NEWLINE));
	return (SUCESS);
}
