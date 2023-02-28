/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:32:28 by aronez            #+#    #+#             */
/*   Updated: 2022/12/11 14:32:28 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../parsed_command.h"

t_parsed_commands	new_parsed_command_list(void)
{
	return ((t_parsed_commands){
		.size = 0,
		.capacity = 10,
		.data = malloc(sizeof(t_parsed_command) * 10)
	});
}

static void	free_file_list(t_file_list file_list)
{
	size_t	i;

	i = -1;
	while (++i < file_list.size)
		free(file_list.data[i].id);
	free(file_list.data);
}

static void	free_string_list(t_string_list string_list)
{
	size_t	i;

	i = -1;
	while (++i < string_list.size)
		free(string_list.strings[i]);
	free(string_list.strings);
}

void	free_parsed_command_list(t_parsed_commands *list)
{
	size_t	i;

	i = -1;
	while (++i < list->size)
	{
		free(list->data[i].command_name);
		free_string_list(list->data[i].command_args);
		free_file_list(list->data[i].files);
	}
	free(list->data);
}
