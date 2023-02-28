/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:55:02 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/30 13:55:02 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_memswap(void *a, void *b, size_t count)
{
	size_t	i;
	char	tmp;

	i = -1;
	while (++i < count)
	{
		tmp = ((char *)a)[i];
		((char *)a)[i] = ((char *)b)[i];
		((char *)b)[i] = tmp;
	}
}
