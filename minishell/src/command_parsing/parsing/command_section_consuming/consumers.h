/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consumers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:19:09 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 10:19:09 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSUMERS_H
# define CONSUMERS_H

# include "../../../variable_registry.h"
# include "../../command_line_sections.h"
# include "../command_sections_index.h"
# include "../parsed_command_allocator.h"

typedef struct s_resolution_data
{
	int							previous_return_code;
	const t_variable_registry	*variable_registry;
}	t_resolution_data;

int	skip(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		);
int	add_command_part(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		);
int	add_here_document(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		);
int	add_input_file(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		);
int	add_appended_file(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		);
int	add_truncated_file(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		);

#endif //CONSUMERS_H
