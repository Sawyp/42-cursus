/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:48:19 by lsanglas          #+#    #+#             */
/*   Updated: 2021/11/22 12:48:20 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	ft_min(int x, int y)
{
	return ((x + y - ft_abs(x - y)) / 2);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const int	len = ft_min(ft_strlen(dst), size) + ft_strlen(src);
	char	*ps;

	ps = (char *) src;
	while (*dst && ++dst && (int)--size > 0)
		;
	while (*ps && (int)--size > 0)
		*dst++ = *ps++;
	if ((int)ft_strlen(dst) > ft_min(ft_strlen(dst), size) || !*ps)
		*dst = 0;
	return (len);
}
