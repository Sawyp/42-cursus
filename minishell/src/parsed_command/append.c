/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:49:11 by aronez            #+#    #+#             */
/*   Updated: 2022/12/11 14:49:11 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../parsed_command.h"

void	append_to_parsed_command_list(
		t_parsed_commands *parsed_commands,
		t_parsed_command command
			)
{
	if (parsed_commands->size == parsed_commands->capacity)
	{
		parsed_commands->data = ft_realloc(
				parsed_commands->data,
				sizeof(t_parsed_command) * parsed_commands->size,
				sizeof(t_parsed_command) * 10
				);
		parsed_commands->capacity += 10;
	}
	parsed_commands->data[parsed_commands->size] = command;
	parsed_commands->size++;
}
