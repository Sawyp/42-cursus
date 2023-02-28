/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <malloc.h>

#include "libft.h"

static int	checked_base_length(const char *base)
{
	size_t	str_len;
	int		base_len;
	int		i;

	str_len = ft_strlen(base);
	if (str_len > INT_MAX)
		return (0);
	base_len = (int)str_len;
	i = 0;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (ft_strchr(base, base[i]) != base + i)
			return (0);
		i++;
	}
	return (base_len);
}

char	*ft_ulltoa_base(unsigned long long n, const char *base)
{
	int		base_len;
	size_t	digit_count;
	char	*result;

	base_len = checked_base_length(base);
	if (base_len < 2)
		return (NULL);
	digit_count = ft_ulog(n, base_len) + 1;
	result = malloc(sizeof(char) * (digit_count + 1));
	if (result == NULL)
		return (NULL);
	result[digit_count] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[digit_count - 1] = base[n % base_len];
		digit_count--;
		n /= base_len;
	}
	return (result);
}
