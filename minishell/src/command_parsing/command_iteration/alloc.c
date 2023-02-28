/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:39:50 by aronez            #+#    #+#             */
/*   Updated: 2022/12/09 10:39:50 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_iteration.h"

t_command_iterator	new_command_iterator(void)
{
	t_command_iterator	command_iterator;

	command_iterator.idx = 0;
	command_iterator.quote_mode = 0;
	return (command_iterator);
}
