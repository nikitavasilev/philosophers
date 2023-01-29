/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:35:29 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/29 22:36:06 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "core.h"

void	create_threads(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_create(&data->philos[i].thread_id, NULL, &routine, &data->philos[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < data->nb_philos)
	{
		pthread_create(&data->philos[i].thread_id, NULL, &routine, &data->philos[i]);
		i += 2;
	}
	check_death(data);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philos->thread_id, NULL);
		i++;
	}
}
