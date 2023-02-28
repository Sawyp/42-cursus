/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_part_adding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:23:13 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 10:23:13 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../command_line_sections.h"
#include "../../../string.h"
#include "../../command_section_consuming.h"
#include "../../command_sections_index.h"
#include "../../parsed_command_allocator.h"
#include "../consumers.h"

#include "command_strings_concatenation.h"

int	add_command_part(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		)
{
	t_string	command_part;

	*idx = skip_spaces(command_sections, *idx);
	if (idx->d_idx < command_sections->length)
	{
		command_part = concatenate_until_command_control_char(command_sections,
				idx, resolution_data);
		if (command_part.data == NULL)
			return (0);
		if (command_allocator->parsed_command->command_name == NULL)
			command_allocator->parsed_command->command_name = command_part.data;
		else
			append_command_arg(command_allocator, command_part.data);
	}
	return (0);
}
