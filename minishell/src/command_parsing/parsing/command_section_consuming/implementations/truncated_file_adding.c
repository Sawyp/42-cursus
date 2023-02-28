/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncated_file_adding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:19:44 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 20:19:44 by aronez           ###   ########.fr       */
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

static int	set_fds(char *content, int fds[2])
{
	fds[1] = -1;
	if (*content == '>')
		fds[0] = 1;
	else if (*content == '&')
	{
		fds[0] = 1;
		fds[1] = 2;
	}
	else
	{
		if (ft_s_atoi(content, &fds[0]) < 0)
			return (-1);
	}
	return (0);
}

int	add_truncated_file(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_parsed_command_allocator *command_allocator,
		t_resolution_data resolution_data
		)
{
	char		*content;
	int			fds[2];
	t_string	file_name;

	*idx = skip_spaces(command_sections, *idx);
	content = command_sections->data[idx->d_idx].contents + idx->c_idx;
	if (set_fds(content, fds) < 0)
		return (ft_fdprintf(2, "Parsing error : file descriptor too large\n"),
			-1);
	idx->c_idx += (ft_strchr(content, '>') - content) + 1;
	*idx = skip_spaces(command_sections, *idx);
	if (idx->d_idx >= command_sections->length)
		return (ft_fdprintf(2, "Parsing error : file name missing\n"), -1);
	file_name = concatenate_until_command_control_char(command_sections, idx,
			resolution_data);
	if (file_name.data == NULL)
		return (ft_fdprintf(2, "Parsing error : file name missing\n"), -1);
	append_file(command_allocator, (t_file){TRUNCATE, fds[0], file_name.data});
	if (fds[1] >= 0)
		append_file(command_allocator, (t_file){TRUNCATE, fds[1],
			ft_strdup(file_name.data)});
	return (0);
}
