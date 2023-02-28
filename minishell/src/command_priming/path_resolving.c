/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolving.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:29:41 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/12 10:29:41 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#include "../command.h"
#include "../parsed_command.h"
#include "execve_invoker.h"

static char	*join_paths(char *path_a, char *path_b)
{
	const size_t	path_a_length = ft_strlen(path_a);
	const size_t	path_b_length = ft_strlen(path_b);
	char			*result;

	result = malloc((path_a_length + 1 + path_b_length + 1) * sizeof(char));
	ft_strcpy(result, path_a);
	result[path_a_length] = '/';
	ft_strcpy(result + (path_a_length + 1), path_b);
	return (result);
}

static int	try_absolute_path(t_parsed_command parsed_command,
		t_execve_data *data)
{
	if (access(parsed_command.command_name, X_OK) < 0)
		return (0);
	if (ft_strcmp(parsed_command.command_name, "..") == 0)
		return (0);
	data->path = ft_strdup(parsed_command.command_name);
	return (1);
}

static int	try_path_combination(t_parsed_command parsed_command,
		t_execve_data *data, char **paths)
{
	int	i;

	if (ft_strcmp(parsed_command.command_name, "") == 0
		|| ft_strcmp(parsed_command.command_name, "..") == 0)
		return (-1);
	i = -1;
	while (paths[++i] != NULL)
	{
		data->path = join_paths(paths[i], parsed_command.command_name);
		if (access(data->path, X_OK) == 0)
			return (0);
		free(data->path);
	}
	return (-1);
}

int	resolve_path(t_parsed_command parsed_command,
		t_command *command, const char *path)
{
	char			**paths;
	t_execve_data	*data;

	data = malloc(sizeof(t_execve_data));
	if (parsed_command.command_name != NULL
		&& !try_absolute_path(parsed_command, data))
	{
		if (path == NULL)
			return (ft_fdprintf(2, "%s: No such file or directory\n",
					parsed_command.command_name), free(data), 127);
		else
		{
			paths = ft_split(path, ':');
			if (try_path_combination(parsed_command, data, paths) != 0)
				return (ft_fdprintf(2, "%s: command not found\n",
						parsed_command.command_name), ft_free_strs(paths),
					free(data), 127);
			ft_free_strs(paths);
		}
	}
	command->f_data = data;
	return (0);
}
