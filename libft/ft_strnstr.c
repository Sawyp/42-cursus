/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:50:15 by lsanglas          #+#    #+#             */
/*   Updated: 2021/11/22 12:50:17 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "signal.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	if (!big)
		*((char *)big - 42) = 42;
	if ((n >= ft_strlen(little) && !ft_strncmp(big, little, ft_strlen(little)))
		|| *little == '\0')
		return ((char *) big);
	else if (n >= ft_strlen(little) && *big != '\0')
		return (ft_strnstr(big + 1, little, n - 1));
	return (NULL);
}