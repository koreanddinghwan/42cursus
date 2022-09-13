/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:51 by myukang           #+#    #+#             */
/*   Updated: 2022/07/01 16:45:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETTER_H
# define GETTER_H

# include "structs.h"

t_lexer_token		*get_ltok_cont(t_dlst *lst);
enum e_word_type	get_ltok_type(t_dlst *lst);
t_cmd_cont			*get_cmd_cont(t_dlst *lst);
t_io_cont			*get_io_cont(t_dlst *lst);
char				*get_cmd(t_dlst *lst);
char				**get_args(t_dlst *lst);
t_dlst				*get_io_list(t_dlst *lst);
int					get_infile(t_dlst *lst);
int					get_outfile(t_dlst *lst);
char				*get_tmpname(t_dlst *iolst);

#endif
