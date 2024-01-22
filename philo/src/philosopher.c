/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:52:02 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/22 15:10:25 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	think_routine(t_philo *philo, bool silent)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_time_lock);
	time_to_think = (philo->data->t_die
			- (get_time() - philo->last_meal) - philo->data->t_eat) / 2;
	pthread_mutex_unlock(&philo->meal_time_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && silent == true)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (silent == false)
		write_status(philo, THINKING);
	philo_sleep(philo->data, time_to_think);
}

void	start_dinner_delay(time_t start_time)
{
	while (get_time() < start_time)
		continue ;
}

void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[0]]);
	write_status(philo, GOT_FORK_1);
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[1]]);
	write_status(philo, GOT_FORK_2);
	write_status(philo, EATING);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_time_lock);
	philo_sleep(philo->data, philo->data->t_eat);
	if (has_dinner_stop(philo->data) == false)
	{
		pthread_mutex_lock(&philo->meal_time_lock);
		philo->times_eated += 1;
		pthread_mutex_unlock(&philo->meal_time_lock);
	}
	write_status(philo, SLEEPING);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[0]]);
	philo_sleep(philo->data, philo->data->t_sleep);
}

void	*lone_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locks[philo->fork[0]]);
	write_status(philo, GOT_FORK_1);
	philo_sleep(philo->data, philo->data->t_die);
	write_status(philo, DIED);
	pthread_mutex_unlock(&philo->data->fork_locks[philo->fork[0]]);
	return (NULL);
}

void	*philosopher(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->data->t_must_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_time_lock);
	philo->last_meal = philo->data->start;
	pthread_mutex_unlock(&philo->meal_time_lock);
	start_dinner_delay(philo->data->start);
	if (philo->data->t_die == 0)
		return (NULL);
	if (philo->data->n_philo == 1)
		return (lone_philo_routine(philo));
	else if (philo->nb_philo % 2)
		think_routine(philo, true);
	while (has_dinner_stop(philo->data) == false)
	{
		eat_sleep_routine(philo);
		think_routine(philo, false);
	}
	return (NULL);
}
