/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:03:57 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/30 00:43:30 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGS_H
# define LOGS_H

# include "core.h"

# define LOG_FORK		"has taken a fork"
# define LOG_EAT		"is eating"
# define LOG_SLEEP		"is sleeping"
# define LOG_THINK		"is thinking"
# define LOG_DIE		"died"
# define LOG_ARGS_ERROR	"ERROR: Wrong number of arguments."
# define LOG_USAGE		"Usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]"

int	print_message(t_philo *philo);

#endif
