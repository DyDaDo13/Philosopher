/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:56:18 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/22 16:53:39 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", get_time()
		- philo->data->start, philo->nb_philo + 1, str);
}

void	write_output(t_data *data)
{
	long	i;
	long	full_count;

	full_count = 0;
	i = -1;
	while (++i < data->n_philo)
		if (data->philo[i]->times_eated >= (unsigned int)data->t_must_eat)
			full_count++;
	pthread_mutex_lock(&data->write_lock);
	printf("%ld/%d philosophers had at least %d meals.\n",
		full_count, data->n_philo, data->t_must_eat);
	pthread_mutex_unlock(&data->write_lock);
	return ;
}

void	write_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (has_dinner_stop(philo->data) == true)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return ;
	}
	if (status == DIED)
		print_status(philo, "\033[31mdied\033[0m");
	else if (status == SLEEPING)
		print_status(philo, "is sleeping");
	else if (status == EATING)
		print_status(philo, "is eating");
	else if (status == THINKING)
		print_status(philo, "is thinking");
	else if (status == GOT_FORK_1 || status == GOT_FORK_2)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->data->write_lock);
}
