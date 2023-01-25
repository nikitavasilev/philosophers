/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:29:14 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/25 23:56:26 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <stdio.h>

void	print_args(t_data *data)
{
	printf("number_of_philosophers: %d\n", data->nb_philos);
	printf("time_to_die: %ld\n", data->time_to_die);
	printf("time_to_eat: %ld\n", data->time_to_eat);
	printf("time_to_sleep: %ld\n", data->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n",
		data->nb_tmust_eat);
}
