/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:13:05 by aronez            #+#    #+#             */
/*   Updated: 2022/12/12 14:13:05 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../command_line_sections.h"
#include "../../command_sections_iteration.h"

int	aggregate_until_unquoted_section(
		t_command_line_section_list sections,
		t_commands_iterator *iterator
		)
{
	while (iterator->section_idx < sections.length
		&& sections.data[iterator->section_idx].quote_level != 0)
	{
		append_to_command_line_section_list(&iterator->next_command_sections,
			sections.data[iterator->section_idx]);
		iterator->section_idx++;
	}
	if (iterator->section_idx == sections.length)
		return (0);
	iterator->delim = sections.data[iterator->section_idx].contents;
	return (1);
}

int	aggregate_unquoted_section(
		t_command_line_section_list sections,
		t_commands_iterator *iterator
		)
{
	t_command_line_section	new_section;
	char					*delim;

	new_section.quote_level = 0;
	delim = ft_strchr(iterator->delim, '|');
	if (delim != NULL)
	{
		new_section.contents = ft_strndup(iterator->delim,
				(size_t)(delim - iterator->delim));
		append_to_command_line_section_list(&iterator->next_command_sections,
			new_section);
		iterator->delim = delim + 1;
		return (1);
	}
	if (++iterator->section_idx == sections.length)
	{
		new_section.contents = ft_strdup(iterator->delim);
		append_to_command_line_section_list(&iterator->next_command_sections,
			new_section);
		return (1);
	}
	new_section.contents = iterator->delim;
	append_to_command_line_section_list(&iterator->next_command_sections,
		new_section);
	return (0);
}
