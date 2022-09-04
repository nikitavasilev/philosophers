/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:35:00 by nvasilev          #+#    #+#             */
/*   Updated: 2022/09/04 21:36:15 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

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
	if (err)
	{
		printf("ERROR: Wrong values.\n");
		printf("Values should be integer positive values and <= INT_MAX.\n");
		return (0);
	}
	return (1);
}