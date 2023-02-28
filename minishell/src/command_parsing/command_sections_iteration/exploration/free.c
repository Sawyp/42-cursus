/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:11:13 by aronez            #+#    #+#             */
/*   Updated: 2022/12/12 14:11:13 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

#include "../../command_line_sections.h"

void	free_command_sections(t_command_line_section_list command_sections)
{
	if (command_sections.length > 0)
	{
		if (command_sections.data[command_sections.length - 1].quote_level == 0)
			free(command_sections.data[command_sections.length - 1].contents);
	}
	free(command_sections.data);
}
