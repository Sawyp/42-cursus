/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sections_index.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:02:26 by aronez            #+#    #+#             */
/*   Updated: 2022/12/17 14:02:26 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_SECTIONS_INDEX_H
# define COMMAND_SECTIONS_INDEX_H

# include <stddef.h>

typedef struct s_command_sections_index
{
	size_t	d_idx;
	size_t	c_idx;
}	t_command_sections_index;

t_command_sections_index	increment_index(
								const t_command_line_section_list *sections,
								t_command_sections_index idx
								);
t_command_sections_index	skip_spaces(
								const t_command_line_section_list *sections,
								t_command_sections_index idx
								);

#endif //COMMAND_SECTIONS_INDEX_H
