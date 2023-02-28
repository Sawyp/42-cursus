/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_svec_element_access.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:38:14 by aronez            #+#    #+#             */
/*   Updated: 2022/10/25 11:38:14 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_svec_contains(const t_ft_svec *svec, size_t elem)
{
	size_t	index;

	index = 0;
	while (index < svec->length)
	{
		if (svec->data[index] == elem)
			return (1);
		index++;
	}
	return (0);
}
