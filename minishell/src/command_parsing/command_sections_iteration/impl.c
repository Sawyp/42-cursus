/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:24:28 by aronez            #+#    #+#             */
/*   Updated: 2022/12/12 16:24:28 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_line_sections.h"
#include "../command_sections_iteration.h"

#include "exploration.h"

void	iterate_to_next_pipe(
			t_commands_iterator *iterator,
			t_command_line_section_list sections)
{
	int	quote_found;
	int	unquoted_section_found;

	if (iterator->section_idx == sections.length)
		return ;
	quote_found = aggregate_unquoted_section(sections, iterator);
	while (!quote_found)
	{
		unquoted_section_found = aggregate_until_unquoted_section(sections,
				iterator);
		if (!unquoted_section_found)
			return ;
		quote_found = aggregate_unquoted_section(sections, iterator);
	}
}
