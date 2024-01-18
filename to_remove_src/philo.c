/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:44:38 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/12 17:13:37 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	assign_number(t_philo *philo, t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->n_philo)
	{
		philo[i].nb_philo = (i + 1);
		philo[i].data = data;
	}
		
}

void	*algo(void	*ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ptr;
	data = philo->data;
	wait_start(data, philo);
	//mutex_printf(data, ft_itoa(((int)get_time())));
	// if (data->pair == 0)
	// 	start_pair(philo, data);
	// else
	// 	start_unpair(philo, data);
	//mutex_printf(data, ft_itoa(philo->nb_philo));
	return (NULL);
}

void	check_pair(t_data *data)
{
	if ((data->n_philo % 2) == 0)
		data->pair = 0;
	else
		data->pair = 1;
}

void	philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = init_data(data);
	check_pair(data);
	assign_number(philo, data);
	while (++i < data->n_philo)
		pthread_create(&philo[i].philo, NULL, algo, &philo[i]);
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
