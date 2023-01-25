/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:06:36 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/25 23:47:22 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "parser.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

// init_data() is a function that initializes the data structure
// and allocates memory for the philosophers.
// It returns 1 if everything went well, 0 otherwise.
// int	init_data(t_data *data, t_philo *philos)
// {
// 	int	i;

// 	i = 0;
// 	philos->data = data;
// 	philos->philos = malloc(sizeof(t_philo) * data->nb_philos);
// 	if (!philos->philos)
// 		return (0);
// 	while (i < data->nb_philos)
// 	{
// 		philos->philos[i].data = data;
// 		philos->philos[i].id = i + 1;
// 		philos->philos[i].last_meal = 0;
// 		philos->philos[i].nb_meals = 0;
// 		i++;
// 	}
// 	return (1);
// }

int	main(int argc, char const *argv[])
{
	// t_philo	philos;
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("ERROR: Wrong number of arguments.\n");
		printf("Usage: ./philo [number_of_philosophers]\b"
			"[time_to_die] [time_to_eat] [time_to_sleep]\b"
			"[number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	if (!parse(&data, argc, argv))
		return (EXIT_FAILURE);
	// if (!init_data(&data, &philos))
	// 	return (EXIT_FAILURE);
	print_args(&data);
	return (EXIT_SUCCESS);
}
