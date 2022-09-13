/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:04:44 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 20:15:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	convert_to_arg(t_dlst *lst)
{
	while (lst && get_ltok_type(lst) == W_SPACE)
		lst = lst->next;
	while (lst && get_ltok_type(lst) == W_COMMAND)
		lst = lst->next;
	while (lst && get_ltok_type(lst) != W_PIPE)
	{
		if (get_ltok_type(lst) == W_SPACE
			|| (get_ltok_type(lst) >= 7
				&& get_ltok_type(lst) <= 10))
		{
			lst = lst->next;
			continue ;
		}
		else
		{
			get_ltok_cont(lst)->w_type = W_ARG;
			lst = lst->next;
		}
	}
	if (lst && get_ltok_type(lst) == W_PIPE)
		lst = lst->next;
	if (lst)
		convert_to_arg(lst);
}

void	do_change_file_deli(t_dlst *lst)
{
	enum e_word_type	type;

	type = get_ltok_type(lst);
	if (lst->next)
		lst = lst->next;
	else
		return ;
	while (lst && get_ltok_type(lst) == W_SPACE)
		lst = lst->next;
	if (lst)
	{
		while (lst && get_ltok_type(lst) != W_SPACE)
		{
			if (get_ltok_type(lst) >= 6)
				return ;
			if (type == 7)
				get_ltok_cont(lst)->w_type = W_DELIMETER;
			else if (type >= 8 && type <= 10)
				get_ltok_cont(lst)->w_type = W_FILE;
			lst = lst->next;
		}
	}
}

void	convert_file_delimeter(t_dlst *lst)
{
	while (lst)
	{
		if (get_ltok_type(lst) >= 7 && get_ltok_type(lst) <= 10)
			do_change_file_deli(lst);
		lst = lst->next;
	}
}

void	lexer_w_converter(t_data *data)
{
	t_dlst	*lst;

	lst = data->lexer_token_lst;
	convert_to_arg(lst);
	convert_file_delimeter(lst);
}
