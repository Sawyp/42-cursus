/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:19 by aronez            #+#    #+#             */
/*   Updated: 2022/11/30 12:19:19 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <libft.h>

#include "command.h"
#include "command_parsing.h"
#include "command_priming.h"
#include "functions_forking.h"
#include "parsed_command.h"
#include "signal_managing.h"
#include "variable_registry.h"

static int	is_only_spaces(const char *string)
{
	size_t	i;

	i = -1;
	while (string[++i] != '\0')
	{
		if (!ft_isblank(string[i]))
			return (0);
	}
	return (1);
}

static int	try_execute_command(
		int *stop,
		t_command_line_section_list sections,
		int previous_return_code,
		t_variable_registry *variable_registry)
{
	int						status;
	t_parsed_commands		parsed_commands;
	t_processes_future		future;

	if (parse_quoted_command_line(sections, previous_return_code,
			variable_registry, &parsed_commands) != 0)
		return (2);
	status = fork_functions(parsed_commands, (t_hahaha){stop,
			previous_return_code}, variable_registry, &future);
	if ((status & (0b1 << 10)) == 0 && status != 0)
		return (wait_processes_future(future),
			free_parsed_command_list(&parsed_commands), status);
	if ((status & (0b1 << 10)) == 0)
		status = wait_processes_future(future);
	else
		free(future.pids);
	free_parsed_command_list(&parsed_commands);
	return (status);
}

static int	run_interactive_mode(
		const char *prompt,
		t_variable_registry *variable_registry)
{
	int							previous_status;
	int							stop;
	char						*line;
	t_command_line_section_list	sections;

	previous_status = 0;
	line = malloc(1);
	stop = 0;
	while (line != NULL && !stop && (previous_status & (0b1 << 10)) == 0)
	{
		free(line);
		setup_prompt_signals();
		line = readline(prompt);
		setup_ignoring_signals();
		if (line != NULL && !is_only_spaces(line))
		{
			sections = quote_command_line(line);
			previous_status = try_execute_command(&stop, sections,
					previous_status, variable_registry);
			free_command_line_section_list(&sections);
			add_history(line);
		}
	}
	return (free(line), previous_status & 0b111111111);
}

static int	run_single_command_mode(
		int argc,
		char **argv,
		t_variable_registry *variable_registry)
{
	t_command_line_section_list	sections;
	int							return_status;
	int							dummy_stop;

	sections = quote_argv(argv, argc);
	return_status = try_execute_command(&dummy_stop, sections, 0,
			variable_registry);
	if ((return_status & (0b1 << 10)) == 0)
		return (free_command_line_section_list(&sections), return_status);
	return (free_command_line_section_list(&sections),
		return_status & 0b111111111);
}

int	main(int argc, char **argv, char **envp)
{
	int						status;
	t_variable_registry		variable_registry;

	setup_ignoring_signals();
	variable_registry = new_variable_registry(envp);
	if (argc == 1)
		status = run_interactive_mode("minishell>", &variable_registry);
	else
		status = run_single_command_mode(argc, argv, &variable_registry);
	return (free_variable_registry(&variable_registry), status);
}
