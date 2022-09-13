/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:45:06 by myukang           #+#    #+#             */
/*   Updated: 2022/05/10 19:22:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <signal.h>

typedef struct s_server
{
	int				requested_num;
	unsigned char	charactor;
}	t_server;

#endif
