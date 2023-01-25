/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:16:15 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/25 23:43:04 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_data	t_data;
typedef struct s_philo
{
	pthread_t		thread_id;
	unsigned short	id;
	unsigned int	times_ate;
	unsigned int	fork[2];
	unsigned int 	nb_of_meals;
	time_t			last_meal;
	t_data			*data;
}	t_philo;

typedef enum e_state
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_state;

typedef struct s_data
{
	unsigned short	nb_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	unsigned int	nb_tmust_eat;
	time_t			start_time;
	pthread_mutex_t	*left_fork_lock;
	pthread_mutex_t	*left_right_lock;
	pthread_mutex_t	check_death_lock;
	pthread_mutex_t	print_lock;
	t_state			state;
	t_philo			**philos;
}	t_data;

void	*routine(void *philo);

#endif
