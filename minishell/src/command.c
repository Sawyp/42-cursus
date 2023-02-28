/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:29:04 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 12:29:04 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <unistd.h>

#include "command.h"

void	no_op(void *data)
{
	(void)data;
}

t_command_list	new_command_list(size_t size)
{
	t_command_list	commands;
	size_t			i;

	commands = (t_command_list){
		.size = size,
		.data = malloc(sizeof(t_command) * size)
	};
	i = -1;
	while (++i < commands.size)
		commands.data[i] = (t_command){.delete_data = &no_op};
	return (commands);
}

void	free_command_list(t_command_list *commands)
{
	size_t	i;

	i = -1;
	while (++i < commands->size)
		commands->data[i].delete_data(commands->data[i].f_data);
	free(commands->data);
}
