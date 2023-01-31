/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:52:06 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/31 02:13:25 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core.h"
#include "utils.h"

static void	destroy_mutexes(t_data *data, int fail_case)
{
	if (fail_case >= 1)
		pthread_mutex_destroy(&data->check_death_lock);
	if (fail_case >= 2)
		pthread_mutex_destroy(&data->print_lock);
	if (fail_case >= 3)
		pthread_mutex_destroy(&data->last_meal_lock);
	if (fail_case >= 4)
		pthread_mutex_destroy(&data->state_lock);
	if (fail_case >= 5)
		pthread_mutex_destroy(&data->nb_of_meals_lock);
	if (fail_case >= 6)
		pthread_mutex_destroy(&data->times_ate_lock);
}

static	int	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->check_death_lock, NULL))
		return (0);
	if (pthread_mutex_init(&data->print_lock, NULL))
		return (1);
	if (pthread_mutex_init(&data->last_meal_lock, NULL))
		return (2);
	if (pthread_mutex_init(&data->state_lock, NULL))
		return (3);
	if (pthread_mutex_init(&data->nb_of_meals_lock, NULL))
		return (4);
	if (pthread_mutex_init(&data->times_ate_lock, NULL))
		return (5);
	return (-1);
}

static void	destroy_mutex_array(t_data *data, unsigned short i)
{
	while (i > 0)
	{
		i--;
		pthread_mutex_destroy(&data->forks_lock[i]);
	}
}

static int	init_philos(t_data *data)
{
	t_philo			*philos;
	unsigned short	i;

	philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!philos)
		return (0);
	i = 0;
	while (i < data->nb_philos)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].last_meal = 0;
		philos[i].nb_of_meals = 0;
		philos[i].state = THINKING;
		i++;
	}
	data->philos = philos;
	return (1);
}

int	init_data(t_data *data)
{
	unsigned short	i;
	int				ret;

	data->start_time = get_time_ms();
	data->one_died = false;
	data->times_ate = 0;
	if (!init_philos(data))
		return (0);
	data->forks_lock = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks_lock)
		return (free(data->philos), 0);
	ret = init_mutexes(data);
	if (ret >= 0)
		return (destroy_mutexes(data, ret), free(data->philos), 0);
	i = 0;
	while (i < data->nb_philos)
	{
		ret = pthread_mutex_init(&data->forks_lock[i], NULL);
		if (ret)
			return (destroy_mutex_array(data, i), destroy_mutexes(data, 6),
				free(data->philos), 0);
		i++;
	}
	return (1);
}
