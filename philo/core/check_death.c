/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:14:44 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/29 23:03:06 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "utils.h"
#include "logs.h"
#include <stdio.h>

void	*check_death(void *data)
{
	t_data	*data_ptr;
	time_t	current_time;
	int		i;

	data_ptr = (t_data *)data;
	while (1)
	{
		i = 0;
		while (i < data_ptr->nb_philos)
		{
			current_time = get_time_ms();

			pthread_mutex_lock(&data_ptr->last_meal_lock);
			if (current_time - data_ptr->philos[i].last_meal > data_ptr->time_to_die && data_ptr->philos[i].last_meal != 0)
			{
				pthread_mutex_lock(&data_ptr->state_lock);
				data_ptr->philos[i].state = DIED;
				pthread_mutex_unlock(&data_ptr->state_lock);
				pthread_mutex_lock(&data_ptr->check_death_lock);
				data_ptr->one_died = true;
				print_message(&data_ptr->philos[i]);
				pthread_mutex_unlock(&data_ptr->check_death_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&data_ptr->last_meal_lock);
			i++;
		}
	}
}
