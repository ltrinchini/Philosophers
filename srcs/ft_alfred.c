/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alfred.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:54:15 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/12 08:51:57 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

static long long	ft_time_last_eat(t_philo *philo)
{
	long long	rtn;

	pthread_mutex_lock(&philo->check_last_eat);
	rtn = philo->last_eat;
	pthread_mutex_unlock(&philo->check_last_eat);
	return (rtn);
}

static int	ft_nb_eat(t_philo *philo)
{
	int	rtn;

	pthread_mutex_lock(&philo->check_nb_eat);
	rtn = philo->nb_of_eat;
	pthread_mutex_unlock(&philo->check_nb_eat);
	return (rtn);
}

static int	ft_help_alfred(t_table *table, int i, int *j)
{
	if (table->nb_of_must_eat != -1)
	{
		if (ft_nb_eat(&table->philos[i]) == table->nb_of_must_eat)
		{
			(*j)++;
		}
		if (*j == table->nb_of_philo)
		{
			memset(&table->alive, 0, sizeof(char));
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

static int	ft_kill(t_philo *philo)
{
	memset(&philo->table->alive, 0, sizeof(char));
	printf("%lld %d is died\n", ft_get_ms_time()
		- philo->table->start_time, philo->id);
	if (philo->table->nb_of_philo == 1)
		pthread_mutex_unlock(&philo->right_fork->check_fork);
	return (EXIT_SUCCESS);
}

void	*ft_check_dead(void *ptr)
{
	int		i;
	int		j;
	t_table	*table;

	i = 0;
	j = 0;
	table = (t_table *)ptr;
	while (1)
	{
		if (i == table->nb_of_philo)
			i = 0;
		if (ft_get_ms_time()
			- ft_time_last_eat(&table->philos[i]) >= table->time_to_die)
		{
			ft_kill(&table->philos[i]);
			usleep(1000);
			return (NULL);
		}
		if (ft_help_alfred(table, i, &j) == EXIT_SUCCESS)
			return (NULL);
		i++;
	}
	return (NULL);
}
