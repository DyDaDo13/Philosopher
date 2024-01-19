/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:40:54 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/19 15:42:51 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	dinner_stop(t_data *data)
{
	bool	r;
	
	r = false;
	pthread_mutex_lock(&data->mutex_dinner);
	if (data->dinner_stop == true)
		r = true;
	pthread_mutex_unlock(&data->mutex_dinner);
	return (r);
}
