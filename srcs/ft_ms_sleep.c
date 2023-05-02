/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:50:33 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/12 08:53:37 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_ms_sleep(t_table *table, int msec)
{
	long long	start;

	start = ft_get_ms_time();
	usleep(0.9 * msec);
	while (ft_get_ms_time() - start <= msec && table->alive == true)
	{
		usleep(100);
	}
	return (EXIT_SUCCESS);
}
