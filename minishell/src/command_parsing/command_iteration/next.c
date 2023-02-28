/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:41:23 by aronez            #+#    #+#             */
/*   Updated: 2022/12/09 10:41:23 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../command_iteration.h"

#include <libft.h>

static int	is_control_quote(
		const char *command_string,
		const t_command_iterator *command_iterator,
		char c
		)
{
	if (command_iterator->quote_mode == c)
		return (1);
	if (command_iterator->quote_mode == 0
		&& ((c == '\'' && ft_strchr(command_string
					+ (command_iterator->idx + 1), '\'') != NULL) || (c == '\"'
				&& ft_strchr(command_string + (command_iterator->idx + 1), '\"')
				!= NULL))
	)
		return (1);
	return (0);
}

t_command_char	peek(
		const t_command_iterator *command_iterator,
		const char *command_string
		)
{
	t_command_char	command_char;

	if (command_string[command_iterator->idx] == '\0')
		return ((t_command_char){'\0', command_iterator->quote_mode, 0});
	command_char.c = command_string[command_iterator->idx];
	command_char.is_control_quote = is_control_quote(
			command_string,
			command_iterator,
			command_string[command_iterator->idx]
			);
	if (command_char.is_control_quote)
	{
		if (command_iterator->quote_mode != 0)
			command_char.current_quote_mode = 0;
		else
			command_char.current_quote_mode = command_char.c;
	}
	else
		command_char.current_quote_mode = command_iterator->quote_mode;
	return (command_char);
}

t_command_char	next_command_char(
		t_command_iterator *command_iterator,
		const char *command_string
		)
{
	t_command_char	command_char;

	command_char = peek(command_iterator, command_string);
	if (command_char.c == '\0')
		return (command_char);
	command_iterator->quote_mode = command_char.current_quote_mode;
	command_iterator->idx++;
	return (command_char);
}
