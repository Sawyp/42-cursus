/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:52:50 by lsanglas          #+#    #+#             */
/*   Updated: 2023/01/03 15:52:50 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <libft.h>
#include <readline/readline.h>

#include "../parsed_command.h"

static int	open_unique_tmp_file(size_t i, size_t j, char **name, int *fd)
{
	char	*name_parts[4];

	name_parts[0] = "/tmp/minishell_here_doc_";
	name_parts[1] = ft_lltoa((long long)i);
	name_parts[2] = "_";
	name_parts[3] = ft_lltoa((long long)j);
	*name = ft_strsnjoin((const char **)name_parts, 4);
	free(name_parts[1]);
	free(name_parts[3]);
	*fd = open(*name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
	if (*fd < 0)
		return (free(*name), ft_fdprintf(2, "%s\n", strerror(errno)), errno);
	return (0);
}

static int	fill_here_doc(int *fd, const char *end, char *name)
{
	char	*line;

	line = readline("> ");
	while (line != NULL && ft_strcmp(line, end) != 0)
	{
		if (write(*fd, line, ft_strlen(line)) < 0)
			return (ft_fdprintf(2, "%s\n", strerror(errno)), free(line), errno);
		if (write(*fd, "\n", 1) < 0)
			return (ft_fdprintf(2, "%s\n", strerror(errno)), free(line), errno);
		free(line);
		line = readline("> ");
	}
	if (line == NULL)
		ft_fdprintf(2, "warning: here-document delimited by end-of-file"
			" (wanted `%s\')\n", end);
	free(line);
	close(*fd);
	*fd = open(name, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP);
	unlink(name);
	return (free(name), 0);
}

int	setup_here_docs(t_parsed_commands *parsed_commands)
{
	int		status;
	size_t	i;
	size_t	j;
	char	*name;

	i = -1;
	while (++i < parsed_commands->size)
	{
		j = -1;
		while (++j < parsed_commands->data[i].files.size)
		{
			if (parsed_commands->data[i].files.data[j].mode != HERE_DOCUMENT)
				continue ;
			status = open_unique_tmp_file(i, j, &name,
					&parsed_commands->data[i].files.data[j].fd);
			if (status != 0)
				return (status);
			status = fill_here_doc(&parsed_commands->data[i].files.data[j].fd,
					parsed_commands->data[i].files.data[j].id, name);
			if (status != 0)
				return (status);
		}
	}
	return (0);
}

void	close_here_docs(const t_parsed_commands *parsed_commands)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < parsed_commands->size)
	{
		j = -1;
		while (++j < parsed_commands->data[i].files.size)
		{
			if (parsed_commands->data[i].files.data[j].mode != HERE_DOCUMENT)
				continue ;
			if (parsed_commands->data[i].files.data[j].fd < 0)
				return ;
			close(parsed_commands->data[i].files.data[j].fd);
		}
	}
}
