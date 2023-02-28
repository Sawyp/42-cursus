/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:40:20 by aronez            #+#    #+#             */
/*   Updated: 2022/12/10 17:40:20 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../command_line_sections.h"

t_command_line_section	clone_command_line_section(
							t_command_line_section section
							)
{
	return ((t_command_line_section){
		.contents = ft_strdup(section.contents),
		.quote_level = section.quote_level
	});
}

t_command_line_section_list	new_command_line_section_list(void)
{
	return ((t_command_line_section_list){
		.capacity = 10,
		.length = 0,
		.data = malloc(sizeof(t_command_line_section) * 10)
	});
}

void	free_command_line_section_list(t_command_line_section_list *sections)
{
	size_t	i;

	i = -1;
	while (++i < sections->length)
		free(sections->data[i].contents);
	free(sections->data);
	sections->capacity = 0;
	sections->length = 0;
}
