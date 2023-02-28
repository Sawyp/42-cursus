/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:57:16 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 19:57:16 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../variable_registry.h"

char	**registry_to_envp(
		const t_variable_registry *registry
		)
{
	char	**envp;
	size_t	i;
	char	*var_str[3];

	envp = malloc(sizeof(char *) * (registry->length + 1));
	var_str[1] = "=";
	i = -1;
	while (++i < registry->length)
	{
		var_str[0] = registry->data[2 * i + 0];
		var_str[2] = registry->data[2 * i + 1];
		envp[i] = ft_strsnjoin((const char **)var_str, 3);
	}
	envp[i] = NULL;
	return (envp);
}
