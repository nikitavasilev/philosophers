/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:04:04 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/28 07:48:21 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "logs.h"
#include "core.h"
#include "utils.h"

void	print_message(t_philo *philo)
{
	time_t	current_time;
	time_t	start_time;

	current_time = get_time_ms();
	start_time = philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_lock);
	if (philo->state == TAKING_FORK)
		printf("%zu %d %s\n", current_time - start_time, philo->id, LOG_FORK);
	else if (philo->state == EATING)
		printf("%zu %d %s\n", current_time - start_time, philo->id, LOG_EAT);
	else if (philo->state == SLEEPING)
		printf("%zu %d %s\n", current_time - start_time, philo->id, LOG_SLEEP);
	else if (philo->state == THINKING)
		printf("%zu %d %s\n", current_time - start_time, philo->id, LOG_THINK);
	else if (philo->state == DIED)
		printf("%zu %d %s\n", current_time - start_time, philo->id, LOG_DIE);
	pthread_mutex_unlock(&philo->data->print_lock);
}
