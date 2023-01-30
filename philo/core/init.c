/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:52:06 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 16:10:44 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core.h"
#include "utils.h"

int	init_philos(t_data *data)
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

	data->start_time = get_time_ms();
	data->one_died = false;
	if (!init_philos(data))
		return (0);
	data->forks_lock = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks_lock)
		return (0);
	pthread_mutex_init(&data->check_death_lock, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->last_meal_lock, NULL);
	pthread_mutex_init(&data->state_lock, NULL);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks_lock[i], NULL);
		i++;
	}
	return (1);
}
