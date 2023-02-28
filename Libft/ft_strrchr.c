/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:49:19 by lsanglas          #+#    #+#             */
/*   Updated: 2021/11/22 12:49:19 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	
	len = ft_strlen(s);
	while (*(s + len) != c && --len > 0)
		;
	if (!len)
		return (NULL);
	return ((char *) s + len);
}
