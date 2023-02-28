/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sections_index.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:12:00 by aronez            #+#    #+#             */
/*   Updated: 2022/12/19 14:12:00 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../command_line_sections.h"

#include "command_sections_index.h"

t_command_sections_index	increment_index(
		const t_command_line_section_list *command_sections,
		t_command_sections_index idx
		)
{
	idx.c_idx++;
	if (command_sections->data[idx.d_idx].contents[idx.c_idx] == '\0')
	{
		idx.c_idx = 0;
		idx.d_idx++;
	}
	return (idx);
}

t_command_sections_index	skip_spaces(
		const t_command_line_section_list *command_sections,
		t_command_sections_index idx
)
{
	if (idx.d_idx < command_sections->length
		&& command_sections->data[idx.d_idx].quote_level == 0
		&& command_sections->data[idx.d_idx].contents[idx.c_idx] == '\0')
	{
		idx.c_idx = 0;
		idx.d_idx++;
	}
	while (idx.d_idx < command_sections->length
		&& command_sections->data[idx.d_idx].quote_level == 0
		&& ft_isspace(command_sections->data[idx.d_idx].contents[idx.c_idx]))
		idx = increment_index(command_sections, idx);
	return (idx);
}
