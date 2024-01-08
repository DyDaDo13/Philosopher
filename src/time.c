/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:40:06 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/08 15:06:16 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	wait_time(long time)
{
	long	actual_time;
	long	temp_time;
	actual_time = get_time();
	temp_time = get_time();
	while ((temp_time - actual_time) != time)
		temp_time = get_time();
}
