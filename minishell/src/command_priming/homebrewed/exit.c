/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:02:47 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:02:47 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <malloc.h>

int	hb_exit(void *data)
{
	long	status;
	size_t	arg_count;
	char	*arg;

	arg_count = *(size_t *)(data + sizeof(int *));
	if (arg_count == 0)
	{
		**(int **)data = 1;
		return (*(int *)(data + sizeof(int *) + sizeof(size_t)));
	}
	arg = *(char **)(data + sizeof(int *) + sizeof(size_t));
	if (ft_s_atol(arg, &status) != 0)
	{
		**(int **)data = 1;
		ft_fdprintf(2, "minishell: exit: %s: numeric argument required\n", arg);
		return (2);
	}
	if (arg_count > 1)
		return (ft_fdprintf(2, "minishell: exit: too many arguments\n"), 1);
	**(int **)data = 1;
	return ((unsigned char)status);
}

void	free_exit_resources(void *data)
{
	if (*(size_t *)(data + sizeof(int *)) != 0)
		free(*(char **)(data + sizeof(int *) + sizeof(size_t)));
	free(data);
}
