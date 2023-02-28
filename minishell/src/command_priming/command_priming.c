/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_priming.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:34:03 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/09 14:34:03 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../command.h"
#include "../command_priming.h"
#include "../parsed_command.h"
#include "../variable_registry.h"
#include "execve_invoker.h"
#include "homebrewed.h"
#include "path_resolving.h"

#include "path_resolving.h"

typedef int	(*t_f)(void *);

static t_f	translate_fn(t_parsed_command parsed_command)
{
	if (parsed_command.command_name == NULL)
		return (&hb_no_op);
	if (ft_strcmp(parsed_command.command_name, "echo") == 0)
		return (&hb_echo);
	else if (ft_strcmp(parsed_command.command_name, "env") == 0)
		return (&hb_env);
	else if (ft_strcmp(parsed_command.command_name, "pwd") == 0)
		return (&hb_pwd);
	else if (ft_strcmp(parsed_command.command_name, "export") == 0)
		return (&hb_export);
	else if (ft_strcmp(parsed_command.command_name, "unset") == 0)
		return (&hb_unset);
	else if (ft_strcmp(parsed_command.command_name, "cd") == 0)
		return (&hb_cd);
	else if (ft_strcmp(parsed_command.command_name, "exit") == 0)
		return (&hb_exit);
	else
		return (&invoke_execve);
}

static int	execve_command_constructor(t_parsed_command parsed_command,
	t_command *command, t_variable_registry *variable_registry)
{
	if (resolve_path(parsed_command, command,
			try_get_variable(variable_registry, "PATH")) != 0)
		return (-1);
	((t_execve_data *)command->f_data)->name = parsed_command.command_name;
	((t_execve_data *)command->f_data)->args = parsed_command.command_args;
	((t_execve_data *)command->f_data)->envp
		= registry_to_envp(variable_registry);
	command->delete_data = &delete_execve_data;
	return (0);
}

static void	env_mods_constructor(t_parsed_command parsed_command,
	t_command *command, t_variable_registry *variable_registry)
{
	command->f_data = malloc(sizeof(t_env_mod_data));
	((t_env_mod_data *)command->f_data)->args = parsed_command.command_args;
	((t_env_mod_data *)command->f_data)->variable_registry = variable_registry;
	command->delete_data = &free;
}

static void	exit_constructor(t_parsed_command *parsed_command, int *stop,
	int previous_return_code, t_command *command)
{
	command->f_data = malloc(sizeof(int *) + sizeof(size_t)
			+ ft_smax(sizeof(char *), sizeof(int)));
	*(int **)(command->f_data + 0) = stop;
	*(size_t *)(command->f_data + sizeof(int *))
		= parsed_command->command_args.size;
	if (parsed_command->command_args.size > 0)
		*(char **)(command->f_data + sizeof(int *) + sizeof(size_t))
			= ft_strdup(parsed_command->command_args.strings[0]);
	else
		*(int *)(command->f_data + sizeof(int *) + sizeof(size_t))
			= previous_return_code;
	command->delete_data = &free_exit_resources;
}

int	prime_command(t_parsed_command *parsed_command, t_hahaha hahaha,
	t_variable_registry *variable_registry, t_command *command)
{
	*command = (t_command){.f_data = NULL, .delete_data = &no_op,
		.f = translate_fn(*parsed_command)};
	if (command->f == &invoke_execve && execve_command_constructor(
			*parsed_command, command, variable_registry))
		return (127);
	else if (command->f == &hb_echo)
		command->f_data = &parsed_command->command_args;
	else if (command->f == &hb_env)
	{
		command->f_data = registry_to_envp(variable_registry);
		command->delete_data = (void (*)(void *)) & ft_free_strs;
	}
	else if (command->f == &hb_pwd)
		command->f_data = variable_registry;
	else if (command->f == &hb_export || command->f == &hb_unset
		|| command->f == &hb_cd)
		env_mods_constructor(*parsed_command, command, variable_registry);
	else if (command->f == &hb_exit)
		exit_constructor(parsed_command, hahaha.stop,
			hahaha.previous_return_code, command);
	return (0);
}
