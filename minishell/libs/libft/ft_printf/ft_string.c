/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
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

static size_t	compute_combined_len(const t_ft_string *strs, size_t count)
{
	size_t	str_len;
	size_t	i;

	str_len = 0;
	i = 0;
	while (i < count)
	{
		str_len += strs[i].len;
		i++;
	}
	return (str_len);
}

static void	join(const t_ft_string *strs, size_t count, char *result)
{
	size_t	result_i;
	size_t	strs_i;
	size_t	str_i;

	result_i = 0;
	strs_i = 0;
	str_i = 0;
	while (strs_i < count)
	{
		if (str_i == strs[strs_i].len)
		{
			strs_i++;
			str_i = 0;
		}
		else
		{
			result[result_i] = strs[strs_i].str[str_i];
			str_i++;
			result_i++;
		}
	}
}

t_ft_string	ft_stringnjoin(const t_ft_string *strings, size_t count)
{
	t_ft_string	result;

	result.len = compute_combined_len(strings, count);
	result.str = malloc(sizeof(char) * (result.len + 1));
	if (result.str == NULL)
		return ((t_ft_string){NULL, 0});
	join(strings, count, result.str);
	result.str[result.len] = '\0';
	return (result);
}
