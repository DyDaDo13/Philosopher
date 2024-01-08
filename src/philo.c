/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:44:38 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/08 15:10:58 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo(t_data *data)
{
	long	time;

	(void)data;
	time = get_time();
	printf("%ld\n", time);
	wait_time(101);
	printf("%ld\n", get_time() - time);
	// data->actual_time = get_time();
	// printf("milisec = %ld\n", data->actual_time);
	// usleep(10000);
	// printf("%ld\n", (get_time() - data->actual_time));
}

int	main(int ac, char **av)
{
	t_data	data;
	
	if (!(ac >= 5 && ac <= 6))
		return (0);
	if (ac >= 5)
	{
		data.n_philo = ft_atoi(av[1]);
		data.t_die = ft_atoi(av[2]);
		data.t_eat = ft_atoi(av[3]);
		data.t_sleep = ft_atoi(av[4]);
	}
	if (ac == 6)
		data.t_must_eat = ft_atoi(av[5]);
	philo(&data);
	return (0);
}
