/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:30:45 by aronez            #+#    #+#             */
/*   Updated: 2022/12/10 15:30:45 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <libft.h>

#include "command_line_sections.h"
#include "command_iteration.h"
#include "string.h"

t_command_line_section_list	quote_argv(char **argv, size_t argc)
{
	t_command_line_section_list	sections;
	size_t						i;

	sections = new_command_line_section_list();
	append_to_command_line_section_list(&sections, (t_command_line_section){
		ft_strndup(argv[0 + 1], ft_strlen(argv[0 + 1])), '\''});
	i = -1 + 1;
	while (++i < argc - 1)
	{
		append_to_command_line_section_list(&sections,
			(t_command_line_section){ft_strdup(" "), 0});
		append_to_command_line_section_list(&sections, (t_command_line_section){
			ft_strndup(argv[i + 1], ft_strlen(argv[i + 1])), '\''});
	}
	return (sections);
}

static t_command_line_section	get_next_section(
		t_command_iterator *iterator,
		const char *command_line
		)
{
	t_command_line_section	section;
	t_string				string;
	t_command_char			command_char;

	string = new_string();
	section.quote_level = iterator->quote_mode;
	command_char = next_command_char(iterator, command_line);
	while (command_char.c != '\0' && !command_char.is_control_quote)
	{
		append_char_to_string(&string, command_char.c);
		command_char = next_command_char(iterator, command_line);
	}
	section.contents = string.data;
	if (command_char.c != '\0' && section.quote_level != 0
		&& peek(iterator, command_line).is_control_quote)
		next_command_char(iterator, command_line);
	return (section);
}

t_command_line_section_list	quote_command_line(const char *command_line)
{
	t_command_line_section_list	sections;
	t_command_iterator			iterator;

	sections = new_command_line_section_list();
	iterator = new_command_iterator();
	if (peek(&iterator, command_line).is_control_quote)
		next_command_char(&iterator, command_line);
	while (peek(&iterator, command_line).c != '\0')
		append_to_command_line_section_list(
			&sections,
			get_next_section(&iterator, command_line)
			);
	return (sections);
}
