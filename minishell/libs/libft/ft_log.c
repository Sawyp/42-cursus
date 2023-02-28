/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_log(long long n, int base)
{
	int	log;

	log = 0;
	while (n / base != 0)
	{
		n /= base;
		log++;
	}
	return (log);
}

int	ft_ulog(unsigned long long n, int base)
{
	int	log;

	log = 0;
	while (n / base != 0)
	{
		n /= base;
		log++;
	}
	return (log);
}
