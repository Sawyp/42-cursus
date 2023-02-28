/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_invoker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:08:03 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:08:03 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EXECVE_INVOKER_H
# define EXECVE_INVOKER_H

# include "../parsed_command.h"
# include "../variable_registry.h"

typedef struct s_execve_data
{
	char			*path;
	char			*name;
	t_string_list	args;
	char			**envp;
}	t_execve_data;
void	delete_execve_data(void *data);
int		invoke_execve(void *data);

#endif //EXECVE_INVOKER_H
