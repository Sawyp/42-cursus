/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sections_iterator.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:43:26 by aronez            #+#    #+#             */
/*   Updated: 2022/12/12 13:43:26 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_SECTIONS_ITERATION_H
# define COMMAND_SECTIONS_ITERATION_H

# include <stddef.h>

# include "command_line_sections.h"

typedef struct s_commands_iterator
{
	size_t						section_idx;
	char						*delim;
	t_command_line_section_list	next_command_sections;
}	t_commands_iterator;

t_commands_iterator			new_commands_iterator(
								t_command_line_section_list sections
								);
void						free_commands_iterator(
								t_commands_iterator *iterator
								);

t_command_line_section_list	next_command_sections(
								t_commands_iterator *iterator,
								t_command_line_section_list sections
								);
void						free_command_sections(
								t_command_line_section_list command_sections
								);

#endif //COMMAND_SECTIONS_ITERATION_H
