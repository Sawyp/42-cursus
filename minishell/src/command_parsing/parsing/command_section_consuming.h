/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_section_consuming.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:03:38 by aronez            #+#    #+#             */
/*   Updated: 2022/12/17 14:03:38 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_SECTION_CONSUMING_H
# define COMMAND_SECTION_CONSUMING_H

# include "../../parsed_command.h"
# include "../../variable_registry.h"

# include "../command_line_sections.h"
# include "command_sections_index.h"
# include "parsed_command_allocator.h"
# include "command_section_consuming/consumers.h"

typedef struct s_command_part_consumer
{
	int					(*consume)(
			const t_command_line_section_list *,
			t_command_sections_index *,
			t_parsed_command_allocator *,
			t_resolution_data);
	t_resolution_data	data;
}	t_command_part_consumer;

t_command_part_consumer	make_next_consumer(
							const t_command_line_section_list *command_sections,
							t_command_sections_index idx,
							int previous_return_code,
							const t_variable_registry *variable_registry
							);

#endif //COMMAND_SECTION_CONSUMING_H
