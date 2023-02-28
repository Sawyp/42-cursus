/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:40:46 by lsanglas          #+#    #+#             */
/*   Updated: 2022/10/22 11:40:51 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_array(t_array l1, t_array l2)
{
	int	i;

	i = -1;
	while (++i < l2.size)
		l1.arr[i] = l2.arr[i];
}

t_array	longest_array(t_array **arrays, long n)
{
	t_array	v;
	int		tmp;
	int		i;

	tmp = 0;
	i = -1;
	while (++i < n)
	{
		if ((*arrays)[i].size > (*arrays)[tmp].size)
			tmp = i;
	}
	i = -1;
	while (++i < n)
	{
		if (i != tmp)
			free((*arrays)[i].arr);
	}
	return (v = (*arrays)[tmp], free(*arrays), v);
}

t_array	lis_finder(t_array arr)
{
	t_array	*lis;
	int		i;
	int		j;

	lis = malloc(arr.size * sizeof(t_array));
	lis[0] = (t_array){1, malloc(arr.size * sizeof(long)), NULL, NULL};
	lis[0].arr[0] = arr.arr[0];
	i = 0;
	while (++i < arr.size)
	{
		lis[i] = (t_array){1, malloc(arr.size * sizeof(long)), NULL, NULL};
		lis[i].arr[0] = arr.arr[i];
		j = -1;
		while (++j < i)
		{
			if (!(arr.arr[i] > arr.arr[j] && lis[i].size < lis[j].size + 1))
				continue ;
			lis[i].size = lis[j].size + 1;
			copy_array(lis[i], lis[j]);
			lis[i].arr[lis[j].size] = arr.arr[i];
		}
	}
	return (longest_array(&lis, arr.size));
}

t_array	lis_stage2(t_array arr)
{
	int		i;
	t_array	*lis;

	lis = malloc(arr.size * sizeof(t_array));
	i = -1;
	while (++i < arr.size)
	{
		lis[i] = lis_finder(arr);
		rrotate(&arr);
	}
	return (longest_array(&lis, arr.size));
}
