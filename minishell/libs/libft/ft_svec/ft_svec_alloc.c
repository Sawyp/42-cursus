/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_svec_alloc.c                                    :+:      :+:    :+:   */
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

void	ft_svec_free(t_ft_svec *svec)
{
	free(svec->data);
}

int	ft_svec_new(t_ft_svec *svec)
{
	return (ft_svec_with_capacity(svec, DEFAULT_NEW_ALLOC_SIZE));
}

int	ft_svec_with_capacity(t_ft_svec *svec, size_t capacity)
{
	svec->data = malloc(sizeof(size_t) * capacity);
	if (svec->data == NULL)
		return (-1);
	svec->capacity = capacity;
	svec->length = 0;
	return (0);
}

int	ft_svec_clone(const t_ft_svec *src, t_ft_svec *dst)
{
	if (ft_svec_with_capacity(dst, src->length) < 0)
		return (-1);
	ft_memcpy(dst->data, src->data, sizeof(size_t) * src->length);
	dst->length = src->length;
	return (0);
}

int	ft_svec_assign(const t_ft_svec *src, t_ft_svec *dst)
{
	if (dst->capacity >= src->length)
	{
		ft_memcpy(dst->data, src->data, sizeof(size_t) * src->length);
		dst->length = src->length;
		return (0);
	}
	ft_svec_free(dst);
	return (ft_svec_clone(src, dst));
}
