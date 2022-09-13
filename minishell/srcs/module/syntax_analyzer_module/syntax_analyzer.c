/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:01:22 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 16:46:24 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * syntax_analyzer
 *
 * ++++258 case1
 * bash-3.2$ cat > |
 * bash: syntax error near unexpected token `|'
 * bash-3.2$ $?
 * bash: 258: command not found
 *
 * ++++258 case2
 * bash-3.2$ cat >|
 * bash: syntax error near unexpected token `newline'
 *
 * ++++case3 : closed redirection by pipe  => ignore pipe
 * bash-3.2$ echo >| cat
 * bash-3.2$ ls
 * cat
 * bash-3.2$ cat cat

 * */

#include "syntax_analyzer.h"

int	syntax_error(t_dlst *lst)
{
	if (pipe_err(lst) == FAIL)
		return (TRUE);
	if (io_err(lst) == FAIL)
		return (TRUE);
	return (FALSE);
}

int	syntax_analyzer(t_data *data)
{
	t_dlst	*lexer_token_lst;

	if (!data)
		return (FAIL);
	lexer_token_lst = data->lexer_token_lst;
	if (!lexer_token_lst)
		return (FAIL);
	if (syntax_error(lexer_token_lst) == TRUE)
	{
		data->exit_status = EX_USAGE;
		return (FAIL);
	}
	return (SUCESS);
}
