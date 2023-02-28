/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:49:38 by lsanglas          #+#    #+#             */
/*   Updated: 2021/11/22 12:49:39 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (*s1 == *s2 && n != 1 && *s1 != '\0')
		return ft_strncmp(s1 + 1, s2 + 1, --n);
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
