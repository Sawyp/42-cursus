/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_registry.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:16:03 by aronez            #+#    #+#             */
/*   Updated: 2022/12/23 11:16:03 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_REGISTRY_H
# define VARIABLE_REGISTRY_H

# include <stddef.h>

typedef struct s_variable_registry
{
	size_t	capacity;
	size_t	length;
	char	**data;
}	t_variable_registry;

/**
 * @brief Creates a new variable registry containing the environment variables
 * found in the given list.
 * @param envp A NULL-terminated list of strings containing variable names and
 * their values.
 * @return A filled variable registry instance.
 */
t_variable_registry	new_variable_registry(char **envp);
/**
 * @brief Frees the allocated memory within the given registry.
 * @param registry A registry created by new_variable_registry(char **).
 */
void				free_variable_registry(t_variable_registry *registry);

/**
 * @brief Changes the value of the given variable if it present in the given
 * registry. Otherwise the variable is added.
 * @param registry A registry in which a variable will be modified/added.
 * @param variable_name The name of the variable to modify/add.
 * @param variable_value The new value of the variable.
 */
void				set_variable(
						t_variable_registry *registry,
						const char *variable_name,
						const char *variable_value
						);
/**
 * @brief Removes the given variable from the registry if it is present.
 * @param registry A registry from which to remove a variable.
 * @param variable_name The name of the variable to remove.
 */
void				remove_variable(
						t_variable_registry *registry,
						const char *variable_name
						);
/**
 * @brief Searches in the registry for a variable, returning it if found, or
 * returning NULL if not.
 * @param registry A registry in which to search for a variable.
 * @param variable_name The name of the variable to look for.
 * @return Returns a read-only, internally managed string if the variable was
 * found, or NULL otherwise.
 */
const char			*try_get_variable(
						const t_variable_registry *registry,
						const char *variable_name
						);

char				**registry_to_envp(
						const t_variable_registry *registry
						);

#endif //VARIABLE_REGISTRY_H
