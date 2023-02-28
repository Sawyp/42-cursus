/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:44:47 by aronez            #+#    #+#             */
/*   Updated: 2022/12/10 17:44:47 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../command_line_sections.h"

void	append_to_command_line_section_list(
		t_command_line_section_list *section_list,
		t_command_line_section section
		)
{
	if (section_list->length == section_list->capacity)
	{
		section_list->data = ft_realloc(
				section_list->data,
				sizeof(t_command_line_section) * section_list->length,
				sizeof(t_command_line_section) * 10
				);
		section_list->capacity += 10;
	}
	section_list->data[section_list->length] = section;
	section_list->length++;
}
