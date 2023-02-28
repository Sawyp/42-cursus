/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:59:00 by lsanglas          #+#    #+#             */
/*   Updated: 2022/10/22 11:59:35 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	min(long x, long y)
{
	if (x > y)
		return (y);
	return (x);
}

long	ft_abs(long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

long	max(long x, long y)
{
	if (x > y)
		return (x);
	return (y);
}

long	dist(long x, t_array *arr)
{
	if (x < ft_abs(x - arr->size))
		return (x);
	return (ft_abs(x - arr->size));
}

int	is_sorted(t_array arr)
{
	int	i;

	i = -1;
	while (++i < arr.size - 1)
	{
		if (arr.arr[i] > arr.arr[i + 1])
			return (0);
	}
	return (1);
}
