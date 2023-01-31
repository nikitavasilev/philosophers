/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:35:42 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/31 04:16:21 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "core.h"
#include "logs.h"
#include "utils.h"

static bool	sleep_and_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->state_lock);
	philo->state = SLEEPING;
	pthread_mutex_unlock(&philo->data->state_lock);
	pthread_mutex_lock(&philo->data->times_ate_lock);
	if (philo->data->times_ate >= philo->data->nb_philos
		|| !print_message(philo))
		return (pthread_mutex_unlock(&philo->data->times_ate_lock), false);
	pthread_mutex_unlock(&philo->data->times_ate_lock);
	sequential_sleep(philo->data, philo->data->time_to_sleep);
	return (true);
}

static void	*routine(void *philo)
{
	t_philo	*ph_ptr;

	ph_ptr = (t_philo *)philo;
	while (1)
	{
		if (!take_forks(ph_ptr))
			return (NULL);
		if (!eat(ph_ptr))
			return (put_forks(ph_ptr), NULL);
		put_forks(ph_ptr);
		if (!sleep_and_check(ph_ptr))
			return (NULL);
		pthread_mutex_lock(&ph_ptr->data->state_lock);
		ph_ptr->state = THINKING;
		usleep(500);
		pthread_mutex_unlock(&ph_ptr->data->state_lock);
		pthread_mutex_lock(&ph_ptr->data->times_ate_lock);
		if (ph_ptr->data->times_ate >= ph_ptr->data->nb_philos
			|| !print_message(ph_ptr))
			return (pthread_mutex_unlock(&ph_ptr->data->times_ate_lock), NULL);
		pthread_mutex_unlock(&ph_ptr->data->times_ate_lock);
	}
}

static void	*one_philo_routine(void *philo)
{
	t_philo	*philo_ptr;

	philo_ptr = (t_philo *)philo;
	pthread_mutex_lock(&philo_ptr->data->state_lock);
	philo_ptr->state = TAKING_FORK;
	pthread_mutex_unlock(&philo_ptr->data->state_lock);
	pthread_mutex_lock(&philo_ptr->data->forks_lock[0]);
	print_message(philo);
	sequential_sleep(philo_ptr->data, philo_ptr->data->time_to_die);
	pthread_mutex_unlock(&philo_ptr->data->forks_lock[0]);
	return (NULL);
}

void	*routine_dispatcher(void *philo)
{
	t_philo	*philo_ptr;

	philo_ptr = (t_philo *)philo;
	if (philo_ptr->data->nb_philos > 1)
		return (routine(philo));
	else
		return (one_philo_routine(philo));
}

void	sequential_sleep(t_data *data, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_time_ms() + sleep_time;
	while (get_time_ms() < wake_up)
	{
		pthread_mutex_lock(&data->check_death_lock);
		if (data->one_died)
		{
			pthread_mutex_unlock(&data->check_death_lock);
			break ;
		}
		pthread_mutex_unlock(&data->check_death_lock);
		usleep(100);
	}
}
