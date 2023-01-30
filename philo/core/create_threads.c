/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:35:29 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 18:05:46 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "core.h"

void	create_threads(t_data *data)
{
	unsigned short	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_create(&data->philos[i].thread_id, NULL, \
		&routine_dispatcher, &data->philos[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < data->nb_philos)
	{
		pthread_create(&data->philos[i].thread_id, NULL, \
		&routine_dispatcher, &data->philos[i]);
		i += 2;
	}
	monitor(data);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
}
