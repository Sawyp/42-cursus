/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_formatted_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "../libft.h"
#include "ft_string.h"

t_ft_string	handle_printf_code(char code, va_list args);

static size_t	count_strs(const char *format_str)
{
	size_t	count;

	count = 0;
	format_str = ft_strchr(format_str, '%');
	while (format_str != NULL)
	{
		count++;
		format_str = ft_strchr(format_str + 2, '%');
	}
	return (count + (count + 1));
}

static void	free_strs(t_ft_string *strs, size_t strs_count)
{
	size_t	i;

	i = 0;
	while (i < strs_count)
	{
		free(strs[i].str);
		i++;
	}
}

static int	parse_strs(
		const char *format,
		va_list args,
		t_ft_string *strs,
		size_t strs_count
		)
{
	size_t		strs_i;
	const char	*prev_cc;
	const char	*cc;

	strs_i = 0;
	prev_cc = format;
	cc = ft_strchr(prev_cc, '%');
	while (cc != NULL)
	{
		strs[strs_i].str = ft_strndup(prev_cc, (size_t)(cc - prev_cc));
		strs[strs_i].len = (size_t)(cc - prev_cc);
		strs[strs_i + 1] = handle_printf_code(*(cc + 1), args);
		if (strs[strs_i].str == NULL || strs[strs_i + 1].str == NULL)
			return (free_strs(strs, strs_count), -1);
		strs_i += 2;
		prev_cc = cc + 2;
		cc = ft_strchr(prev_cc, '%');
	}
	strs[strs_i].str = ft_strdup(prev_cc);
	if (strs[strs_i].str == NULL)
		return (free_strs(strs, strs_count), -1);
	strs[strs_i].len = ft_strlen(strs[strs_i].str);
	return (0);
}

static t_ft_string	*make_strs(
		const char *format,
		size_t strs_count,
		va_list args
		)
{
	t_ft_string	*strs;

	strs = ft_calloc(strs_count, sizeof(t_ft_string));
	if (strs == NULL)
		return (NULL);
	if (parse_strs(format, args, strs, strs_count) < 0)
		return (free(strs), NULL);
	return (strs);
}

t_ft_string	translate_printf_format_string(const char *format, va_list args)
{
	size_t			strs_count;
	t_ft_string		*strs;
	t_ft_string		formatted_str;

	strs_count = count_strs(format);
	strs = make_strs(format, strs_count, args);
	if (strs == NULL)
		return ((t_ft_string){NULL, 0});
	formatted_str = ft_stringnjoin(strs, strs_count);
	free_strs(strs, strs_count);
	free(strs);
	return (formatted_str);
}
