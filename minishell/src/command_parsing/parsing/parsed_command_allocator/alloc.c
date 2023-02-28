/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:22:27 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 20:22:27 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "../../../parsed_command.h"

#include "../parsed_command_allocator.h"

t_parsed_command_allocator	new_parsed_command_allocator(
		t_parsed_command *parsed_command
		)
{
	parsed_command->command_name = NULL;
	parsed_command->command_args = (t_string_list){
		.size = 0,
		.strings = malloc(sizeof(char *) * 5)
	};
	parsed_command->files = (t_file_list){
		.size = 0,
		.data = malloc(sizeof(t_file) * 5)
	};
	return ((t_parsed_command_allocator){
		.parsed_command = parsed_command,
		.command_args_capacity = 5,
		.files_capacity = 5
	});
}

void	free_allocated_memory(t_parsed_command_allocator *allocator)
{
	size_t	i;

	free(allocator->parsed_command->command_name);
	i = -1;
	while (++i < allocator->parsed_command->command_args.size)
		free(allocator->parsed_command->command_args.strings[i]);
	free(allocator->parsed_command->command_args.strings);
	i = -1;
	while (++i < allocator->parsed_command->files.size)
		free(allocator->parsed_command->files.data[i].id);
	free(allocator->parsed_command->files.data);
}
