/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exploration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:58:54 by aronez            #+#    #+#             */
/*   Updated: 2022/12/12 13:58:54 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPLORATION_H
# define EXPLORATION_H

# include "../command_line_sections.h"
# include "../command_sections_iteration.h"

int		aggregate_until_unquoted_section(
			t_command_line_section_list sections,
			t_commands_iterator *iterator
			);
int		aggregate_unquoted_section(
			t_command_line_section_list sections,
			t_commands_iterator *iterator
			);

#endif //EXPLORATION_H
