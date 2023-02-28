/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

char	*ft_substr(const char *str, size_t start, size_t len)
{
	char	*result;
	size_t	res_len;
	size_t	i;

	if (start >= ft_strlen(str))
		res_len = 0;
	else
		res_len = ft_smin(ft_strlen(str) - start, len);
	result = malloc(sizeof(char) * (res_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < res_len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
