/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:12:44 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/12 08:44:29 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

static int	ft_init_philo(t_table *tab)
{
	int	i;

	i = 0;
	while (i < tab->nb_of_philo)
	{
		tab->philos[i].id = i + 1;
		tab->philos[i].nb_of_eat = 0;
		tab->philos[i].left_fork.bool = true;
		pthread_mutex_init(&tab->philos[i].left_fork.check_fork, NULL);
		pthread_mutex_init(&tab->philos[i].check_last_eat, NULL);
		pthread_mutex_init(&tab->philos[i].check_nb_eat, NULL);
		tab->philos[i].right_fork = &tab->philos[(i + 1)
			% tab->nb_of_philo].left_fork;
		tab->philos[i].table = tab;
		i++;
	}
	tab->start_time = ft_get_ms_time();
	return (EXIT_SUCCESS);
}

int	ft_init(int ac, char **av, t_table *table)
{
	table->nb_of_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->alive = 1;
	if (ac == 6)
		table->nb_of_must_eat = ft_atoi(av[5]);
	else
		table->nb_of_must_eat = -1;
	if (pthread_mutex_init(&table->write_permission, NULL))
		return (EXIT_FAILURE);
	table->philos = malloc(sizeof(t_philo) * table->nb_of_philo);
	if (!table->philos)
		return (EXIT_FAILURE);
	return (ft_init_philo(table));
}
