/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:41:09 by lsanglas          #+#    #+#             */
/*   Updated: 2022/10/22 11:41:10 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_array
{
	long	size;
	long	*arr;
	long	*indexes;
	long	*paired;
}	t_array;

t_array	lis_stage2(t_array arr);
t_array	lis_finder(t_array arr);

long	ft_atol(char *str);
long	is_in(t_array arr, long x);
int		is_num(char *str);
int		ft_strlen(char *str);

int		is_sorted(t_array arr);
long	min(long x, long y);
long	ft_abs(long x);
long	max(long x, long y);
long	dist(long x, t_array *arr);

int		parse_input(t_array *a, int ac, char **av);
int		smallest_element(t_array arr);
void	smallest_on_top(t_array *a);
void	instruction_and_print(t_array *arr, void (*f)(t_array *), char *str);

void	small_data_set(t_array a, t_array b, t_array lis, int ac);
void	pop_b_in_order(t_array *a, t_array *b);

void	rotate(t_array *arr);
void	rrotate(t_array *arr);
void	pop(t_array *arr1, t_array *arr2);
void	rr(t_array *a, t_array *b);
void	rrr(t_array *a, t_array *b);

#endif //PUSH_SWAP_H
