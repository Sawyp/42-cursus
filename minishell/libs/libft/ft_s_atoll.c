/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_atoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "libft.h"

static int	extract_sign(const char **str)
{
	int	multiplier;

	while (ft_isspace(**str))
		(*str)++;
	multiplier = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			multiplier = -1;
		(*str)++;
	}
	return (multiplier);
}

static char	leftmost_digit(long long n)
{
	while (ft_llabs(n) > 10)
		n /= 10;
	return ((char)('0' + ft_abs((int)n)));
}

static int	is_overflow(
		long long current_value,
		size_t digit_index,
		unsigned long long new_digit,
		long long multiplier
		)
{
	int					llong_max_log;
	char				llong_max_leftmost_digit;
	unsigned long long	u_current_value;
	unsigned long long	u_multiplier;
	unsigned long long	u_max_value;

	llong_max_log = ft_log(LLONG_MAX, 10);
	llong_max_leftmost_digit = leftmost_digit(LLONG_MAX);
	if (digit_index < (size_t)llong_max_log || new_digit == 0)
		return (0);
	if ((int)(new_digit + '0') < llong_max_leftmost_digit)
		return (0);
	if ((int)(new_digit + '0') > llong_max_leftmost_digit)
		return (1);
	u_current_value = current_value;
	u_multiplier = multiplier;
	u_max_value = LLONG_MAX;
	if (current_value < 0)
	{
		u_current_value = -current_value;
		u_multiplier = -multiplier;
		u_max_value = (unsigned long long)LLONG_MAX + 1;
	}
	return (u_current_value + u_multiplier * new_digit > u_max_value);
}

static int	try_atoll(
		const char *str,
		int sign,
		size_t digit_count,
		long long *out
		)
{
	long long	multiplier;
	size_t		i;

	*out = 0;
	multiplier = sign;
	i = 0;
	while (i < digit_count)
	{
		if (is_overflow(
				*out,
				i,
				str[digit_count - 1 - i] - '0',
				multiplier
			))
			return (-3);
		*out += multiplier * (str[digit_count - 1 - i] - '0');
		multiplier *= 10;
		i++;
	}
	return (0);
}

int	ft_s_atoll(const char *str, long long *out)
{
	int		sign;
	size_t	digit_count;

	if (str == NULL || out == NULL)
		return (-1);
	sign = extract_sign(&str);
	digit_count = 0;
	while (ft_isdigit(str[digit_count]))
		digit_count++;
	if (digit_count == 0)
		return (-2);
	return (try_atoll(str, sign, digit_count, out));
}
