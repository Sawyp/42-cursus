/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:04:57 by aronez            #+#    #+#             */
/*   Updated: 2022/12/24 12:04:57 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../variable_registry.h"

t_variable_registry	new_variable_registry(char **envp)
{
	t_variable_registry	variable_registry;
	char				*equal_sign;

	variable_registry = (t_variable_registry){.length = 0, .capacity = 50,
		.data = malloc(sizeof(char **) * (50 * 2))};
	while (envp[variable_registry.length] != NULL)
	{
		if (variable_registry.length == variable_registry.capacity)
		{
			variable_registry.data = ft_realloc(variable_registry.data,
					sizeof(char *) * (variable_registry.capacity * 2),
					sizeof(char *) * ((variable_registry.capacity + 50) * 2));
			variable_registry.capacity += 50;
		}
		equal_sign = ft_strchr(envp[variable_registry.length], '=');
		variable_registry.data[2 * variable_registry.length + 0] = ft_strndup(
				envp[variable_registry.length], equal_sign
				- envp[variable_registry.length]);
		variable_registry.data[2 * variable_registry.length + 1]
			= ft_strdup(equal_sign + 1);
		variable_registry.length++;
	}
	return (variable_registry);
}

void	free_variable_registry(t_variable_registry *registry)
{
	size_t	i;

	i = -1;
	while (++i < registry->length)
	{
		free(registry->data[2 * i + 0]);
		free(registry->data[2 * i + 1]);
	}
	free(registry->data);
}
