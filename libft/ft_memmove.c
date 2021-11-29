/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:47:51 by lsanglas          #+#    #+#             */
/*   Updated: 2021/11/22 12:47:53 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	if(dest == NULL && src == NULL)
		return (NULL);
	pd = (unsigned char *) dest;
	ps = (unsigned char *) src;
	if (0 < dest - src && dest - src < (long int)n)
	{
		pd += n;
		ps += n;
		while (n--)
			*--pd = *--ps;
	}
	else
		while (n--)
			*pd++ = *ps++;
	return ((void *) dest);
}
