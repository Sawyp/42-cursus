/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_atol.c                                        :+:      :+:    :+:   */
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

static char	leftmost_digit(long n)
{
	while (ft_labs(n) > 10)
		n /= 10;
	return ((char)('0' + ft_abs((int)n)));
}

static int	is_overflow(
		long current_value,
		size_t digit_index,
		unsigned long new_digit,
		long multiplier
)
{
	int				long_max_log;
	char			long_max_leftmost_digit;
	unsigned long	u_current_value;
	unsigned long	u_multiplier;
	unsigned long	u_max_value;

	long_max_log = ft_log(LONG_MAX, 10);
	long_max_leftmost_digit = leftmost_digit(LONG_MAX);
	if (digit_index < (size_t)long_max_log || new_digit == 0)
		return (0);
	if ((int)(new_digit + '0') < long_max_leftmost_digit)
		return (0);
	if ((int)(new_digit + '0') > long_max_leftmost_digit)
		return (1);
	u_current_value = current_value;
	u_multiplier = multiplier;
	u_max_value = LONG_MAX;
	if (current_value < 0)
	{
		u_current_value = -current_value;
		u_multiplier = -multiplier;
		u_max_value = (unsigned long)LONG_MAX + 1;
	}
	return (u_current_value + u_multiplier * new_digit > u_max_value);
}

static int	try_atol(
		const char *str,
		int sign,
		size_t digit_count,
		long *out
)
{
	long	multiplier;
	size_t	i;

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

int	ft_s_atol(const char *str, long *out)
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
	return (try_atol(str, sign, digit_count, out));
}
