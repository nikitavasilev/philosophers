/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:16:15 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 18:05:25 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef enum e_state
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_state;

typedef struct s_philo
{
	pthread_t		thread_id;
	unsigned short	id;
	unsigned int	nb_of_meals;
	time_t			last_meal;
	t_state			state;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	unsigned short	nb_philos;
	bool			one_died;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	unsigned int	nb_tmust_eat;
	unsigned int	times_ate;
	time_t			start_time;
	pthread_mutex_t	*forks_lock;
	pthread_mutex_t	check_death_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	last_meal_lock;
	pthread_mutex_t	state_lock;
	pthread_mutex_t	nb_of_meals_lock;
	t_philo			*philos;
}	t_data;

void	*routine_dispatcher(void *philo);
void	*routine(void *philo);
int		init_philos(t_data *data);
int		init_data(t_data *data);
void	destroy(t_data *data);
void	create_threads(t_data *data);
void	*monitor(t_data *data);

#endif
