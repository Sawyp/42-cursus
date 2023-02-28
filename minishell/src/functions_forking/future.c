/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   future.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:13:18 by lsanglas          #+#    #+#             */
/*   Updated: 2023/01/03 14:13:18 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <sys/wait.h>
#include <libft.h>

#include "../functions_forking.h"

int	get_signaled_status(int pid_status)
{
	int	signal_status;

	signal_status = WTERMSIG(pid_status);
	if (signal_status == 2)
		ft_printf("\n");
	else if (signal_status == 3)
		ft_printf("Quit (core dumped)\n");
	signal_status += 128;
	return (signal_status);
}

int	wait_processes_future(t_processes_future future)
{
	size_t	i;
	int		pid_status;
	int		exit_status;
	int		signal_status;

	exit_status = 0;
	signal_status = 0;
	i = -1;
	while (++i < future.size)
	{
		if (waitpid(future.pids[i], &pid_status, 0) == future.pids[i])
		{
			if (WIFEXITED(pid_status))
				exit_status = WEXITSTATUS(pid_status);
			else if (WIFSIGNALED(pid_status))
				signal_status = get_signaled_status(pid_status);
		}
	}
	free(future.pids);
	if (exit_status != 0)
		return (exit_status);
	return (signal_status);
}
