/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:21 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/18 11:02:53 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/******************************************************
*                      INCLUDES                       *
******************************************************/

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

/******************************************************
*                     STRUCTURES                      *
******************************************************/

typedef struct s_data
{
	time_t			start;
	unsigned int	n_philo;
	time_t			t_die;
	time_t			t_sleep;
	time_t			t_eat;
	int				t_must_eat;
	pthread_mutex_t	mutex_printf;
	pthread_mutex_t	mutex_status;
	pthread_mutex_t	*mutex_fork;
	struct s_philo	**philo;
}t_data;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	nb_philo;
	unsigned int	times_eated;
	unsigned int	fork[2];
	pthread_mutex_t	mutex_eat_fork;
	time_t			last_meal;
	t_data			*data;
}t_philo;

/******************************************************
*                     FUNCTIONS                       *
******************************************************/

//------------------- functions.c ------------------
long	ft_atol(const char *nptr);

//------------------ check_errors.c ----------------
void	check_errors(int ac, char **av);
int		not_number(char **tab);

//------------------- init_all.c -------------------
void	init_all(int ac, char **av, t_data *data);
void	error_handler(char *str);
// long	get_time(void);
// void	wait_time(long time);
// char	*ft_itoa(int n);
// void	wait_start(t_data *data, t_philo *philo);

// ///////////  mutex  //////////////
// void	mutex_state(t_data *data, int i);
// void	mutex_printf(t_data *data, char *str);

// /////////// init destroy /////////
// t_philo	*init_data(t_data *data);
// void	destroy_data(t_data *data, t_philo *philo);

#endif