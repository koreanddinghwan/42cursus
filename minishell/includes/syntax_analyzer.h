/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:20:12 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 14:16:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ANALYZER_H
# define SYNTAX_ANALYZER_H
# include "structs.h"
# include "cleaner.h"
# include "getter.h"
# define ERR_NEWLINE "`newline\'"
# define ERR_PIPE "`|\'"
# define ERR_REDIR_IN "`<\'"
# define ERR_REDIR_OUT "`>\'"
# define ERR_HEREDOC "`<<\'"
# define ERR_APPEND "`>>\'"

int	pipe_err(t_dlst *lst);
int	io_err(t_dlst *lst);
int	syntax_error_printer(char *str);
#endif
