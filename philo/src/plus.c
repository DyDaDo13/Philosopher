/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:40:54 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/22 15:10:52 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	dinner_stop(t_data *data)
{
	bool	r;

	r = false;
	pthread_mutex_lock(&data->sim_stop_lock);
	if (data->dinner_stop == true)
		r = true;
	pthread_mutex_unlock(&data->sim_stop_lock);
	return (r);
}

bool	has_dinner_stop(t_data *data)
{
	bool	r;

	r = false;
	pthread_mutex_lock(&data->sim_stop_lock);
	if (data->dinner_stop == true)
		r = true;
	pthread_mutex_unlock(&data->sim_stop_lock);
	return (r);
}
