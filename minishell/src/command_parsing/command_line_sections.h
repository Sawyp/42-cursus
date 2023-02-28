/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_sections.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:35:47 by aronez            #+#    #+#             */
/*   Updated: 2022/12/10 17:35:47 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LINE_SECTIONS_H
# define COMMAND_LINE_SECTIONS_H

# include <stddef.h>

typedef struct s_command_line_section
{
	char	*contents;
	char	quote_level;
}	t_command_line_section;

typedef struct s_command_line_section_list
{
	size_t					length;
	size_t					capacity;
	t_command_line_section	*data;
}	t_command_line_section_list;

t_command_line_section		clone_command_line_section(
								t_command_line_section section
								);

t_command_line_section_list	new_command_line_section_list(void);
void						free_command_line_section_list(
								t_command_line_section_list *section_list
								);
void						append_to_command_line_section_list(
								t_command_line_section_list *section_list,
								t_command_line_section section
								);

#endif //COMMAND_LINE_SECTIONS_H
