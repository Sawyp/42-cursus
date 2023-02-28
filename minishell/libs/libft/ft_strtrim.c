/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	result_len;
	char	*result;

	i = 0;
	while (i < ft_strlen(str) && ft_strchr(set, str[i]) != NULL)
		i++;
	j = ft_strlen(str) - 1;
	while (j >= i && ft_strchr(set, str[j]) != NULL)
		j--;
	result_len = j - i + 1;
	result = malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	while (j < result_len)
	{
		result[j] = str[i + j];
		j++;
	}
	result[result_len] = '\0';
	return (result);
}
