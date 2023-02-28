/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "libft.h"

static int	str_counter(const char *substr, size_t len, void *data)
{
	(void)substr;
	(void)len;
	(*(size_t *)data)++;
	return (0);
}

static int	str_maker(const char *substr, size_t len, void *data)
{
	char	**strs;

	strs = (char **)data;
	while (*strs != NULL)
		strs++;
	*strs = ft_strndup(substr, len);
	if (*strs == NULL)
		return (-1);
	return (0);
}

static int	invoke_on_substrs(
		const char *str,
		char c,
		int (*f)(const char *, size_t, void *),
		void *data
		)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (j - i > 0 && f(str + j, i - j, data) < 0)
				return (-1);
			j = i + 1;
		}
		i++;
	}
	if (j - i > 0)
		f(str + (j), i - j, data);
	return (0);
}

char	**ft_split(const char *str, char c)
{
	size_t	strs_count;
	char	**strs;

	strs_count = 0;
	if (invoke_on_substrs(str, c, &str_counter, &strs_count) < 0)
		return (NULL);
	strs = ft_calloc(strs_count + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	if (invoke_on_substrs(str, c, &str_maker, strs) < 0)
	{
		ft_free_strs(strs);
		return (NULL);
	}
	return (strs);
}
