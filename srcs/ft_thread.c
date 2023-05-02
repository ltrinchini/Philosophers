/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:50:31 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/11 10:05:32 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_start_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philo)
	{
		table->philos[i].last_eat = table->start_time;
		if (pthread_create(&table->philos[i].tid, NULL,
				&ft_routine, &table->philos[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_wait_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philo)
	{
		pthread_join(table->philos[i].tid, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}
