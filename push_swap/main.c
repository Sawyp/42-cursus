/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:41:00 by lsanglas          #+#    #+#             */
/*   Updated: 2022/10/22 11:41:01 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	nearest_element(t_array *a, t_array *b)
{
	long	i;
	long	j;
	long	tmp;
	long	min_index;

	i = -1;
	min_index = 0;
	while (++i < b->size)
	{
		tmp = -1;
		j = -1;
		while (++j < a->size)
		{
			if (b->arr[i] < a->arr[j] && (tmp == -1 || a->arr[j] < a->arr[tmp]))
				tmp = j;
		}
		if (tmp == -1)
			tmp = smallest_element(*a);
		b->paired[i] = tmp;
		b->indexes[i] = min(max(ft_abs(i - b->size), ft_abs(tmp - a->size)),
				min(max(i, tmp), dist(i, b) + dist(tmp, a)));
		if (b->indexes[i] < b->indexes[min_index])
			min_index = i;
	}
	return (min_index);
}

void	pop_non_lis_elements(t_array *a, t_array *b, t_array lis)
{
	int			i;
	const int	size = a->size;

	i = -1;
	while (++i < size)
	{
		if (!is_in(lis, a->arr[0]))
		{
			pop(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
}

void	get_in_pos(t_array *a, t_array *b, long min_index)
{
	int	i;

	i = -1;
	while (++i < dist(b->paired[min_index], a))
	{
		if (b->paired[min_index] < ft_abs(b->paired[min_index] - a->size))
			instruction_and_print(a, &rotate, "ra\n");
		else
			instruction_and_print(a, &rrotate, "rra\n");
	}
	i = -1;
	while (++i < min(min_index, ft_abs(min_index - b->size)))
	{
		if (min_index < ft_abs(min_index - b->size))
			instruction_and_print(b, &rotate, "rb\n");
		else
			instruction_and_print(b, &rrotate, "rrb\n");
	}
}

void	pop_b_in_order(t_array *a, t_array *b)
{
	int		i;
	long	min_index;

	while (b->size)
	{
		i = -1;
		min_index = nearest_element(a, b);
		if (b->paired[min_index] < ft_abs(b->paired[min_index] - a->size)
			&& min_index < ft_abs(min_index - b->size))
		{
			while (++i < min(dist(min_index, b), dist(b->paired[min_index], a)))
				rr(a, b);
		}
		else if (b->paired[min_index] >= ft_abs(b->paired[min_index] - a->size)
			&& min_index >= ft_abs(min_index - b->size))
		{
			while (++i < min(min(min_index, ft_abs(min_index - b->size)),
					min(b->paired[min_index],
						ft_abs(b->paired[min_index] - a->size))))
				rrr(a, b);
		}
		get_in_pos(a, b, nearest_element(a, b));
		pop(b, a);
		write(1, "pa\n", 3);
	}
}

int	main(int ac, char **av)
{
	t_array	a;
	t_array	b;
	t_array	lis;

	if (ac == 2 && (!av[1][0] || !is_num(av[1])))
		return (write(2, "Error\n", 6), 1);
	if (ac <= 2)
		return (0);
	lis = (t_array){0, NULL, NULL, NULL};
	a = (t_array){ac - 1, malloc(ac * sizeof(long)), NULL, NULL};
	if (!parse_input(&a, ac - 1, av + 1))
		return (write(2, "Error\n", 6), free(a.arr), 1);
	if (is_sorted(a))
		return (free(a.arr), 1);
	b = (t_array){0, malloc(ac * sizeof(long)),
		malloc(ac * sizeof(long)), malloc(ac * sizeof(long))};
	if (ac < 7)
		return (small_data_set(a, b, lis, ac), free(a.arr),
			free(b.arr), free(b.indexes), free(b.paired), 1);
	lis = lis_stage2(a);
	pop_non_lis_elements(&a, &b, lis);
	pop_b_in_order(&a, &b);
	smallest_on_top(&a);
	return (free(a.arr), free(b.arr),
		free(b.indexes), free(b.paired), free(lis.arr), 0);
}
