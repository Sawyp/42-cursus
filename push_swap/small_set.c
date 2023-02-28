/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:10:31 by lsanglas          #+#    #+#             */
/*   Updated: 2022/10/26 13:10:35 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_array *a)
{
	long	tmp;

	tmp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = tmp;
}

void	sort_3(t_array a, t_array lis)
{
	lis = lis_stage2(a);
	if (lis.size == a.size)
	{
		rotate(&a);
		if (is_sorted(a))
			write(1, "ra\n", 3);
		else
			write(1, "rra\n", 4);
		return ;
	}
	instruction_and_print(&a, &swap, "sa\n");
	if (is_sorted(a))
		return ;
	rotate(&a);
	if (is_sorted(a))
		write(1, "ra\n", 3);
	else
		write(1, "rra\n", 4);
}

void	small_data_set(t_array a, t_array b, t_array lis, int ac)
{
	if (ac < 5)
		return (sort_3(a, lis));
	pop(&a, &b);
	pop(&a, &b);
	write(1, "pb\npb\n", 6);
	lis = lis_stage2(a);
	if (lis.size != a.size)
		instruction_and_print(&a, &swap, "sa\n");
	pop_b_in_order(&a, &b);
	smallest_on_top(&a);
}
