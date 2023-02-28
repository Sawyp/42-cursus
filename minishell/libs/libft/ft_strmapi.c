/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	str_len;
	char			*result;
	unsigned int	i;

	str_len = ft_strlen(str);
	result = malloc(sizeof(char) * (str_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[str_len] = '\0';
	return (result);
}
