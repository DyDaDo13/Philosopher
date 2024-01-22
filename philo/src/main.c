/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:07:49 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/22 16:44:11 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	start_dinner(t_data *data)
{
	long		i;

	data->start = get_time() + (data->n_philo * 2 * 10);
	i = -1;
	while (++i < data->n_philo)
	{
		data->philo[i]->last_meal = data->start;
		if (pthread_create(&data->philo[i]->thread, NULL,
				&philosopher, data->philo[i]) != 0)
			return (error_handler(data), false);
	}
	if (data->n_philo > 1)
	{
		if (pthread_create(&data->supervisor, NULL, &supervisor, data) != 0)
			return (error_handler(data), false);
	}
	return (true);
}

void	stop_dinner(t_data *data)
{
	long		i;

	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->philo[i]->thread, NULL);
	if (data->n_philo > 1)
		pthread_join(data->supervisor, NULL);
	destroy_mutexes(data);
	free_all(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (check_errors(ac, av) != 0)
		return (0);
	data = init_all(ac, av, data);
	if (!data)
		return (0);
	if (!start_dinner(data))
		return (0);
	stop_dinner(data);
	return (0);
}
