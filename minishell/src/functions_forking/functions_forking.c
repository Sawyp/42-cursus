/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_forking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:10:35 by lsanglas          #+#    #+#             */
/*   Updated: 2023/01/03 14:10:35 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libft.h>

#include "../functions_forking.h"
#include "../parsed_command.h"
#include "../command_parsing/string.h"
#include "../command_priming.h"
#include "../command_priming/homebrewed.h"
#include "../signal_managing.h"
#include "fds.h"

static int	open_and_dup(t_file_list files)
{
	size_t	i;
	int		fd;

	i = -1;
	while (++i < files.size)
	{
		if (files.data[i].mode != HERE_DOCUMENT)
		{
			fd = open(files.data[i].id, files.data[i].mode,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			if (fd < 0)
				return (ft_fdprintf(2, "%s\n", strerror(errno)), errno);
			if (dup2(fd, files.data[i].fd) < 0)
				return (close(fd), ft_fdprintf(2, "%s\n", strerror(errno)),
					errno);
			close(fd);
			continue ;
		}
		if (dup2(files.data[i].fd, 0) < 0)
			return (close(files.data[i].fd),
				ft_fdprintf(2, "%s\n", strerror(errno)), errno);
		close(files.data[i].fd);
	}
	return (0);
}

typedef struct s_popo
{
	t_hahaha			hahaha;
	t_variable_registry	*variable_registry;
}	t_popo;

static int	run_fork(size_t i, const t_parsed_commands *parsed_commands,
	int pipe_fds[3], t_popo gros_popo)
{
	int			status;
	t_command	command;

	setup_execution_signals();
	close(pipe_fds[0]);
	dup2(pipe_fds[2], 0);
	if (pipe_fds[2] != 0)
		close(pipe_fds[2]);
	if (i < parsed_commands->size - 1)
		dup2(pipe_fds[1], 1);
	close(pipe_fds[1]);
	status = open_and_dup(parsed_commands->data[i].files);
	if (status != 0)
		return (status | (0b1 << 10));
	status = prime_command(&parsed_commands->data[i], gros_popo.hahaha,
			gros_popo.variable_registry, &command);
	if (status != 0)
		return (status | (0b1 << 10));
	status = command.f(command.f_data);
	command.delete_data(command.f_data);
	return (status | (0b1 << 10));
}

static int	is_pipeable_fn(t_parsed_command *parsed_command, t_hahaha hahaha,
	t_variable_registry *variable_registry, int *f)
{
	t_command	command;

	if (parsed_command->command_name == NULL)
		return (1);
	if (ft_strcmp(parsed_command->command_name, "cd") == 0
		|| ft_strcmp(parsed_command->command_name, "export") == 0
		|| ft_strcmp(parsed_command->command_name, "unset") == 0
		|| ft_strcmp(parsed_command->command_name, "exit") == 0)
	{
		*f = prime_command(parsed_command, hahaha, variable_registry, &command);
		if (*f == 0)
			*f = command.f(command.f_data);
		return (command.delete_data(command.f_data), 0);
	}
	return (1);
}

static void	rotate_pipe_fds(int pipe_fds[3])
{
	close(pipe_fds[1]);
	if (pipe_fds[2] != 0)
		close(pipe_fds[2]);
	pipe_fds[2] = pipe_fds[0];
}

int	fork_functions(t_parsed_commands commands, t_hahaha haha,
	t_variable_registry *registry, t_processes_future *future)
{
	int			status;
	int			fds[3];
	size_t		i;

	*future = (t_processes_future){0, malloc(sizeof(pid_t) * commands.size)};
	if (commands.size == 1 && !is_pipeable_fn(&commands.data[0], haha,
			registry, &status))
		return (status);
	status = setup_here_docs(&commands);
	if (status != 0)
		return (close_here_docs(&commands), status);
	fds[2] = 0;
	i = -1;
	while (++i < commands.size)
	{
		pipe(fds);
		future->pids[i] = fork();
		if (future->pids[i] < 0)
			return (close_here_docs(&commands), -1);
		else if (future->pids[i] == 0)
			return (run_fork(i, &commands, fds, (t_popo){haha, registry}));
		rotate_pipe_fds(fds);
		future->size++;
	}
	return (close(fds[2]), close_here_docs(&commands), 0);
}
