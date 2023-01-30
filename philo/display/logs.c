/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:04:04 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 15:55:17 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "logs.h"
#include "core.h"
#include "utils.h"

static void	select_msg_to_print(t_philo *philo, time_t curr, time_t start)
{
	pthread_mutex_lock(&philo->data->print_lock);
	pthread_mutex_lock(&philo->data->state_lock);
	if (philo->state == TAKING_FORK)
		printf("%zu %d %s\n", curr - start, philo->id, LOG_FORK);
	else if (philo->state == EATING)
		printf("%zu %d %s\n", curr - start, philo->id, LOG_EAT);
	else if (philo->state == SLEEPING)
		printf("%zu %d %s\n", curr - start, philo->id, LOG_SLEEP);
	else if (philo->state == THINKING)
		printf("%zu %d %s\n", curr - start, philo->id, LOG_THINK);
	pthread_mutex_unlock(&philo->data->state_lock);
	pthread_mutex_unlock(&philo->data->print_lock);
}

int	print_message(t_philo *philo)
{
	time_t	current_time;
	time_t	start_time;

	current_time = get_time_ms();
	start_time = philo->data->start_time;
	pthread_mutex_lock(&philo->data->check_death_lock);
	if (!philo->data->one_died)
		select_msg_to_print(philo, current_time, start_time);
	else
	{
		pthread_mutex_unlock(&philo->data->check_death_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->check_death_lock);
	return (1);
}

void	print_death(t_philo *philo)
{
	time_t	current_time;
	time_t	start_time;

	current_time = get_time_ms();
	start_time = philo->data->start_time;
	pthread_mutex_lock(&philo->data->print_lock);
	printf("%zu %d %s\n", current_time - start_time, philo->id, LOG_DIE);
	pthread_mutex_unlock(&philo->data->print_lock);
}
