/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:09:25 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/26 02:15:22 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "core.h"

int		atoi_err_overflow(const char *str, int *err);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	print_args(t_data *data);
time_t	get_time_ms(void);

#endif
