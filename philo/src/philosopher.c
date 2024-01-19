/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:52:02 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/19 12:09:33 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	think_routine(t_philo *philo, bool silent)
{
	time_t	time_to_think;
	
	pthread_mutex_lock(&philo->mutex_eat_fork);
	time_to_think = (philo->data->t_die)
	pthread_mutex_unlock(&philo->mutex_eat_fork);
	
}

void	start_dinner_delay(time_t start_time)
{
	while(get_time() < start_time)
		continue;
}

void	*philosopher(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo*)ptr;
	if (philo->data->t_must_eat == 0)
		return (NULL);
	
	pthread_mutex_lock(&philo->mutex_eat_fork);
	philo->last_meal = philo->data->start;
	pthread_mutex_unlock(&philo->mutex_eat_fork);
	
	// pthread_mutex_lock(&philo->data->mutex_printf);
	// printf("start : %li\n", philo->data->start);
	// printf("get_time = %li\n", get_time());
	// printf("calcul = %li\n", (philo->data->start - get_time()));
	// pthread_mutex_unlock(&philo->data->mutex_printf);
	
	start_dinner_delay(philo->data->start);
	
	// pthread_mutex_lock(&philo->data->mutex_printf);
	// printf("start : %li\n", philo->data->start);
	// printf("get_time = %li\n", get_time());
	// printf("calcul = %li\n", (philo->data->start - get_time()));
	// pthread_mutex_unlock(&philo->data->mutex_printf);
	
	if (philo->data->t_die == 0)
		return (NULL);
	else if (philo->nb_philo % 2)
		think_routine(philo, true);
	while (has_dinner_stop(philo->data) == true)
	{
		printf("test\n");
		eat_sleep_routine(philo);
		think_routine(philo, false);
	}
	return (NULL);
}