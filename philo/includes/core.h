/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:16:15 by nvasilev          #+#    #+#             */
/*   Updated: 2022/10/02 20:50:13 by nvasilev         ###   ########.fr       */
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
	pthread_mutex_t	display;
}	t_philo_args;

typedef enum e_state
{
	sleep,
	eating,
	died,
	thinking,
	taking_fork
}	t_state;

typedef struct s_philo
{
	pthread_mutex_t	**left_fork;
	pthread_mutex_t	**left_right;
	pthread_mutex_t	check_death;
	t_state			state;
	int				nb_of_meal;
}	t_philo;

void	*routine(t_philo *philo);
// eat();
// sleep();
// take_fork();
// think();

#endif
