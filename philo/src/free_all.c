/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:11:09 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/22 16:40:19 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	free_all(t_data *data)
{
	long	i;

	i = -1;
	free(data->fork_locks);
	while (++i < (int)data->n_philo)
		free(data->philo[i]);
	free(data->philo);
	free(data);
}

void	destroy_mutexes(t_data *data)
{
	long		i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_destroy(&data->fork_locks[i]);
		pthread_mutex_destroy(&data->philo[i]->meal_time_lock);
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->sim_stop_lock);
}
