/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:50:02 by lsanglas          #+#    #+#             */
/*   Updated: 2021/11/22 12:50:03 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	else if (*(unsigned char *) s1 == *(unsigned char *) s2)
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
