/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:02:59 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:02:59 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <libft.h>

#include "../homebrewed.h"

static int	is_id_valid(const char *str)
{
	size_t	i;

	if (!(str[0] == '_' || ft_isalpha(str[0])))
		return (0);
	i = 0;
	while (str[i] != '\0' && !(str[i] == '+' || str[i] == '='))
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (str[i] == '+' && str[i + 1] != '=')
		return (0);
	return (1);
}

void	handle_export(t_variable_registry *registry, const char *cmd)
{
	char	*op;
	char	*var_name;
	char	*var_val;

	op = ft_strstr(cmd, "+=");
	if (op != NULL)
	{
		var_name = ft_substr(cmd, 0, op - cmd);
		var_val = (char *)try_get_variable(registry, var_name);
		if (var_val == NULL)
			var_val = ft_strdup(op + 2);
		else
			var_val = ft_strjoin(var_val, op + 2);
	}
	else
	{
		op = ft_strchr(cmd, '=');
		if (op == NULL)
			return ;
		var_name = ft_substr(cmd, 0, op - cmd);
		var_val = ft_strdup(op + 1);
	}
	set_variable(registry, var_name, var_val);
	free(var_val);
	free(var_name);
}

int	hb_export(void *data)
{
	size_t			i;
	t_env_mod_data	*env_mod_data;

	env_mod_data = data;
	i = -1;
	while (++i < env_mod_data->args.size)
	{
		if (!is_id_valid(env_mod_data->args.strings[i]))
			return (ft_fdprintf(2, "export: `%s\': not a valid identifier\n",
					env_mod_data->args.strings[i]), 1);
		handle_export(env_mod_data->variable_registry,
			env_mod_data->args.strings[i]);
	}
	return (0);
}
