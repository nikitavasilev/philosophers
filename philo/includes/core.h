/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:16:15 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/22 18:45:16 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <pthread.h>

typedef struct s_philo_args
{
	int				nb_philos;
	int				tsleep;
	int				tdie;
	int				teat;
	int				nb_tmust_eat;
	pthread_t		thread_id;
}	t_philo_args;

typedef enum e_state
{
	fsleep,
	eating,
	died,
	thinking,
	taking_fork
}	t_state;

typedef struct s_data
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*left_right;
	pthread_mutex_t	check_death;
	pthread_mutex_t	display;
	t_state			state;
	int				last_meal;
	int				nb_of_meal;
	t_philo_args	*args;
}	t_data;

void	*routine(void *philo);

#endif
