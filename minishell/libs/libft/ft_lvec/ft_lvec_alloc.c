/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvec_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:12:50 by aronez            #+#    #+#             */
/*   Updated: 2022/10/25 11:12:50 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <malloc.h>

#ifndef DEFAULT_NEW_ALLOC_SIZE
# define DEFAULT_NEW_ALLOC_SIZE 10
#endif

void	ft_lvec_free(t_ft_lvec *lvec)
{
	free(lvec->data);
}

int	ft_lvec_new(t_ft_lvec *lvec)
{
	return (ft_lvec_with_capacity(lvec, DEFAULT_NEW_ALLOC_SIZE));
}

int	ft_lvec_with_capacity(t_ft_lvec *lvec, size_t capacity)
{
	lvec->data = malloc(sizeof(long) * capacity);
	if (lvec->data == NULL)
		return (-1);
	lvec->capacity = capacity;
	lvec->length = 0;
	return (0);
}

int	ft_lvec_clone(const t_ft_lvec *src, t_ft_lvec *dst)
{
	if (ft_lvec_with_capacity(dst, src->length) < 0)
		return (-1);
	ft_memcpy(dst->data, src->data, sizeof(long) * src->length);
	dst->length = src->length;
	return (0);
}

int	ft_lvec_assign(const t_ft_lvec *src, t_ft_lvec *dst)
{
	if (dst->capacity >= src->length)
	{
		ft_memcpy(dst->data, src->data, sizeof(long) * src->length);
		dst->length = src->length;
		return (0);
	}
	ft_lvec_free(dst);
	return (ft_lvec_clone(src, dst));
}
