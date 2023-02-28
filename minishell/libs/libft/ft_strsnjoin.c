/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsnjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

static size_t	compute_combined_len(const char **strs, size_t count)
{
	size_t	str_len;
	size_t	i;

	str_len = 0;
	i = 0;
	while (i < count)
	{
		str_len += ft_strlen(strs[i]);
		i++;
	}
	return (str_len);
}

static void	join(const char **strs, size_t count, char *result)
{
	size_t	result_i;
	size_t	strs_i;
	size_t	str_i;

	result_i = 0;
	strs_i = 0;
	str_i = 0;
	while (strs_i < count)
	{
		if (strs[strs_i][str_i] == '\0')
		{
			strs_i++;
			str_i = 0;
		}
		else
		{
			result[result_i] = strs[strs_i][str_i];
			str_i++;
			result_i++;
		}
	}
}

char	*ft_strsnjoin(const char **strs, size_t count)
{
	size_t	str_len;
	char	*result;

	str_len = compute_combined_len(strs, count);
	result = malloc(sizeof(char) * (str_len + 1));
	if (result == NULL)
		return (NULL);
	join(strs, count, result);
	result[str_len] = '\0';
	return (result);
}
