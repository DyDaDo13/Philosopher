/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:07:49 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/18 16:50:52 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	start_dinner(t_data *data)
{
	int		i;

	data->start = get_time() + (data->n_philo * 2 * 10);
	i = -1;
	while (++i < data->n_philo)
		if (pthread_create(data->philo[i]->thread, NULL,
			&philosopher, data->philo[i]) != 0)
			error_handler("Error : error while creating thread", data);
}

void	stop_dinner(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->philo[i]->thread, NULL);
	// if (data->t_must_eat != 1)
	// 	write(ouput);
	destroy_mutexes(data);
	free_all(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_errors(ac, av) != 0)
		return (0);
	init_all(ac, av, &data);
	start_dinner(&data);
	stop_dinner(&data);
	//free_all(&data);
	return (0);
}
