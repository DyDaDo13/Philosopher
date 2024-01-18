/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:11:09 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/18 16:48:21 by dydado13         ###   ########.fr       */
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

void	destroy_mutexes(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_destroy(&data->mutex_fork[i]);
		pthread_mutex_destroy(&data->philo[i]->mutex_eat_fork);
	}
	pthread_mutex_destroy(&data->mutex_printf);
	//pthread_mutex_destroy(&data->mutex_status);
}
