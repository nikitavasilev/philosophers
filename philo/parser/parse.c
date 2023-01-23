/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:35:00 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/22 15:27:34 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

static void	is_negative(t_philo_args *args, int *err)
{
	if (args->nb_philos < 0 || args->tsleep < 0 || args->tdie < 0
		|| args->teat < 0 || args->nb_tmust_eat < 0)
		*err = 1;
}

int	parse(t_philo_args *args, int argc, char const *argv[])
{
	int	err;

	err = 0;
	args->nb_philos = atoi_err_overflow(argv[1], &err);
	args->tdie = atoi_err_overflow(argv[2], &err);
	args->teat = atoi_err_overflow(argv[3], &err);
	args->tsleep = atoi_err_overflow(argv[4], &err);
	if (argc == 6)
		args->nb_tmust_eat = atoi_err_overflow(argv[5], &err);
	else
		args->nb_tmust_eat = 0;
	is_negative(args, &err);
	if (argc == 5)
		args->nb_tmust_eat = -1;
	if (err || args->nb_philos < 1)
	{
		printf("ERROR: Wrong values.\n");
		printf("Values should be integer positive values and <= INT_MAX.\n");
		return (0);
	}
	return (1);
}
