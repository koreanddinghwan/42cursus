/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:46:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 20:57:36 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * io_error -> special token after io redirection token
 * */

#include "syntax_analyzer.h"

char	*get_err_message(enum e_word_type type)
{
	if (type == W_REDIRECTION_INPUT)
		return (ERR_REDIR_IN);
	else if (type == W_REDIRECTION_OUTPUT)
		return (ERR_REDIR_OUT);
	else if (type == W_APPENDING_TO)
		return (ERR_APPEND);
	else if (type == W_HERE_DOC)
		return (ERR_HEREDOC);
	else
		return (ERR_PIPE);
}

static int	is_io(t_dlst *lst)
{
	enum e_word_type	type;

	type = get_ltok_type(lst);
	if (type >= 7 && type <= 10)
		return (TRUE);
	else
		return (FALSE);
}

int	endwith_io(t_dlst *lst)
{
	t_dlst	*last;

	last = ft_dlst_last(lst);
	if (get_ltok_type(last) == W_SPACE)
	{
		while (get_ltok_type(last) == W_SPACE)
			last = last->back;
		if (is_io(last) == TRUE)
			return (TRUE);
	}
	else if (get_ltok_type(last) >= 7
		&& get_ltok_type(last) <= 10)
		return (TRUE);
	return (FALSE);
}

int	ioafter_io(t_dlst *lst, enum e_word_type *type)
{
	enum e_word_type	cur;

	while (lst)
	{
		if (is_io(lst) == TRUE)
		{
			lst = lst->next;
			while (lst && get_ltok_type(lst) == W_SPACE)
				lst = lst->next;
			if (lst)
			{
				cur = get_ltok_type(lst);
				if (cur >= 5 && cur <= 10)
				{
					*type = cur;
					return (TRUE);
				}
			}
		}
		if (lst)
			lst = lst->next;
	}
	return (FALSE);
}

int	io_err(t_dlst *lst)
{
	enum e_word_type	type;

	if (ioafter_io(lst, &type) == TRUE)
		return (syntax_error_printer(get_err_message(type)));
	if (endwith_io(lst) == TRUE)
		return (syntax_error_printer(ERR_NEWLINE));
	return (SUCESS);
}
