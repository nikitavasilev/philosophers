/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:29:14 by nvasilev          #+#    #+#             */
/*   Updated: 2022/09/04 21:32:30 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <stdio.h>

void	print_args(t_philo_args *args)
{
	printf("number_of_philosophers: %d\n", args->nb_philos);
	printf("time_to_die: %d\n", args->tdie);
	printf("time_to_eat: %d\n", args->teat);
	printf("time_to_sleep: %d\n", args->tsleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n", args->nb_tmust_eat);
}
