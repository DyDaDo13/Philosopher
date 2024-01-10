/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:21 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/10 15:21:29 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_data
{
	pthread_mutex_t	mutex_printf;
	pthread_mutex_t	mutex_status;
	pthread_mutex_t	mutex_nb_philo;
	int				pair;
	int				state;
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				t_must_eat;
	long			actual_time;
	struct s_philo	*philo;
}t_data;

typedef struct	s_philo 
{
	pthread_t	philo;
	int		nb_philo;
	int		times_eated;
	int		fork;
	pthread_mutex_t	mutex_fork;
	t_data	*data;
}t_philo;

int		ft_atoi(const char *nptr);
long	get_time(void);
void	wait_time(long time);
char	*ft_itoa(int n);

///////////  mutex  //////////////
void	mutex_state(t_data *data, int i);
void	mutex_printf(t_data *data, char *str);

/////////// init destroy /////////
t_philo	*init_data(t_data *data);
void	destroy_data(t_data *data, t_philo *philo);

#endif