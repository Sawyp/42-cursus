/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:16:15 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 10:16:15 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../../command_line_sections.h"

#include "../command_section_consuming.h"

#include "consumers.h"

static char	*skip_digits(char *string)
{
	int	atoi_status;
	int	fd;

	atoi_status = ft_s_atoi(string, &fd);
	if (atoi_status == -3)
		return (string);
	while (ft_isdigit(*string))
		string++;
	return (string);
}

static char	*skip_out_specifier(char *string)
{
	if (*string == '&')
		return (string + 1);
	return (skip_digits(string));
}

t_command_part_consumer	make_next_consumer(
		const t_command_line_section_list *command_sections,
		t_command_sections_index idx,
		int previous_return_code,
		const t_variable_registry *variable_registry
		)
{
	char	*content;

	idx = skip_spaces(command_sections, idx);
	if (idx.d_idx >= command_sections->length)
		return ((t_command_part_consumer){&skip, (t_resolution_data){
			previous_return_code, variable_registry}});
	if (command_sections->data[idx.d_idx].quote_level != 0)
		return ((t_command_part_consumer){&add_command_part,
			(t_resolution_data){previous_return_code, variable_registry}});
	content = command_sections->data[idx.d_idx].contents + idx.c_idx;
	if (ft_strncmp(skip_digits(content), "<<", 2) == 0)
		return ((t_command_part_consumer){&add_here_document,
			(t_resolution_data){previous_return_code, variable_registry}});
	if (ft_strncmp(skip_digits(content), "<", 1) == 0)
		return ((t_command_part_consumer){&add_input_file,
			(t_resolution_data){previous_return_code, variable_registry}});
	if (ft_strncmp(skip_out_specifier(content), ">>", 2) == 0)
		return ((t_command_part_consumer){&add_appended_file,
			(t_resolution_data){previous_return_code, variable_registry}});
	if (ft_strncmp(skip_out_specifier(content), ">", 1) == 0)
		return ((t_command_part_consumer){&add_truncated_file,
			(t_resolution_data){previous_return_code, variable_registry}});
	return ((t_command_part_consumer){&add_command_part, (t_resolution_data){
		previous_return_code, variable_registry}});
}
