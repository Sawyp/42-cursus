/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:57:16 by lsanglas          #+#    #+#             */
/*   Updated: 2022/09/12 12:57:23 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	throw_error(int errno, int ex)
{
	write(2, "pipex: ", 7);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	if (ex)
		exit(errno);
	return (errno);
}

void	exec(char *commands, char **env)
{
	char	*command;
	char	**av;

	av = ft_split(commands, ' ');
	if (!av)
		return ;
	command = get_path(av[0], env);
	if (!command)
	{
		ft_split_free(av);
		throw_error(95, 1);
	}
	if (execve(command, av, env) == -1)
	{
		ft_split_free(av);
		return ;
	}
	ft_split_free(av);
	free(command);
}

void	pipex(int *input, char *commands, char **env)
{
	int		end[2];

	pipe(end);
	if (*input != -1 && !fork())
	{
		close(end[0]);
		if (dup2(end[1], 1) == -1)
			return ;
		exec(commands, env);
		exit(0);
	}
	*input = 1;
	if (dup2(end[0], 0) == -1)
		return ;
	close(end[1]);
	close(end[0]);
}

void	helper(int ac, char **av, char **env)
{
	int	i;
	int	input;
	int	output;

	i = 2;
	input = open(av[1], O_RDONLY);
	output = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (input == -1 || dup2(input, 0) == -1)
		throw_error(2, 0);
	if (dup2(output, 1) == -1)
		throw_error(2, 0);
	if (input != -1)
		close(input);
	if (output != -1)
		close(output);
	while (i < ac - 2)
		pipex(&input, av[i++], env);
	if (output != -1 && !fork())
		exec(av[i], env);
	close(0);
	close(1);
	while (waitpid(-1, NULL, 0) != -1)
		;
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		return (throw_error(22, 0));
	if (!*av[2] || !*av[3])
		return (throw_error(22, 0));
	helper(ac, av, env);
	return (0);
}
