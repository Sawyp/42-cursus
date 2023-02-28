/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:46:10 by aronez            #+#    #+#             */
/*   Updated: 2022/12/12 13:46:10 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "../command_sections_iteration.h"

#include "exploration.h"
#include "impl.h"

t_commands_iterator	new_commands_iterator(t_command_line_section_list sections)
{
	t_commands_iterator	iterator;
	int					found_unquoted_section;

	iterator = (t_commands_iterator){0, NULL, new_command_line_section_list()};
	found_unquoted_section = aggregate_until_unquoted_section(sections,
			&iterator);
	if (!found_unquoted_section)
		return (iterator);
	iterate_to_next_pipe(&iterator, sections);
	return (iterator);
}

void	free_commands_iterator(t_commands_iterator *iterator)
{
	if (iterator->next_command_sections.length > 0
		&& iterator->next_command_sections.data[
			iterator->next_command_sections.length - 1
		].quote_level == 0)
		free(iterator->next_command_sections.data[
			iterator->next_command_sections.length - 1
		].contents);
	free_command_sections(iterator->next_command_sections);
}
