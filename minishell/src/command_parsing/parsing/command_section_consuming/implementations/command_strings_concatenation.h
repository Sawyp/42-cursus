/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_strings_concatenation.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:15:43 by aronez            #+#    #+#             */
/*   Updated: 2022/12/20 16:15:43 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_STRINGS_CONCATENATION_H
# define COMMAND_STRINGS_CONCATENATION_H

# include "../../../command_line_sections.h"
# include "../../../string.h"
# include "../../command_sections_index.h"
# include "../consumers.h"

int			is_command_control_char(char c);

t_string	concatenate_until_command_control_char(
				const t_command_line_section_list *command_sections,
				t_command_sections_index *idx,
				t_resolution_data resolution_data
				);

#endif //COMMAND_STRINGS_CONCATENATION_H
