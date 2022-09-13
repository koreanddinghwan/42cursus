/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_decide_w_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:02:03 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 13:13:19 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	fork_builtin(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(S_ECHO, str) == 0)
		return (1);
	if (ft_strcmp(ENV, str) == 0)
		return (1);
	if (ft_strcmp(PWD, str) == 0)
		return (1);
	if (ft_strcmp(CD, str) == 0)
		return (0);
	if (ft_strcmp(EXPORT, str) == 0)
		return (0);
	if (ft_strcmp(UNSET, str) == 0)
		return (0);
	if (ft_strcmp(EXIT, str) == 0)
		return (0);
	return (1);
}

int	check_builtin(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(S_ECHO, str) == 0)
		return (1);
	if (ft_strcmp(CD, str) == 0)
		return (1);
	if (ft_strcmp(PWD, str) == 0)
		return (1);
	if (ft_strcmp(EXPORT, str) == 0)
		return (1);
	if (ft_strcmp(UNSET, str) == 0)
		return (1);
	if (ft_strcmp(ENV, str) == 0)
		return (1);
	if (ft_strcmp(EXIT, str) == 0)
		return (1);
	return (0);
}

int	check_spec_token(char *str)
{
	if (ft_strcmp(str, " ") == 0)
		return (0);
	if (ft_strcmp(str, "|") == 0)
		return (W_PIPE);
	else if (ft_strcmp(str, "<<") == 0)
		return (W_HERE_DOC);
	else if (ft_strcmp(str, ">>") == 0)
		return (W_APPENDING_TO);
	else if (ft_strcmp(str, "<") == 0)
		return (W_REDIRECTION_INPUT);
	else if (ft_strcmp(str, ">") == 0)
		return (W_REDIRECTION_OUTPUT);
	return (0);
}

int	get_word_type(char *str)
{
	if (check_spec_token(str))
		return (check_spec_token(str));
	else
		return (W_COMMAND);
}

void	lexer_decide_w_type(t_lexer_token *l_tok)
{
	char	*str;

	str = l_tok->buffer;
	l_tok->w_type = get_word_type(str);
}
