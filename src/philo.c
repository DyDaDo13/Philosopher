/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:44:38 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/09 17:54:37 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	assign_number(t_data *data)
{
	int		i;

	while (i < )
}

void	*algo(void	*ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while(1)
	{
		pthread_mutex_lock(&data->mutex_status);
		if (data->state == 1)
		{
			pthread_mutex_unlock(&data->mutex_status);
			break;
		}
		pthread_mutex_unlock(&data->mutex_status);
		wait_time(1);
	}
	assign_number(data);
	// if ((data->n_philo % 2) == 0)
	// 	mutex_printf(data, "pair\n");
	// else
	// 	mutex_printf(data, "impair\n");
	return (NULL);
}

void	philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = init_data(data);
	while (++i < data->n_philo)
		pthread_create(&philo[i].philo, NULL, algo, data);
	mutex_state(data, 1);
	while (i-- > 0)
		pthread_join(philo[i].philo, NULL);
	destroy_data(data, philo);
}

int	main(int ac, char **av)
{
	t_data	data;
	
	if (!(ac >= 5 && ac <= 6))
		return (printf("Error : Not 5 args"), 1);
	if (ac >= 5)
	{
		data.n_philo = ft_atoi(av[1]);
		data.t_die = ft_atoi(av[2]);
		data.t_eat = ft_atoi(av[3]);
		data.t_sleep = ft_atoi(av[4]);
		data.t_must_eat = 0;
	}
	if (ac == 6)
		data.t_must_eat = ft_atoi(av[5]);
	philo(&data);
	return (0);
}
