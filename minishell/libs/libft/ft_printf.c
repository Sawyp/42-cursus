/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <malloc.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#include "libft.h"
#include "ft_printf/ft_string.h"

t_ft_string	translate_printf_format_string(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_ft_string	formatted_str;
	int			result;

	if (ft_strchr(format, '%') == NULL)
	{
		result = (int)ft_smin(ft_strlen(format), INT_MAX);
		ft_putstrn_fd(format, (size_t)result, 1);
		return (result);
	}
	va_start(args, format);
	formatted_str = translate_printf_format_string(format, args);
	va_end(args);
	if (formatted_str.str == NULL)
		return (0);
	write(1, formatted_str.str, formatted_str.len);
	result = (int)ft_smin(formatted_str.len, INT_MAX);
	return (free(formatted_str.str), result);
}
