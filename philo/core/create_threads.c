/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:35:29 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/28 07:37:07 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core.h"

void	create_threads(t_data *data)
{
	int			i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!threads)
		return ;
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_create(&threads[i], NULL, &routine, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}
