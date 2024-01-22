/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:35:55 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/22 16:40:47 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_dinner_stop_flag(t_data *data, bool state)
{
	pthread_mutex_lock(&data->sim_stop_lock);
	data->dinner_stop = state;
	pthread_mutex_unlock(&data->sim_stop_lock);
}

bool	kill_philo(t_philo *philo)
{
	time_t	time;

	time = get_time();
	if ((time - philo->last_meal) >= philo->data->t_die)
	{
		write_status(philo, DIED);
		set_dinner_stop_flag(philo->data, true);
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (true);
	}
	return (false);
}

bool	end_condition_reached(t_data *data)
{
	long		i;
	bool		all_ate_enough;

	all_ate_enough = true;
	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_lock(&data->philo[i]->meal_time_lock);
		if (kill_philo(data->philo[i]))
			return (true);
		if (data->t_must_eat != -1)
			if (data->philo[i]->times_eated < (unsigned int)data->t_must_eat)
				all_ate_enough = false;
		pthread_mutex_unlock(&data->philo[i]->meal_time_lock);
	}
	if (data->t_must_eat != -1 && all_ate_enough == true)
	{
		set_dinner_stop_flag(data, true);
		return (true);
	}
	return (false);
}

void	*supervisor(void *ptr)
{
	t_data	*data;

	data = ptr;
	if (data->t_must_eat == 0)
		return (NULL);
	set_dinner_stop_flag(data, false);
	start_dinner_delay(data->start);
	while (true)
	{
		if (end_condition_reached(data) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
