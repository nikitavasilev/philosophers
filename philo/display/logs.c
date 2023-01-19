/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:04:04 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/18 21:04:06 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_fork(size_t timestamp_in_ms, int philo_id)
{
	printf("%zu %d has taken a fork\n", timestamp_in_ms, philo_id);
}

void	print_eat(size_t timestamp_in_ms, int philo_id)
{
	printf("%zu %d is eating\n", timestamp_in_ms, philo_id);
}

void	print_sleep(size_t timestamp_in_ms, int philo_id)
{
	printf("%zu %d is sleeping\n", timestamp_in_ms, philo_id);
}

void	print_think(size_t timestamp_in_ms, int philo_id)
{
	printf("%zu %d is thinking\n", timestamp_in_ms, philo_id);
}

void	print_die(size_t timestamp_in_ms, int philo_id)
{
	printf("%zu %d died\n", timestamp_in_ms, philo_id);
}
