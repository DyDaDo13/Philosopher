/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:56:18 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/19 15:48:00 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", get_time() - philo->data->start, philo->nb_philo + 1, str);
}

void	write_output(t_data *data)
{
	long	i;
	long	full_count;

	full_count = 0;
	i = -1;
	while (++i < data->n_philo)
		if ()
}

void	write_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->data->mutex_printf);
	if (has_dinner_stop(philo->data) == true)
	{
		pthread_mutex_unlock(&philo->data->mutex_printf);
		return ;
	}
	if (status == DIED)
		print_status(philo, "died");
	else if (status == SLEEPING)
		print_status(philo, "is sleeping");
	else if (status == EATING)
		print_status(philo, "is eating");
	else if (status == THINKING)
		print_status(philo, "is thinking");
	else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->data->mutex_printf);
}
