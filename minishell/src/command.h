/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:16:36 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/09 12:16:36 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <stddef.h>

typedef struct s_command
{
	int				(*f)(void *);
	void			*f_data;
	void			(*delete_data)(void *);
}	t_command;

typedef struct s_command_list
{
	size_t		size;
	t_command	*data;
}	t_command_list;

t_command_list	new_command_list(size_t size);
void			free_command_list(t_command_list *commands);
void			no_op(void *data);

#endif //COMMAND_H
