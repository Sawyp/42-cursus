/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:25:20 by lsanglas          #+#    #+#             */
/*   Updated: 2022/10/22 13:25:33 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_element(t_array arr)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (++i < arr.size)
	{
		if (arr.arr[i] < arr.arr[tmp])
			tmp = i;
	}
	return (tmp);
}

void	smallest_on_top(t_array *a)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (++i < a->size)
	{
		if (a->arr[tmp] > a->arr[i])
			tmp = i;
	}
	i = -1;
	while (++i < dist(tmp, a))
	{
		if (dist(tmp, a) == tmp)
			instruction_and_print(a, &rotate, "ra\n");
		else
			instruction_and_print(a, &rrotate, "rra\n");
	}
}

long	is_in_till(t_array arr, long x, int i)
{
	arr.size = i;
	return (is_in(arr, x));
}

int	parse_input(t_array *a, int ac, char **av)
{
	int		i;

	i = -1;
	while (++i < ac)
	{
		if (!*av[1] || !is_num(av[i]) || ft_strlen(av[i]) > 11)
			return (0);
		a->arr[i] = ft_atol(av[i]);
		if (is_in_till(*a, a->arr[i], i) || a->arr[i] > 2147483647
			|| a->arr[i] < -2147483648)
			return (0);
	}
	return (1);
}

void	instruction_and_print(t_array *arr, void (*f)(t_array *), char *str)
{
	f(arr);
	write(1, str, ft_strlen(str));
}
