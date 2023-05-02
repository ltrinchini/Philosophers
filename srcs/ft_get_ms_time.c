/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ms_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:54:29 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/11 10:14:19 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

long long	ft_get_ms_time(void)
{
	t_timeval	time;
	long long	rtn;

	gettimeofday(&time, NULL);
	rtn = time.tv_sec * 1000;
	rtn += (time.tv_usec / 1000);
	return (rtn);
}
