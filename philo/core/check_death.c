/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:14:44 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 16:06:31 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "utils.h"
#include "logs.h"

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

void	*check_death(void *data)
{
	t_data			*data_ptr;
	time_t			current_time;
	time_t			last_meal;
	unsigned short	i;

	data_ptr = (t_data *)data;
	while (1)
	{
		i = 0;
		while (i < data_ptr->nb_philos)
		{
			current_time = get_time_ms();
			pthread_mutex_lock(&data_ptr->last_meal_lock);
			last_meal = data_ptr->philos[i].last_meal;
			pthread_mutex_unlock(&data_ptr->last_meal_lock);
			if (current_time - last_meal > data_ptr->time_to_die && last_meal)
				return (grim_reaper(data, i), NULL);
			i++;
		}
	}
}
