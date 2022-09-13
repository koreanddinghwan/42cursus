/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:36 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 11:15:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structs.h"
# include "path_finder.h"
# include "getter.h"
# include "cleaner.h"

char			*make_cmd(t_data *data);
char			*cmdpath_finder(t_envlst *envlst, char *cmd);
int				check_builtin(char *str);
enum e_cmdtype	get_cmdtype(char *cmd);
void			make_args(t_data *data, t_cmd_cont *cont);
t_cmd_cont		*init_cmd_cont(void);
t_dlst			*make_iolst(t_data *data);
int				get_offset(t_dlst *tok_lst, enum e_word_type type);
t_dlst			*wget_startpoint(t_dlst *cur, enum e_word_type type);
char			*wget_join(t_dlst *cur, enum e_word_type type);
void			delete_multiple_tokens(t_data *data, enum e_word_type type);
#endif
