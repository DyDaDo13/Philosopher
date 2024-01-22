/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:40:06 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/22 15:07:42 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_sleep(t_data *data, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_time() + sleep_time;
	while (get_time() < wake_up)
	{
		if (has_dinner_stop(data))
			break ;
		usleep(20);
	}
}

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
