/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:15:46 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/01 11:16:09 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (EXIT_FAILURE);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isnum(av[i][j]) || ft_atoi(av[i]) <= 0)
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
