/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_invoker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:09:13 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:09:13 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

#include "execve_invoker.h"

void	delete_execve_data(void *data)
{
	free(((t_execve_data *)data)->path);
	ft_free_strs(((t_execve_data *)data)->envp);
	free(data);
}

int	invoke_execve(void *data)
{
	size_t	i;
	char	**null_terminated_args;

	null_terminated_args = malloc((((t_execve_data *)data)->args.size + 2)
			* sizeof(char *));
	null_terminated_args[0] = ((t_execve_data *)data)->name;
	i = -1;
	while (++i < ((t_execve_data *)data)->args.size)
		null_terminated_args[1 + i] = ((t_execve_data *)data)->args.strings[i];
	null_terminated_args[1 + i] = NULL;
	if (execve(((t_execve_data *)data)->path, null_terminated_args,
			((t_execve_data *)data)->envp) < 0)
		return (ft_fdprintf(2, "%s\n", strerror(errno)),
			free(null_terminated_args), errno);
	return (0);
}
