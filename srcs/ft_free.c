/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:20:00 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/08 11:34:39 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_free_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philo)
	{
		pthread_mutex_destroy(&table->philos[i].left_fork.check_fork);
		pthread_mutex_destroy(&table->philos[i].check_last_eat);
		pthread_mutex_destroy(&table->philos[i].check_nb_eat);
		i++;
	}
	pthread_mutex_destroy(&table->write_permission);
	if (table->philos)
		free(table->philos);
	return (EXIT_FAILURE);
}
