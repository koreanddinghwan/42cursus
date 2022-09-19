/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:30:08 by myukang           #+#    #+#             */
/*   Updated: 2022/05/30 13:12:04 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# define FORK 0
# define LFORK -1
# define FORK_MSG "has taken a fork\n"
# define EAT 1
# define EAT_MSG "is eating\n"
# define SLEEP 2
# define SLEEP_MSG "is sleeping\n"
# define THINK 3
# define THINK_MSG "is thinking\n"
# define DIE 4
# define DIE_MSG "died\n"
# define DEAD -4
# define ALIVE 5
# define OVER 0
# define NOTOVER 1
# define FAIL 0
# define SUCCESS 1
# define HUNGRY 0
# define FULL 1

/*
 * each philosopher's data
 * */
typedef struct s_phdata
{
	int			nth;
	int			left_idx;
	int			right_idx;
	long long	last_eat;
	int			total_eat;
	int			is_full;
	long long	ph_init_time;
}	t_phdata;

/*
 * main data
 * isdead used in printing message
 * so if a philosophers dead but another thread occupy
 * write mutex, prevent printing any message in term
 * */
typedef struct s_data
{
	int				num;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				times_must_eat;
	long long		init_time;
	int				isdead;
	pthread_t		t_reaper;
	pthread_mutex_t	*write;
	pthread_mutex_t	*status;
	pthread_mutex_t	*forks;
	t_phdata		*phdata;
	pthread_t		*t_arr;
}	t_data;

typedef struct s_param
{
	t_data		*data;
	t_phdata	*phdata;
}	t_param;
/*
 * ft_tools
 * */
long long	ft_strlen(char *str);
int			ft_atoi(const char *str);
/*
 * argument validation tools
 * */
int			validate_struct_num(t_data *data, char **av);
int			check_num(char *str);
int			validate_av_num(char **av);
int			ac_err(int ac);
/*
 * print tools
 * */
int			write_msg(t_data *data, long long time, t_phdata *phdata, int type);
void		print_total_eat(t_data *data);
/*
 * data_free tools
 * */
void		all_free(t_data *data);
void		data_free(t_data *data);
void		all_free(t_data *data);
/*
 * time tools
 * */
long long	t_diff(long long t);
long long	t_now(void);
void		t_usleep(long long t_obj, int sleep_time);
/*
 * init
 * */
int			init_data(t_data **data, int ac, char **av);
int			init_memory(t_data *data);
int			init_data_mem(t_data **data);
int			init_mutex(t_data *data);
/*
 * thread and routines
 * */
int			init_thread(t_data *data);
int			join_thread(t_data *data);
void		*philo(void *param);
void		*reaper(void *param);
/*
 * actions
 * */
int			eating(t_data *data, t_phdata *phdata);
int			sleeping(t_data *data, t_phdata *phdata);
int			thinking(t_data *data, t_phdata *phdata);
int			check_dead(t_data *data, t_phdata *phdata);
int			check_meal(t_data *data);

#endif
