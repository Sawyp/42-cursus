/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:02:24 by aronez            #+#    #+#             */
/*   Updated: 2022/12/17 13:02:24 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../parsed_command.h"
# include "../variable_registry.h"

# include "command_line_sections.h"

int	parse_command(
		const t_command_line_section_list *command_sections,
		int previous_return_code,
		const t_variable_registry *variable_registry,
		t_parsed_command *parsed_command
		);

#endif //PARSING_H
