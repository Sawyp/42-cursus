/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *substr)
{
	size_t	str_len;
	size_t	substr_len;
	size_t	i;

	substr_len = ft_strlen(substr);
	if (substr_len == 0)
		return ((char *)str);
	str_len = ft_strlen(str);
	i = 0;
	while (i + substr_len <= str_len)
	{
		if (ft_strncmp(str + i, substr, substr_len) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
