/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:06:36 by nvasilev          #+#    #+#             */
/*   Updated: 2023/01/28 07:53:20 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "parser.h"
#include "logs.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf("%s\n%s\n", LOG_ARGS_ERROR, LOG_USAGE), EXIT_FAILURE);
	if (!parse(&data, argc, argv))
		return (EXIT_FAILURE);
	if (!init_data(&data))
		return (EXIT_FAILURE);
	create_threads(&data);
	destroy(&data);
	return (EXIT_SUCCESS);
}
