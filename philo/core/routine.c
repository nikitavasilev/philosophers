/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:35:42 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/29 23:04:37 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "core.h"
#include "logs.h"
#include "utils.h"

int		take_forks(t_philo *philo);
void	put_forks(t_philo *philo);
int		eat(t_philo *philo);
void	philo_sleep(t_data *data, time_t sleep_time);

void	*routine(void *philo)
{
	t_philo	*philo_ptr;

	philo_ptr = (t_philo *)philo;
	while (1)
	{
		if (!take_forks(philo_ptr))
			return (NULL);
		if (!eat(philo_ptr))
			return (NULL);
		put_forks(philo_ptr);
		pthread_mutex_lock(&philo_ptr->data->state_lock);
		philo_ptr->state = SLEEPING;
		pthread_mutex_unlock(&philo_ptr->data->state_lock);
		print_message(philo_ptr);
		philo_sleep(philo_ptr->data, philo_ptr->data->time_to_sleep);
		pthread_mutex_lock(&philo_ptr->data->state_lock);
		philo_ptr->state = THINKING;
		pthread_mutex_unlock(&philo_ptr->data->state_lock);
		print_message(philo_ptr);
	}
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*forks_lock;

	forks_lock = philo->data->forks_lock;
	pthread_mutex_lock(&forks_lock[philo->id - 1]);
	pthread_mutex_lock(&philo->data->state_lock);
	philo->state = TAKING_FORK;
	pthread_mutex_unlock(&philo->data->state_lock);
	print_message(philo);
	pthread_mutex_lock(&forks_lock[philo->id % philo->data->nb_philos]);
	print_message(philo);
	return (1);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_t	*forks_lock;

	forks_lock = philo->data->forks_lock;
	pthread_mutex_unlock(&forks_lock[philo->id - 1]);
	pthread_mutex_unlock(&forks_lock[philo->id % philo->data->nb_philos]);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->state_lock);
	philo->state = EATING;
	pthread_mutex_unlock(&philo->data->state_lock);
	pthread_mutex_lock(&philo->data->last_meal_lock);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->data->last_meal_lock);
	philo->nb_of_meals++;
	print_message(philo);
	philo_sleep(philo->data, philo->data->time_to_eat);
	return (1);
}

void	philo_sleep(t_data *data, time_t sleep_time)
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
