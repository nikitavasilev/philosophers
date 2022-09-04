/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_err_overflow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:19 by nvasilev          #+#    #+#             */
/*   Updated: 2022/09/04 20:43:26 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>
#include <stdint.h>

static int	err_check(const char c, int *err, int end)
{
	if ((c && !ft_isdigit(c) && end) || (c == '\0' && !end))
	{
		*err = 1;
		return (1);
	}
	return (0);
}

static char	*conv_overflow(const char *str, char sign, int *err, __int64_t *nb)
{
	unsigned int	max;

	max = INT_MAX;
	*nb = 0;
	while (*str && ft_isdigit(*str))
	{
		*nb = *nb * 10 + (*str - '0');
		if (((int)(*nb) < 0 && !((int)(*nb) == INT_MIN && sign == -1))
			|| (*nb > (max + 1) && sign == -1))
		{
			*err = 1;
			break ;
		}
		str++;
	}
	return ((char *)str);
}

int	atoi_err_overflow(const char *str, int *err)
{
	__int64_t	nb;
	char		sign;

	while ((ft_isspace(*str)))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	if (err_check(*str, err, 0))
		return (1);
	str = conv_overflow(str, sign, err, &nb);
	if (*err)
		return (1);
	if (err_check(*str, err, 1))
		return (1);
	return (nb * sign);
}
