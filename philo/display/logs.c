/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:04:04 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/26 03:19:40 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "logs.h"

void	print_message(time_t time_in_ms, unsigned short philo_id, t_state state)
{
	if (state == FORK)
		printf("%zu %d %s\n", time_in_ms, philo_id, LOG_FORK);
	else if (state == EAT)
		printf("%zu %d %s\n", time_in_ms, philo_id, LOG_EAT);
	else if (state == SLEEP)
		printf("%zu %d %s\n", time_in_ms, philo_id, LOG_SLEEP);
	else if (state == THINK)
		printf("%zu %d %s\n", time_in_ms, philo_id, LOG_THINK);
	else if (state == DIE)
		printf("%zu %d %s\n", time_in_ms, philo_id, LOG_DIE);
}
