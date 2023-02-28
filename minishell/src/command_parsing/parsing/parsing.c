/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:19:44 by aronez            #+#    #+#             */
/*   Updated: 2022/12/17 13:19:44 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsed_command.h"
#include "../../variable_registry.h"

#include "../command_line_sections.h"

#include "command_sections_index.h"
#include "command_section_consuming.h"
#include "parsed_command_allocator.h"

int	parse_command(
		const t_command_line_section_list *command_sections,
		int previous_return_code,
		const t_variable_registry *variable_registry,
		t_parsed_command *parsed_command
		)
{
	t_command_sections_index	idx;
	t_command_part_consumer		consumer;
	t_parsed_command_allocator	parsed_command_allocator;
	int							consume_status;

	parsed_command_allocator = new_parsed_command_allocator(parsed_command);
	idx = (t_command_sections_index){0, 0};
	while (idx.d_idx < command_sections->length)
	{
		consumer = make_next_consumer(command_sections, idx,
				previous_return_code, variable_registry);
		consume_status = consumer.consume(command_sections, &idx,
				&parsed_command_allocator, consumer.data);
		if (consume_status < 0)
			return (free_allocated_memory(&parsed_command_allocator), -1);
	}
	return (0);
}
