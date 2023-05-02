/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:20:13 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/12 08:49:42 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_alfred(t_table *table)
{
	pthread_create(&table->alfred, NULL, &ft_check_dead, table);
	pthread_join(table->alfred, NULL);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ft_check_arg(ac, av))
		return (ft_error("Error: Arguments invalids"));
	if (ft_init(ac, av, &table))
		return (ft_error("Error: Initialization\n"));
	if (ft_start_thread(&table))
		return (ft_error("Error: Thread_create\n"));
	ft_alfred(&table);
	ft_wait_thread(&table);
	ft_free_all(&table);
	return (EXIT_SUCCESS);
}
