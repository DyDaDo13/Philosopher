/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:23:21 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/18 11:08:49 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!forks)
		error_handler("Error : forks not allocated | l-37 in 'init_all.c'\n");
	i = -1;
	while (++i < data->n_philo)
		if (pthread_mutex_init(&forks[i], 0) != 0)
			error_handler("Error : mutex_fork did not initialized\n");
	return (forks);
}

void	init_mutexes(t_data *data)
{
	data->mutex_fork = init_forks(data);
	if (pthread_mutex_init(&data->mutex_printf, NULL) != 0)
		error_handler("Error : mutex_printf not allocated\n");
	if (pthread_mutex_init(&data->mutex_status, NULL) != 0)
		error_handler("Error : mutex_status not allocated\n");
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
		error_handler("Error : structure 'Philo' did not allocated\n");
	i = -1;
	while (++i < data->n_philo)
	{
		philo[i] = malloc(sizeof(t_philo) * 1);
		if (!philo[i])
			error_handler("Error : structure 'Philo*' did not allocated\n");
		if (pthread_mutex_init(&philo[i]->mutex_eat_fork, 0) != 0)
			error_handler("Error : mutex->philo did not allocated\n");
		philo[i]->data = data;
		philo[i]->nb_philo = i;
		philo[i]->times_eated = 0;
		assign_forks(philo[i]);
	}
	return (philo);
}

void	init_all(int ac, char **av, t_data *data)
{
	(void)ac;
	data->n_philo = ft_atol(av[1]);
	data->t_die = ft_atol(av[2]);
	data->t_eat = ft_atol(av[3]);
	data->t_sleep = ft_atol(av[4]);
	data->t_must_eat = -1;
	if (av[5])
		data->t_must_eat = ft_atol(av[5]);
	data->philo = init_philo(data);
	init_mutexes(data);
}
