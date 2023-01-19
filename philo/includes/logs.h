/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:03:57 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/18 21:05:41 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGS_H
# define LOGS_H

# include <sys/types.h>

void	print_fork(size_t timestamp_in_ms, int philo_id);
void	print_eat(size_t timestamp_in_ms, int philo_id);
void	print_sleep(size_t timestamp_in_ms, int philo_id);
void	print_think(size_t timestamp_in_ms, int philo_id);
void	print_die(size_t timestamp_in_ms, int philo_id);

#endif
