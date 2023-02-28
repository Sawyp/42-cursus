/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_command_allocator.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:47:32 by aronez            #+#    #+#             */
/*   Updated: 2022/12/17 13:47:32 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSED_COMMAND_ALLOCATOR_H
# define PARSED_COMMAND_ALLOCATOR_H

# include <stddef.h>

# include "../../parsed_command.h"

typedef struct s_parsed_command_allocator
{
	t_parsed_command	*parsed_command;
	size_t				command_args_capacity;
	size_t				files_capacity;
}	t_parsed_command_allocator;

t_parsed_command_allocator	new_parsed_command_allocator(
								t_parsed_command *parsed_command
								);
void						free_allocated_memory(
								t_parsed_command_allocator *allocator
								);

void						append_command_arg(
								t_parsed_command_allocator *allocator,
								char *argument
								);
void						append_file(
								t_parsed_command_allocator *allocator,
								t_file file
								);

#endif //PARSED_COMMAND_ALLOCATOR_H
