/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:42:53 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 10:15:47 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "defines_enums.h"
# include "libft.h"

typedef struct s_token
{
	enum e_char_type	type;
	char				c;
}	t_token;

typedef struct s_lexer_token
{
	enum e_word_type	w_type;
	char				*buffer;
	int					buf_len;
	int					nth;
}	t_lexer_token;

typedef struct s_data
{
	char		*command;
	t_token		*tok_buf;
	t_dlst		*lexer_token_lst;
	t_envlst	*env_lst;
	char		**env;
	size_t		env_size;
	t_dlst		*cmd_lst;
	int			cmd_size;
	int			exit_status;
	int			pipe_exist;
}	t_data;

enum e_cmdtype
{
	E_CMD,
	E_BUILTIN,
};

typedef struct s_io_cont
{
	char				*filepath;
	enum e_word_type	type;
	char				*tmpname;
	int					fd;
}	t_io_cont;

typedef struct s_cmd_cont
{
	enum e_cmdtype	cmdtype;
	char			*cmd;
	char			**args;
	int				nth;
	t_dlst			*iolst;
	int				infile;
	int				outfile;
}	t_cmd_cont;

#endif
