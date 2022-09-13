/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_enums.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:44:39 by myukang           #+#    #+#             */
/*   Updated: 2022/07/01 18:15:46 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_ENUMS_H
# define DEFINES_ENUMS_H

# define S_ECHO	"echo"
# define CD		"cd"
# define PWD	"pwd"
# define EXPORT	"export"
# define UNSET	"unset"
# define ENV	"env"
# define EXIT	"exit"
# define SUCESS	1
# define FAIL	0
# define NOFILE ": No such file or directory"
# define ISDIR ": is a directory"
# define DENY ": Permission denied"
# define CMDNOTFOUND ": command not found"

enum	e_char_type
{
	NORM = 1,
	PIPE = '|',
	LESSER = '<',
	GREATER = '>',
	DQUO = '\"',
	SQUO = '\'',
	SPC = ' ',
	END_C = '\0'
};

enum	e_word_type
{
	W_COMMAND = 0,
	W_BUILTIN = 1,
	W_ARG = 2,
	W_SPACE = 3,
	W_OPTION = 4,
	W_FILE = 5,
	W_PIPE = 6,
	W_HERE_DOC = 7,
	W_APPENDING_TO = 8,
	W_REDIRECTION_INPUT = 9,
	W_REDIRECTION_OUTPUT = 10,
	W_DELIMETER = 11
};

enum	e_state
{
	STATE_SQUOTE,
	STATE_DQUOTE,
	STATE_NORMAL
};

# define TRUE 1
# define FALSE 0
# define EXECUTION_FAILURE 1
# define EXECUTION_SUCCESS 0
# define EX_NOEXEC	126
# define EX_NOTFOUND	127
# define EX_BADSYNTAX	257
# define EX_USAGE	258	/* syntax error in usage */
#endif
