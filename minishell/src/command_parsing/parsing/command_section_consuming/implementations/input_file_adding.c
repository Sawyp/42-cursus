/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file_adding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:25:03 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 17:25:03 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../../command_line_sections.h"
#include "../../../string.h"
#include "../../command_section_consuming.h"
#include "../../command_sections_index.h"
#include "../../parsed_command_allocator.h"
#include "../consumers.h"

#include "command_strings_concatenation.h"

int	add_input_file(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		)
{
	t_string	file_name;
	char		*content;
	int			fd;

	*idx = skip_spaces(command_sections, *idx);
	content = command_sections->data[idx->d_idx].contents + idx->c_idx;
	fd = 0;
	if (content[0] != '<' && ft_s_atoi(content, &fd) < 0)
		return (ft_fdprintf(2, "Parsing error : file descriptor too large\n"),
			-1);
	idx->c_idx += (ft_strchr(content, '<') - content) + 1;
	*idx = skip_spaces(command_sections, *idx);
	if (idx->d_idx >= command_sections->length)
		return (ft_fdprintf(2, "Parsing error : file name missing\n"), -1);
	file_name = concatenate_until_command_control_char(command_sections,
			idx, resolution_data);
	if (file_name.data == NULL)
		return (ft_fdprintf(2, "Parsing error : file name missing\n"), -1);
	append_file(command_allocator, (t_file){
		.mode = READ_ONLY,
		.fd = fd,
		.id = file_name.data
	});
	return (0);
}
