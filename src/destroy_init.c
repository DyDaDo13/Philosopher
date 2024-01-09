/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:47:56 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/09 17:48:29 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	destroy_data(t_data *data, t_philo *philo)
{
	free(philo);
	pthread_mutex_destroy(&data->mutex_status);
	pthread_mutex_destroy(&data->mutex_printf);
}

t_philo	*init_data(t_data *data)
{
	t_philo	*philo;
	
	philo = malloc(sizeof(t_philo) * data->n_philo);
	data->philo = philo;
	pthread_mutex_init(&data->mutex_status, NULL);
	pthread_mutex_init(&data->mutex_printf, NULL);
	return (philo);
}
