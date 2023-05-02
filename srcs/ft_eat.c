/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:48:46 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/12 08:49:00 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_take_fork(t_philo *philo, t_mutex *fork)
{
	int	rtn;

	pthread_mutex_lock(&fork->check_fork);
	rtn = fork->bool;
	if (fork->bool == true)
	{
		fork->bool = false;
		if (philo->table->alive == true)
		{
			printf("%lld %d has taken a fork\n",
				ft_get_ms_time() - philo->table->start_time, philo->id);
		}
	}
	return (rtn);
}

int	ft_time_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_last_eat);
	philo->last_eat = ft_get_ms_time();
	pthread_mutex_unlock(&philo->check_last_eat);
	return (EXIT_SUCCESS);
}

int	ft_eat_help(t_philo *philo)
{
	printf("%lld %d is eating\n",
		ft_get_ms_time() - philo->table->start_time, philo->id);
	ft_time_eat(philo);
	ft_ms_sleep(philo->table, philo->table->time_to_eat);
	pthread_mutex_lock(&philo->check_nb_eat);
	(philo->nb_of_eat)++;
	pthread_mutex_unlock(&philo->check_nb_eat);
	philo->left_fork.bool = true;
	philo->right_fork->bool = true;
	pthread_mutex_unlock(&philo->left_fork.check_fork);
	pthread_mutex_unlock(&philo->right_fork->check_fork);
	return (EXIT_SUCCESS);
}

int	ft_eat(t_philo *philo)
{
	while (philo->table->alive)
	{
		if (ft_take_fork(philo, &philo->left_fork) == true)
		{
			while (philo->table->alive)
			{
				if (ft_take_fork(philo, philo->right_fork) == true)
				{
					if (philo->table->alive == true)
					{
						ft_eat_help(philo);
						return (EXIT_SUCCESS);
					}
				}
				pthread_mutex_unlock(&philo->right_fork->check_fork);
			}
		}
		pthread_mutex_unlock(&philo->left_fork.check_fork);
	}
	return (EXIT_SUCCESS);
}
