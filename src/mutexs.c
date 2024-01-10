/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:30:36 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/10 15:39:36 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	mutex_printf(t_data *data, char *str)
{
	pthread_mutex_lock(&data->mutex_printf);
	printf("%s\n", str);
	pthread_mutex_unlock(&data->mutex_printf);
}

void	mutex_state(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_status);
	data->state = i;
	pthread_mutex_unlock(&data->mutex_status);
}
