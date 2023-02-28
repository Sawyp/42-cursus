/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:15:35 by aronez            #+#    #+#             */
/*   Updated: 2022/12/12 16:15:35 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPL_H
# define IMPL_H

# include "../command_line_sections.h"
# include "../command_sections_iteration.h"

void	iterate_to_next_pipe(
			t_commands_iterator *iterator,
			t_command_line_section_list sections);

#endif //IMPL_H
