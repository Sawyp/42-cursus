/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoted_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 10:12:05 by aronez            #+#    #+#             */
/*   Updated: 2022/12/11 10:12:05 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsed_command.h"
#include "../variable_registry.h"

#include "command_line_sections.h"
#include "command_sections_iteration.h"
#include "parsing.h"

int	parse_quoted_command_line(
		t_command_line_section_list section_list,
		int previous_return_code,
		const t_variable_registry *variable_registry,
		t_parsed_commands *parsed_commands
		)
{
	t_commands_iterator			commands_iterator;
	t_command_line_section_list	command_sections;
	t_parsed_command			parsed_command;

	*parsed_commands = new_parsed_command_list();
	if (section_list.length == 0)
		return (0);
	commands_iterator = new_commands_iterator(section_list);
	command_sections = next_command_sections(&commands_iterator, section_list);
	while (command_sections.length != 0)
	{
		if (parse_command(&command_sections, previous_return_code,
				variable_registry, &parsed_command) < 0)
			return (free_command_sections(command_sections),
				free_commands_iterator(&commands_iterator),
				free_parsed_command_list(parsed_commands), -1);
		append_to_parsed_command_list(parsed_commands, parsed_command);
		free_command_sections(command_sections);
		command_sections = next_command_sections(&commands_iterator,
				section_list);
	}
	free_command_sections(command_sections);
	return (free_commands_iterator(&commands_iterator), 0);
}
