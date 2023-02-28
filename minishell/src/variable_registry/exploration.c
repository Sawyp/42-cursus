/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exploration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:24:28 by aronez            #+#    #+#             */
/*   Updated: 2022/12/24 13:24:28 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../variable_registry.h"

static size_t	try_get_variable_index(
		const t_variable_registry *registry,
		const char *variable_name
		)
{
	size_t	i;

	i = 0;
	while (i < registry->length
		&& ft_strcmp(registry->data[2 * i + 0], variable_name) != 0)
		i++;
	return (i);
}

void	set_variable(
		t_variable_registry *registry,
		const char *variable_name,
		const char *variable_value
		)
{
	size_t	i;

	i = try_get_variable_index(registry, variable_name);
	if (i < registry->length)
	{
		free(registry->data[2 * i + 1]);
		registry->data[2 * i + 1] = ft_strdup(variable_value);
	}
	else
	{
		if (registry->length == registry->capacity)
		{
			registry->data = ft_realloc(registry->data,
					sizeof(char *) * (registry->capacity * 2),
					sizeof(char *) * ((registry->capacity + 50) * 2));
			registry->capacity += 50;
		}
		registry->data[2 * registry->length + 0] = ft_strdup(variable_name);
		registry->data[2 * registry->length + 1] = ft_strdup(variable_value);
		registry->length++;
	}
}

void	remove_variable(
		t_variable_registry *registry,
		const char *variable_name
		)
{
	size_t	i;

	i = try_get_variable_index(registry, variable_name);
	if (i < registry->length)
	{
		free(registry->data[2 * i + 0]);
		free(registry->data[2 * i + 1]);
		ft_memmove(registry->data + (2 * i), registry->data + (2 * (i + 1)),
			sizeof(char *) * (2 * (registry->length - i - 1)));
		registry->length--;
	}
}

const char	*try_get_variable(
		const t_variable_registry *registry,
		const char *variable_name
		)
{
	size_t	i;

	i = try_get_variable_index(registry, variable_name);
	if (i < registry->length)
		return (registry->data[2 * i + 1]);
	else
		return (NULL);
}
