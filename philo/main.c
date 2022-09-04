/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:06:36 by nvasilev          #+#    #+#             */
/*   Updated: 2022/09/04 21:33:34 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "parser.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	t_philo_args	args;

	if (argc < 5 || argc > 6)
	{
		printf("ERROR: Wrong number of arguments.\n");
		printf("Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	if (!parse(&args, argc, argv))
		return (EXIT_FAILURE);
	print_args(&args);
	return (EXIT_SUCCESS);
}
