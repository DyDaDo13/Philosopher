/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:23:21 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/22 16:43:21 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!forks)
		return (error_handler(data), NULL);
	i = -1;
	while (++i < data->n_philo)
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_handler(data), NULL);
	return (forks);
}

bool	init_mutexes(t_data *data)
{
	data->fork_locks = init_forks(data);
	if (!data->fork_locks)
		return (false);
	if (pthread_mutex_init(&data->sim_stop_lock, NULL) != 0)
		return (error_handler(data), false);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (error_handler(data), false);
	return (true);
}

void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->nb_philo;
	philo->fork[1] = (philo->nb_philo + 1) % philo->data->n_philo;
	if (philo->nb_philo % 2)
	{
		philo->fork[0] = (philo->nb_philo + 1) % philo->data->n_philo;
		philo->fork[1] = philo->nb_philo;
	}
}

t_philo	**init_philo(t_data *data)
{
	t_philo			**philo;
	unsigned int	i;

	philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!philo)
		return (error_handler(data), NULL);
	i = -1;
	while (++i < data->n_philo)
	{
		philo[i] = malloc(sizeof(t_philo) * 1);
		if (!philo[i])
			return (error_handler(data), NULL);
		if (pthread_mutex_init(&philo[i]->meal_time_lock, 0) != 0)
			return (error_handler(data), NULL);
		philo[i]->data = data;
		philo[i]->nb_philo = i;
		philo[i]->times_eated = 0;
		assign_forks(philo[i]);
	}
	return (philo);
}

t_data	*init_all(int ac, char **av, t_data *data)
{
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->n_philo = ft_atol(av[1]);
	data->t_die = ft_atol(av[2]);
	data->t_eat = ft_atol(av[3]);
	data->t_sleep = ft_atol(av[4]);
	data->t_must_eat = -1;
	if (ac - 1 == 5)
		data->t_must_eat = ft_atol(av[5]);
	data->philo = init_philo(data);
	if (!data->philo)
		return (NULL);
	if (!init_mutexes(data))
		return (NULL);
	data->dinner_stop = false;
	return (data);
}
