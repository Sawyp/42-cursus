/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:07:21 by aronez            #+#    #+#             */
/*   Updated: 2022/12/21 10:07:21 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <libft.h>

#include "../../../../../variable_registry.h"
#include "../../../../string.h"
#include "../../consumers.h"

static const char	*get_env_variable(
		const char *section,
		size_t *idx,
		const t_variable_registry *variable_registry
		)
{
	size_t		variable_name_len;
	char		*variable_name;
	const char	*variable;

	variable_name_len = 0;
	if (ft_isdigit(section[*idx + variable_name_len]))
		variable_name_len++;
	else
	{
		while (ft_isalnum(section[*idx + variable_name_len])
			|| section[*idx + variable_name_len] == '_')
			variable_name_len++;
	}
	if (variable_name_len == 0)
		return ("$");
	variable_name = ft_strndup(section + *idx, variable_name_len);
	*idx += variable_name_len;
	variable = try_get_variable(variable_registry, variable_name);
	return (free(variable_name), variable);
}

static void	resolve_variable(
		const char *section,
		size_t *idx,
		t_resolution_data resolution_data,
		t_string *resolved_section
		)
{
	char		*itoa_result;
	const char	*variable_string;

	if (section[*idx] == '?')
	{
		itoa_result = ft_itoa(resolution_data.previous_return_code);
		*idx += 1;
		append_str_to_string(resolved_section, itoa_result);
		free(itoa_result);
	}
	else
	{
		variable_string = get_env_variable(section, idx,
				resolution_data.variable_registry);
		if (variable_string != NULL)
			append_str_to_string(resolved_section, variable_string);
	}
}

static void	append_section_to_dollar(
		const char *section,
		size_t *idx,
		t_string *resolved_section
		)
{
	const char	*section_start;
	const char	*dollar;
	size_t		dollar_offset;

	section_start = section + *idx;
	dollar = ft_strchr(section_start, '$');
	if (dollar == NULL)
		dollar = ft_strchr(section_start, '\0');
	dollar_offset = dollar - section_start;
	*idx += dollar_offset;
	append_strn_to_string(resolved_section, section_start, dollar_offset);
}

char	*resolve_section(
		const char *section,
		t_resolution_data resolution_data,
		int display_last_dollar
		)
{
	t_string	resolved_section;
	size_t		i;

	resolved_section = new_string();
	i = 0;
	append_section_to_dollar(section, &i, &resolved_section);
	while (section[i] != '\0')
	{
		while (section[i] == '$')
		{
			i++;
			if (section[i] != '\0')
				resolve_variable(section, &i, resolution_data,
					&resolved_section);
			else if (display_last_dollar)
				append_char_to_string(&resolved_section, '$');
		}
		append_section_to_dollar(section, &i, &resolved_section);
	}
	return (resolved_section.data);
}
