/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:24:42 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/07 11:24:42 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_FORKING_H
# define FUNCTIONS_FORKING_H

# include "command.h"
# include "parsed_command.h"
# include "variable_registry.h"
# include "command_priming.h"

typedef struct s_processes_future
{
	size_t	size;
	pid_t	*pids;
}	t_processes_future;

int	fork_functions(t_parsed_commands commands, t_hahaha hahaha,
		t_variable_registry *registry, t_processes_future *future);

/**
 * Waits for each child process stored in the future parameter to terminate and
 * returns the low-order 8 bits of the status argument that the child process
 * passed to exit().
 * @brief Waits for childs to finish and returns first nonzero exit value.
 * @param future A list of pids to ensure the main process will wait.
 * @return The exit value of the first unnatural ending in the command chain.
 */
int	wait_processes_future(t_processes_future future);

#endif //FUNCTIONS_FORKING_H
