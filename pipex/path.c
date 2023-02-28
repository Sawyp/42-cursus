/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:01:12 by lsanglas          #+#    #+#             */
/*   Updated: 2022/09/12 17:01:14 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *str1, char *str2, int n)
{
	if (!n)
		return (1);
	else if (*str1 != *str2)
		return (0);
	return (ft_strncmp(++str1, ++str2, --n));
}

char	*append_path(char *path, char *command)
{
	char	*command_path;

	command_path = ft_strjoin_command(path, command);
	if (!access(command_path, F_OK | X_OK))
		return (command_path);
	free (command_path);
	return (NULL);
}

char	*get_path(char *command, char **env)
{
	char	**paths;
	char	*path;
	int		i;

	if (!access(command, F_OK | X_OK))
		return (command);
	while (*env && !ft_strncmp(*env, "PATH=", 5))
		env++;
	if (!env)
		return (NULL);
	paths = ft_split(*env + 5, ':');
	path = NULL;
	i = -1;
	while (paths[++i] && !path)
		path = append_path(paths[i], command);
	ft_split_free(paths);
	return (path);
}
