/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:56:51 by lsanglas          #+#    #+#             */
/*   Updated: 2022/09/12 16:56:52 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (ft_strlen(++str) + 1);
}

static char	*ft_strncpy(char *dst, char *src, size_t n)
{
	if ((int) n > 0)
	{
		*dst = *src;
		return (ft_strncpy(dst + 1, src + 1, --n));
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	const size_t	srclen = ft_strlen(src);

	if (srclen + 1 < size)
		ft_strncpy(dst, src, srclen + 1);
	else if (size != 0)
	{
		ft_strncpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclen);
}

char	*ft_strjoin_command(char *s1, char *s2)
{
	char	*dst;

	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	dst[ft_strlen(s1)] = '/';
	ft_strlcpy(dst + ft_strlen(s1) + 1, s2, ft_strlen(s2) + 1);
	return (dst);
}
