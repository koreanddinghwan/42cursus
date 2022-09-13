/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:11:40 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 14:46:59 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "structs.h"
# include "cleaner.h"
# include "getter.h"

t_lexer_token	*lexer_token_init(t_token *tok_buf);
int				syntax_analyzer(t_data *data);
void			lexer_decide_w_type(t_lexer_token *l_tok);
void			lexer_w_converter(t_data *data);
int				fork_builtin(char *str);
int				check_builtin(char *str);
void			replacer(t_data *data);
void			lexer_add_nth(t_data *data);
t_lexer_token	*lexer_space_token(void);
#endif
