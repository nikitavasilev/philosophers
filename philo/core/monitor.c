/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:14:44 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/31 02:33:22 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "utils.h"
#include "logs.h"
#include <unistd.h>

static void	grim_reaper(t_data *data, unsigned short index)
{
	pthread_mutex_lock(&data->state_lock);
	data->philos[index].state = DIED;
	pthread_mutex_unlock(&data->state_lock);
	pthread_mutex_lock(&data->check_death_lock);
	data->one_died = true;
	pthread_mutex_unlock(&data->check_death_lock);
	print_death(&data->philos[index]);
}

static bool	set_death(t_data *data)
{
	pthread_mutex_unlock(&data->times_ate_lock);
	pthread_mutex_lock(&data->check_death_lock);
	data->one_died = true;
	pthread_mutex_unlock(&data->check_death_lock);
	return (true);
}

static bool	nb_of_meals_check(t_data *data)
{
	unsigned short	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->nb_of_meals_lock);
		if (data->philos[i].nb_of_meals >= data->nb_tmust_eat)
		{
			pthread_mutex_unlock(&data->nb_of_meals_lock);
			pthread_mutex_lock(&data->times_ate_lock);
			data->times_ate++;
			if (data->times_ate == data->nb_philos)
				return (set_death(data));
			pthread_mutex_unlock(&data->times_ate_lock);
		}
		else
			pthread_mutex_unlock(&data->nb_of_meals_lock);
		i++;
	}
	pthread_mutex_lock(&data->times_ate_lock);
	data->times_ate = 0;
	pthread_mutex_unlock(&data->times_ate_lock);
	return (false);
}

void	*monitor(t_data *data)
{
	time_t			current_time;
	time_t			last_meal;
	unsigned short	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			current_time = get_time_ms();
			pthread_mutex_lock(&data->last_meal_lock);
			last_meal = data->philos[i].last_meal;
			pthread_mutex_unlock(&data->last_meal_lock);
			if (data->nb_philos == 1
				&& ((current_time - data->start_time) > data->time_to_die))
				return (grim_reaper(data, i), NULL);
			if (current_time - last_meal > data->time_to_die && last_meal)
				return (grim_reaper(data, i), NULL);
			if (i == data->nb_philos - 1 && data->nb_tmust_eat > 0
				&& nb_of_meals_check(data))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
}
