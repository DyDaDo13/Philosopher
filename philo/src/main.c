/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:07:49 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/18 11:23:09 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	free(data->mutex_fork);
	while (++i < (int)data->n_philo)
		free(data->philo[i]);
	free(data->philo);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_errors(ac, av);
	init_all(ac, av, &data);
	free_all(&data);
	return (0);
}
