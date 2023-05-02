/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:05:50 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/12 08:49:08 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_sleep(t_philo *philo)
{
	if (philo->table->alive == true)
	{
		printf("%lld %d is sleeping\n",
			ft_get_ms_time() - philo->table->start_time, philo->id);
		ft_ms_sleep(philo->table, philo->table->time_to_sleep);
	}
	return (EXIT_SUCCESS);
}

int	ft_think(t_philo *philo)
{
	if (philo->table->alive == true)
	{
		printf("%lld %d is thinking\n",
			ft_get_ms_time() - philo->table->start_time, philo->id);
	}
	return (0);
}

void	*ft_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(100);
	while (philo->table->alive == true)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
