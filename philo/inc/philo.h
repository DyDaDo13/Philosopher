/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:21 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/22 14:50:55 by dydado13         ###   ########.fr       */
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
# include <stdbool.h>

/******************************************************
*                     STRUCTURES                      *
******************************************************/

typedef struct s_data
{
	time_t			start;
	unsigned int	n_philo;
	pthread_t		supervisor;
	time_t			t_die;
	time_t			t_sleep;
	time_t			t_eat;
	int				t_must_eat;
	bool			dinner_stop;
	pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_locks;
	struct s_philo	**philo;
}t_data;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	nb_philo;
	unsigned int	times_eated;
	unsigned int	fork[2];
	pthread_mutex_t	meal_time_lock;
	time_t			last_meal;
	t_data			*data;
}t_philo;

typedef enum s_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}t_status;

/******************************************************
*                     FUNCTIONS                       *
******************************************************/

//------------------- functions.c ------------------
long	ft_atol(const char *nptr);

//------------------ check_errors.c ----------------
int		check_errors(int ac, char **av);
int		not_number(char **tab);
void	error_handler(char *str, t_data *data);

//------------------- init_all.c -------------------
void	init_all(int ac, char **av, t_data *data);
void	free_all(t_data *data);
void	destroy_mutexes(t_data *data);

//--------------------- time.c ---------------------
long	get_time(void);
void	wait_time(long time);
void	*philosopher(void *ptr);
void	print_status(t_philo *philo, char *str);
void	write_status(t_philo *philo, t_status status);
void	write_output(t_data *data);
bool	has_dinner_stop(t_data *data);
void	philo_sleep(t_data *data, time_t sleep_time);
void	start_dinner_delay(time_t start_time);
void	*supervisor(void *ptr);
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