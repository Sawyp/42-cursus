/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:20:27 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 16:20:27 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../../../../command_line_sections.h"
#include "../../../../string.h"
#include "../../../command_sections_index.h"
#include "../../consumers.h"

#include "../command_strings_concatenation.h"

#include "variable_resolution.h"

static void	add_quoted_sections(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_string *command_part,
		t_resolution_data resolution_data
)
{
	char	*resolved_string;

	while (idx->d_idx < command_sections->length
		&& command_sections->data[idx->d_idx].quote_level != 0)
	{
		if (command_sections->data[idx->d_idx].quote_level == '\'')
			append_str_to_string(command_part,
				command_sections->data[idx->d_idx].contents);
		else
		{
			resolved_string = resolve_section(command_sections->data[idx->d_idx]
					.contents, resolution_data, 1);
			append_str_to_string(command_part, resolved_string);
			free(resolved_string);
		}
		idx->d_idx++;
	}
}

static void	add_unquoted_sections(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_string *command_part,
		t_resolution_data resolution_data
)
{
	t_string	unresolved_string;
	char		*resolved_string;

	if (idx->d_idx < command_sections->length
		&& command_sections->data[idx->d_idx].contents[idx->c_idx] == '\0')
	{
		*idx = (t_command_sections_index){idx->d_idx + 1, 0};
		return ;
	}
	unresolved_string = new_string();
	while (idx->d_idx < command_sections->length
		&& command_sections->data[idx->d_idx].quote_level == 0
		&& !is_command_control_char(command_sections->data[idx->d_idx]
			.contents[idx->c_idx]))
	{
		append_char_to_string(&unresolved_string,
			command_sections->data[idx->d_idx].contents[idx->c_idx]);
		*idx = increment_index(command_sections, *idx);
	}
	resolved_string = resolve_section(unresolved_string.data,
			resolution_data, idx->d_idx == command_sections->length
			|| command_sections->data[idx->d_idx].quote_level == 0);
	append_str_to_string(command_part, resolved_string);
	free(resolved_string);
	free_string(&unresolved_string);
}

static int	is_empty_string_ok(
		t_command_sections_index a,
		t_command_sections_index b,
		const t_command_line_section_list *command_sections
		)
{
	size_t	c_count;
	int		has_quoted_section;

	c_count = 0;
	has_quoted_section = 0;
	while (a.d_idx < b.d_idx)
	{
		has_quoted_section |= command_sections->data[a.d_idx].quote_level;
		c_count += ft_strlen(command_sections->data[a.d_idx].contents);
		a.d_idx++;
	}
	if (a.d_idx < command_sections->length)
	{
		has_quoted_section |= command_sections->data[a.d_idx].quote_level;
		c_count += b.c_idx;
	}
	return (c_count == 0 || has_quoted_section);
}

t_string	concatenate_until_command_control_char(
		const t_command_line_section_list *command_sections,
		t_command_sections_index *idx,
		t_resolution_data resolution_data
		)
{
	t_string					command_part;
	t_command_sections_index	old_idx;

	while (1)
	{
		old_idx = *idx;
		command_part = new_string();
		while (idx->d_idx < command_sections->length && (command_sections->data[
					idx->d_idx].quote_level != 0 || !is_command_control_char(
					command_sections->data[idx->d_idx].contents[idx->c_idx])))
		{
			add_quoted_sections(command_sections, idx, &command_part,
				resolution_data);
			add_unquoted_sections(command_sections, idx, &command_part,
				resolution_data);
		}
		if (is_empty_string_ok(old_idx, *idx, command_sections)
			|| string_len(&command_part) != 0)
			return (command_part);
		free_string(&command_part);
		if (idx->d_idx == command_sections->length
			|| command_sections->data[idx->d_idx].contents[idx->c_idx] != ' ')
			return ((t_string){.data = NULL});
		*idx = skip_spaces(command_sections, *idx);
	}
}
