/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	sub_str_len;
	size_t	i;

	sub_str_len = ft_strlen(substr);
	if (sub_str_len == 0)
		return ((char *)str);
	i = 0;
	while (i + sub_str_len <= ft_smin(len, ft_strlen(str)))
	{
		if (ft_strncmp(str + i, substr, sub_str_len) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
