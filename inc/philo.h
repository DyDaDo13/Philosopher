/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:21 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/08 15:06:40 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct	s_philo 
{
	int		times_eated;
}t_philo;


typedef struct	s_data
{
	int		n_philo;
	int		t_die;
	int		t_sleep;
	int		t_eat;
	int		t_must_eat;
	long	actual_time;
	t_philo	philo;
	struct s_data	*next;
}t_data;

int		ft_atoi(const char *nptr);
long	get_time(void);
void	wait_time(long time);

#endif