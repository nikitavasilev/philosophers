/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:52:06 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/26 02:16:18 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core.h"
#include "utils.h"

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

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
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % data->nb_philos;
		i++;
	}
	data->philos = philos;
	return (1);
}

int	init_data(t_data *data)
{
	unsigned short	i;

	data->start_time = get_time_ms();
	data->state = THINKING;
	if (!init_philos(data))
		return (0);
	data->left_fork_lock = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->left_fork_lock)
		return (0);
	data->left_right_lock = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->left_right_lock)
		return (0);
	pthread_mutex_init(&data->check_death_lock, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->left_fork_lock[i], NULL);
		pthread_mutex_init(&data->left_right_lock[i], NULL);
		i++;
	}
	return (1);
}
