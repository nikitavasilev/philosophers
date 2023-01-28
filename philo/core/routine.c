/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:35:42 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/28 05:42:24 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "core.h"
#include "logs.h"
#include "utils.h"

void	take_forks(t_philo *philo);
void	put_forks(t_philo *philo);
void	eat(t_philo *philo);

void	*routine(void *philo)
{
	t_philo	*philo_ptr;

	philo_ptr = (t_philo *)philo;
	while (1)
	{
		take_forks(philo_ptr);
		eat(philo_ptr);
		put_forks(philo_ptr);
		philo_ptr->state = SLEEPING;
		print_message(philo_ptr);
		usleep(philo_ptr->data->time_to_sleep * 1000);
		philo_ptr->state = THINKING;
		print_message(philo_ptr);
	}
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks_lock[philo->id - 1]);
	philo->state = TAKING_FORK;
	print_message(philo);
	pthread_mutex_lock(&philo->data->forks_lock[philo->id % philo->data->nb_philos]);
	print_message(philo);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks_lock[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks_lock[philo->id % philo->data->nb_philos]);
}

void	eat(t_philo *philo)
{
	philo->state = EATING;
	philo->last_meal = get_time_ms();
	philo->nb_of_meals++;
	print_message(philo);
	usleep(philo->data->time_to_eat * 1000);
}
