/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

char	*ft_strndup(const char *src, size_t count)
{
	size_t	src_len;
	char	*copy;
	size_t	i;

	src_len = 0;
	while (src_len < count && src[src_len] != '\0')
		src_len++;
	copy = malloc(sizeof(char) * (src_len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
