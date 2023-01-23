/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:06:36 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/23 18:56:34 by nvasilev         ###   ########.fr       */
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
int	init_data(t_data *data, t_philo_args *args)
{
	int	i;

	data->args = args;
	data->philos = malloc(sizeof(t_data) * args->nb_philos);
	if (!data->philos)
		return (0);
	i = 0;
	while (i < args->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].nb_eat = 0;
		i++;
	}
	return (1);
}

int	main(int argc, char const *argv[])
{
	t_philo_args	args;
	t_data			data;

	if (argc < 5 || argc > 6)
	{
		printf("ERROR: Wrong number of arguments.\n");
		printf("Usage: ./philo [number_of_philosophers]\b"
			"[time_to_die] [time_to_eat] [time_to_sleep]\b"
			"[number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	if (!parse(&args, argc, argv))
		return (EXIT_FAILURE);
	if (!init_data(&data, &args))
		return (EXIT_FAILURE);
	print_args(&args);
	return (EXIT_SUCCESS);
}
