/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:52:02 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/18 16:54:42 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philosopher(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo*)ptr;
	if (philo->data->t_must_eat == 0)
		return (NULL);
	
}