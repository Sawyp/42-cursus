/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_smax(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

long	ft_lmax(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

long long	ft_llmax(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}
