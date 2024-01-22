/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:22:21 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/22 16:25:15 by dydado13         ###   ########.fr       */
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
void	error_handler(t_data *data);

//------------------- init_all.c -------------------
t_data	*init_all(int ac, char **av, t_data *data);
void	free_all(t_data *data);
void	destroy_mutexes(t_data *data);

//----------------------- plus.c -----------------
bool	has_dinner_stop(t_data *data);

//--------------------- time.c ---------------------
long	get_time(void);
void	wait_time(long time);
void	philo_sleep(t_data *data, time_t sleep_time);

//-------------------- prints.c ------------------
void	write_output(t_data *data);
void	write_status(t_philo *philo, t_status status);
void	print_status(t_philo *philo, char *str);

//------------------- philo.c --------------------
void	*philosopher(void *ptr);
void	start_dinner_delay(time_t start_time);

//---------------- supervisor.c ------------------
void	*supervisor(void *ptr);

#endif