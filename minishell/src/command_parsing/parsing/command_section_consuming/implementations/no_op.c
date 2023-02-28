/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:20:56 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 10:20:56 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../command_line_sections.h"
#include "../../command_section_consuming.h"
#include "../../command_sections_index.h"
#include "../../parsed_command_allocator.h"
#include "../consumers.h"

int	skip(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
)
{
	*idx = skip_spaces(command_sections, *idx);
	(void)command_allocator;
	(void)resolution_data;
	return (0);
}
