/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_svec_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:25:00 by aronez            #+#    #+#             */
/*   Updated: 2022/10/25 16:25:00 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_svec_push_back(t_ft_svec *svec, size_t new_elem)
{
	size_t	extra_bytes;

	if (svec->capacity == svec->length)
	{
		extra_bytes = ft_smin(sizeof(size_t) * svec->capacity, 65536);
		svec->data = ft_realloc(
				svec->data,
				sizeof(size_t) * svec->capacity,
				extra_bytes
				);
		svec->capacity += extra_bytes / sizeof(size_t);
		if (svec->data == NULL)
			return (-1);
	}
	svec->data[svec->length] = new_elem;
	svec->length++;
	return (0);
}

int	ft_svec_pop_back(t_ft_svec *svec, size_t *prev_back_val)
{
	if (svec->length == 0)
		return (-2);
	svec->length--;
	*prev_back_val = svec->data[svec->length];
	return (0);
}
