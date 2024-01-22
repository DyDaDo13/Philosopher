/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:23:21 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/22 15:08:47 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!forks)
		error_handler("Error : forks not allocated\n", data);
	i = -1;
	while (++i < data->n_philo)
		if (pthread_mutex_init(&forks[i], 0) != 0)
			error_handler("Error : mutex_fork did not initialized\n", data);
	return (forks);
}

void	init_mutexes(t_data *data)
{
	data->fork_locks = init_forks(data);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		error_handler("Error : mutex_printf not allocated\n", data);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		error_handler("Error : mutex_status not allocated\n", data);
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
		error_handler("Error : structure 'Philo' did not allocated\n", data);
	i = -1;
	while (++i < data->n_philo)
	{
		philo[i] = malloc(sizeof(t_philo) * 1);
		if (!philo[i])
			error_handler("Error : structure 'Philo*' did not alloc\n", data);
		if (pthread_mutex_init(&philo[i]->meal_time_lock, 0) != 0)
			error_handler("Error : mutex->philo did not allocated\n", data);
		philo[i]->data = data;
		philo[i]->nb_philo = i;
		philo[i]->times_eated = 0;
		assign_forks(philo[i]);
	}
	return (philo);
}

void	init_all(int ac, char **av, t_data *data)
{
	data->n_philo = ft_atol(av[1]);
	data->t_die = ft_atol(av[2]);
	data->t_eat = ft_atol(av[3]);
	data->t_sleep = ft_atol(av[4]);
	data->t_must_eat = -1;
	if (ac - 1 == 5)
		data->t_must_eat = ft_atol(av[5]);
	data->philo = init_philo(data);
	init_mutexes(data);
	data->dinner_stop = false;
}
