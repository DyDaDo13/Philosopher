/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:40:06 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/11 13:32:56 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	wait_time(long time)
{
	long	actual_time;
	long	temp_time;
	actual_time = get_time();
	temp_time = get_time();
	while ((temp_time - actual_time) < time)
	{
		temp_time = get_time();
		usleep(20);
	}
}

void	wait_start(t_data *data, t_philo *philo)
{
	(void)philo;
	while (1)
	{
		pthread_mutex_lock(&data->mutex_status);
		if (data->state == 1)
		{
			pthread_mutex_unlock(&data->mutex_status);
			break;
		}
		pthread_mutex_unlock(&data->mutex_status);
		wait_time(1);
	}
	// while (1)
	// {
	// 	pthread_mutex_lock(&data->mutex_pair);
	// 	if (data->pair == 0)
	// 	{
	// 		if ((philo->nb_philo % 2) == 0)
	// 		{
	// 			pthread_mutex_unlock(&data->mutex_pair);
	// 			break;
	// 		}
	// 		else
	// 		{
	// 			wait_time(data->t_eat);
	// 			pthread_mutex_unlock(&data->mutex_pair);
	// 		}
	// 	}
	// 	pthread_mutex_unlock(&data->mutex_pair);
	// 	wait_time(1);
	// }
}
