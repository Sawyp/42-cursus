/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:02:39 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:02:39 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <malloc.h>
#include <unistd.h>
#include <libft.h>

#include "../../variable_registry.h"

int	hb_pwd(void *data)
{
	char						*buf;
	size_t						i;
	const t_variable_registry	*registry;
	const char					*pwd;

	registry = (const t_variable_registry *)data;
	pwd = try_get_variable(registry, "PWD");
	if (pwd != NULL && ft_strcmp(pwd, "//") == 0)
		ft_printf("//\n");
	else
	{
		i = 1;
		buf = NULL;
		while (i == 1 || errno == ERANGE)
		{
			free(buf);
			buf = malloc(1024 * i);
			getcwd(buf, 1024 * i++);
		}
		ft_printf("%s\n", buf);
		free(buf);
	}
	return (0);
}
