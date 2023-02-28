/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:15:56 by aronez            #+#    #+#             */
/*   Updated: 2022/12/12 14:15:56 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_line_sections.h"
#include "../command_sections_iteration.h"

#include "impl.h"

t_command_line_section_list	next_command_sections(
		t_commands_iterator *iterator,
		t_command_line_section_list sections
		)
{
	t_command_line_section_list	current_command_sections;

	current_command_sections = iterator->next_command_sections;
	iterator->next_command_sections = new_command_line_section_list();
	iterate_to_next_pipe(iterator, sections);
	return (current_command_sections);
}
