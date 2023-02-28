/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *str, int ch, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	if (i < count && ch == '\0')
		return ((char *)(str + i));
	return (NULL);
}
