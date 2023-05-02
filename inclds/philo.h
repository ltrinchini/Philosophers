/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:30:15 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/12 08:51:38 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_boolean
{
	false,
	true	
}	t_boolean;

typedef struct timeval	t_timeval;
typedef struct s_table	t_table;

// Structs
typedef struct s_mutex
{
	t_boolean		bool;
	pthread_mutex_t	check_fork;
}	t_mutex;

typedef struct s_philo
{
	int				id;
	int				nb_of_eat;
	t_mutex			left_fork;
	t_mutex			*right_fork;
	t_table			*table;
	pthread_t		tid;
	pthread_mutex_t	check_last_eat;
	pthread_mutex_t	check_nb_eat;
	long long		last_eat;
	long long		start;
}	t_philo;

typedef struct s_table
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_must_eat;
	char			alive;
	pthread_mutex_t	write_permission;
	t_philo			*philos;
	pthread_t		alfred;
	long long		start_time;
}	t_table;

// Tools Functions
int			ft_atoi(const char *str);
int			ft_isnum(int c);
int			ft_error(char *str);
int			ft_free_all(t_table *table);

// Init Functions
int			ft_check_arg(int ac, char **av);
int			ft_init(int ac, char **av, t_table *table);

// Thread Functions
int			ft_start_thread(t_table *table);

// Alfred Functions
int			ft_alfred(t_table *table);
void		*ft_check_dead(void *ptr);

// Routine Functions
void		*ft_routine(void *ptr);
int			ft_eat(t_philo *philo);

// Time Functions
long long	ft_get_ms_time(void);
int			ft_ms_sleep(t_table *table, int msec);
int			ft_wait_thread(t_table *table);

#endif
