/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*copy;
	size_t	i;

	src_len = ft_strlen(src);
	copy = malloc(sizeof(char) * (src_len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < src_len + 1)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
