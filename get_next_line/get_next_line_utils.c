/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:30:38 by lsanglas          #+#    #+#             */
/*   Updated: 2021/12/14 15:30:39 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	if (!*str)
		return (0);
	return (ft_strlen(str + 1) + 1);
}

char	*ft_strchr(const char *s, int c)
{
	if (*s == (unsigned char)c)
		return ((char *) s);
	if (!*s)
		return ("\0");
	return (ft_strchr(s + 1, c));
}

static char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	if ((int) n > 0)
	{
		*dst = *src;
		return (ft_strncpy(dst + 1, src + 1, --n));
	}
	return (dst);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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

char	*ft_strnjoin(char **s1, const char *s2, size_t n)
{
	char	*dst;

	dst = malloc(ft_strlen(*s1) + n + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, *s1, ft_strlen(*s1) + 1);
	ft_strlcpy(dst + ft_strlen(*s1), s2, n + 1);
	free(*s1);
	if (*dst)
		return (dst);
	free(dst);
	return (NULL);
}
