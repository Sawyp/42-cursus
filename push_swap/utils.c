/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:40:54 by lsanglas          #+#    #+#             */
/*   Updated: 2022/10/22 11:40:56 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_pow(long x, long y)
{
	if (y)
		return (x * ft_pow(x, y - 1));
	return (1);
}

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (ft_strlen(++str) + 1);
}

int	is_num(char *str)
{
	if (!*str)
		return (1);
	if (*str == '-')
		return (-1 * is_num(str + 1));
	else if (!(*str > 47 && *str < 58))
		return (0);
	return (is_num(str + 1));
}

long	is_in(t_array arr, long x)
{
	int	i;

	i = -1;
	while (++i < arr.size)
	{
		if (arr.arr[i] == x)
			return (i + 1);
	}
	return (0);
}

long	ft_atol(char *str)
{
	long	x;
	long	sign;

	sign = 1;
	x = 0;
	if (!*str)
		return (0);
	if (*str == '-' && ++str)
		sign = -1;
	if (!(*str <= '9' && *str >= '0'))
		return (2147483649);
	while (*str && *str <= '9' && *str >= '0')
	{
		x += (*str - '0') * ft_pow(10, ft_strlen(str) - 1);
		++str;
	}
	if (*str)
		return (2147483649);
	return (x * sign);
}
