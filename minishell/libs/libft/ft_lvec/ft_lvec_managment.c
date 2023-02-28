/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvec_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:25:00 by aronez            #+#    #+#             */
/*   Updated: 2022/10/25 16:25:00 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lvec_push_back(t_ft_lvec *lvec, long new_elem)
{
	size_t	extra_bytes;

	if (lvec->capacity == lvec->length)
	{
		extra_bytes = ft_smin(sizeof(long) * lvec->capacity, 65536);
		lvec->data = ft_realloc(
				lvec->data,
				sizeof(long) * lvec->capacity,
				extra_bytes
				);
		lvec->capacity += extra_bytes / sizeof(long);
		if (lvec->data == NULL)
			return (-1);
	}
	lvec->data[lvec->length] = new_elem;
	lvec->length++;
	return (0);
}

int	ft_lvec_pop_back(t_ft_lvec *lvec, long *prev_back_val)
{
	if (lvec->length == 0)
		return (-2);
	lvec->length--;
	*prev_back_val = lvec->data[lvec->length];
	return (0);
}
