/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_iteration.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:14:17 by aronez            #+#    #+#             */
/*   Updated: 2022/12/09 10:14:17 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_ITERATION_H
# define COMMAND_ITERATION_H

# include <stddef.h>

typedef struct s_command_iterator
{
	size_t	idx;
	char	quote_mode;
}	t_command_iterator;

typedef struct s_command_char
{
	char	c;
	char	current_quote_mode;
	int		is_control_quote;
}	t_command_char;

t_command_iterator	new_command_iterator(void);

t_command_char		peek(
						const t_command_iterator *command_iterator,
						const char *command_string
						);
t_command_char		next_command_char(
						t_command_iterator *command_iterator,
						const char *command_string
						);

#endif //COMMAND_ITERATION_H
