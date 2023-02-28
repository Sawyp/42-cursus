/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appends.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:30:56 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 20:30:56 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../../parsed_command.h"

#include "../parsed_command_allocator.h"

void	append_command_arg(
		t_parsed_command_allocator *allocator,
		char *argument
		)
{
	if (allocator->parsed_command->command_args.size
		== allocator->command_args_capacity)
	{
		allocator->parsed_command->command_args.strings = ft_realloc(
				allocator->parsed_command->command_args.strings,
				sizeof(char *) * allocator->command_args_capacity,
				sizeof(char *) * allocator->command_args_capacity + 5
				);
	}
	allocator->parsed_command->command_args.strings[
		allocator->parsed_command->command_args.size] = argument;
	allocator->parsed_command->command_args.size++;
}

void	append_file(t_parsed_command_allocator *allocator, t_file file)
{
	if (allocator->parsed_command->files.size
		== allocator->files_capacity)
	{
		allocator->parsed_command->files.data = ft_realloc(
				allocator->parsed_command->files.data,
				sizeof(t_file) * allocator->files_capacity,
				sizeof(t_file) * allocator->files_capacity + 5
				);
	}
	allocator->parsed_command->files.data[
		allocator->parsed_command->files.size] = file;
	allocator->parsed_command->files.size++;
}
