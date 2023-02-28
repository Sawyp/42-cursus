/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:41:05 by lsanglas          #+#    #+#             */
/*   Updated: 2022/10/22 11:41:06 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_array *arr)
{
	int			i;
	const long	tmp = arr->arr[0];

	i = -1;
	while (++i < arr->size - 1)
		arr->arr[i] = arr->arr[i + 1];
	arr->arr[arr->size - 1] = tmp;
}

void	rrotate(t_array *arr)
{
	int			i;
	const long	tmp = arr->arr[arr->size - 1];

	i = arr->size;
	while (--i > 0)
		arr->arr[i] = arr->arr[i - 1];
	arr->arr[0] = tmp;
}

void	rr(t_array *a, t_array *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rrr(t_array *a, t_array *b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}

void	pop(t_array *arr1, t_array *arr2)
{
	if ((*arr2).size)
	{
		(*arr2).arr[(*arr2).size] = (*arr2).arr[(*arr2).size - 1];
		rrotate(arr2);
	}
	(*arr2).arr[0] = (*arr1).arr[0];
	(*arr2).size += 1;
	rotate(arr1);
	(*arr1).size -= 1;
}
