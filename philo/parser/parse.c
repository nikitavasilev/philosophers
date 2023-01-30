/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:35:00 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 17:02:46 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

static void	is_negative(t_data *data, int *err)
{
	if ((short)data->nb_philos < 0 || data->time_to_sleep < 0
		|| data->time_to_die < 0 || data->time_to_eat < 0
		|| (int)data->nb_tmust_eat < 0)
		*err = 1;
}

int	parse(t_data *data, int argc, char const *argv[])
{
	int	err;

	err = 0;
	data->nb_philos = atoi_err_overflow(argv[1], &err);
	data->time_to_die = atoi_err_overflow(argv[2], &err);
	data->time_to_eat = atoi_err_overflow(argv[3], &err);
	data->time_to_sleep = atoi_err_overflow(argv[4], &err);
	if (argc == 6)
		data->nb_tmust_eat = atoi_err_overflow(argv[5], &err);
	else
		data->nb_tmust_eat = 0;
	is_negative(data, &err);
	if (argc == 5)
		data->nb_tmust_eat = -1;
	if (err || data->nb_philos < 1 || data->nb_tmust_eat < 1)
	{
		printf("ERROR: Wrong values.\n");
		printf("Values should be integer positive values and <= INT_MAX.\n");
		return (0);
	}
	return (1);
}
