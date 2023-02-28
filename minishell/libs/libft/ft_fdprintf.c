/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:43:35 by aronez            #+#    #+#             */
/*   Updated: 2022/11/24 14:43:35 by aronez           ###   ########.fr       */
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

int	ft_fdprintf(int fd, const char *format, ...)
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
	if (write(fd, formatted_str.str, formatted_str.len) < 0)
		return (free(formatted_str.str), -1);
	result = (int)ft_smin(formatted_str.len, INT_MAX);
	return (free(formatted_str.str), result);
}
