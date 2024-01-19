/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:07:49 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/19 15:44:01 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	start_dinner(t_data *data)
{
	long		i;

	data->start = get_time() + (data->n_philo * 2 * 10);
	i = -1;
	while (++i < data->n_philo)
		if (pthread_create(&data->philo[i]->thread, NULL,
			&philosopher, data->philo[i]) != 0)
			error_handler("Error : error while creating thread", data);
}

void	stop_dinner(t_data *data)
{
	long		i;

	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->philo[i]->thread, NULL);
	if (data->t_must_eat != 1)
		write_output(data);
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
	//printf("[%10ld]\t%s%03d\t%s\e[0m:fork[%d]\n", get_time() - data.start, "\e[31m", 3 + 1, "test", 0);
	stop_dinner(&data);
	free_all(&data);
	return (0);
}
