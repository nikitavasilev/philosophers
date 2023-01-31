/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:05:13 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/31 02:23:28 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "logs.h"
#include "utils.h"

static int	odd_philo_takes_fork(t_philo *philo, pthread_mutex_t *forks_lock)
{
	pthread_mutex_lock(&forks_lock[philo->id - 1]);
	pthread_mutex_lock(&philo->data->times_ate_lock);
	if (philo->data->times_ate >= philo->data->nb_philos
		|| !print_message(philo))
	{
		pthread_mutex_unlock(&philo->data->times_ate_lock);
		pthread_mutex_unlock(&forks_lock[philo->id - 1]);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->times_ate_lock);
	pthread_mutex_lock(&forks_lock[philo->id % philo->data->nb_philos]);
	pthread_mutex_lock(&philo->data->times_ate_lock);
	if (philo->data->times_ate >= philo->data->nb_philos
		|| !print_message(philo))
	{
		pthread_mutex_unlock(&philo->data->times_ate_lock);
		pthread_mutex_unlock(&forks_lock[philo->id % philo->data->nb_philos]);
		pthread_mutex_unlock(&forks_lock[philo->id - 1]);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->times_ate_lock);
	return (1);
}

static int	even_philo_takes_fork(t_philo *philo, pthread_mutex_t *forks_lock)
{
	pthread_mutex_lock(&forks_lock[philo->id % philo->data->nb_philos]);
	pthread_mutex_lock(&philo->data->times_ate_lock);
	if (philo->data->times_ate >= philo->data->nb_philos
		|| !print_message(philo))
	{
		pthread_mutex_unlock(&philo->data->times_ate_lock);
		pthread_mutex_unlock(&forks_lock[philo->id % philo->data->nb_philos]);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->times_ate_lock);
	pthread_mutex_lock(&forks_lock[philo->id - 1]);
	pthread_mutex_lock(&philo->data->times_ate_lock);
	if (philo->data->times_ate >= philo->data->nb_philos
		|| !print_message(philo))
	{
		pthread_mutex_unlock(&philo->data->times_ate_lock);
		pthread_mutex_unlock(&forks_lock[philo->id - 1]);
		pthread_mutex_unlock(&forks_lock[philo->id % philo->data->nb_philos]);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->times_ate_lock);
	return (1);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*forks_lock;

	forks_lock = philo->data->forks_lock;
	pthread_mutex_lock(&philo->data->state_lock);
	philo->state = TAKING_FORK;
	pthread_mutex_unlock(&philo->data->state_lock);
	if (philo->id % 2 == 0)
		return (even_philo_takes_fork(philo, forks_lock));
	else
		return (odd_philo_takes_fork(philo, forks_lock));
	return (1);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_t	*forks_lock;

	forks_lock = philo->data->forks_lock;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&forks_lock[philo->id - 1]);
		pthread_mutex_unlock(&forks_lock[philo->id % philo->data->nb_philos]);
	}
	else
	{
		pthread_mutex_unlock(&forks_lock[philo->id % philo->data->nb_philos]);
		pthread_mutex_unlock(&forks_lock[philo->id - 1]);
	}
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->state_lock);
	philo->state = EATING;
	pthread_mutex_unlock(&philo->data->state_lock);
	pthread_mutex_lock(&philo->data->last_meal_lock);
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&philo->data->last_meal_lock);
	pthread_mutex_lock(&philo->data->times_ate_lock);
	if (philo->data->times_ate >= philo->data->nb_philos
		|| !print_message(philo))
		return (pthread_mutex_unlock(&philo->data->times_ate_lock), 0);
	pthread_mutex_unlock(&philo->data->times_ate_lock);
	pthread_mutex_lock(&philo->data->nb_of_meals_lock);
	philo->nb_of_meals++;
	pthread_mutex_unlock(&philo->data->nb_of_meals_lock);
	sequential_sleep(philo->data, philo->data->time_to_eat);
	return (1);
}
