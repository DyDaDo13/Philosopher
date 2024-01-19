/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:52:02 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/19 10:44:15 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philosopher(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo*)ptr;
	if (philo->data->t_must_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->data->mutex_status);
	printf("program started !!!\n");
	pthread_mutex_unlock(&philo->data->mutex_status);
	return (NULL);
}