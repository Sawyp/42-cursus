/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:02:52 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:02:52 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <libft.h>

#include "../homebrewed.h"

static char	*get_cwd(void)
{
	char	*buf;
	size_t	i;

	i = 1;
	buf = NULL;
	while (i == 1 || errno == ERANGE)
	{
		free(buf);
		buf = malloc(1024 * i);
		getcwd(buf, 1024 * i++);
	}
	return (buf);
}

static int	get_target_dir(
		const t_env_mod_data *env_mod_data,
		const char **target
		)
{
	if (env_mod_data->args.size > 1)
		return (ft_fdprintf(2, "cd: too many arguments\n"), 1);
	if (env_mod_data->args.size == 0)
	{
		*target = try_get_variable(env_mod_data->variable_registry, "HOME");
		if (*target == NULL)
			return (ft_fdprintf(2, "cd: HOME not set\n"), 1);
	}
	else if (ft_strcmp(env_mod_data->args.strings[0], "-") == 0)
	{
		*target = try_get_variable(env_mod_data->variable_registry, "OLDPWD");
		if (*target == NULL)
			return (ft_fdprintf(2, "cd: OLDPWD not set\n"), 1);
	}
	else
		*target = env_mod_data->args.strings[0];
	return (0);
}

int	hb_cd(void *data)
{
	t_env_mod_data	*env_mod_data;
	int				status;
	const char		*target;
	char			*old_cwd;
	char			*cwd;

	env_mod_data = data;
	status = get_target_dir(env_mod_data, &target);
	if (status != 0)
		return (status);
	old_cwd = get_cwd();
	if (chdir(target))
		return (ft_fdprintf(2, "cd: %s: %s\n", strerror(errno), target),
			free(old_cwd), 1);
	if (ft_strcmp(target, "//") == 0)
		set_variable(env_mod_data->variable_registry, "PWD", "//");
	else
	{
		cwd = get_cwd();
		set_variable(env_mod_data->variable_registry, "PWD", cwd);
		free(cwd);
	}
	set_variable(env_mod_data->variable_registry, "OLDPWD", old_cwd);
	return (free(old_cwd), 0);
}
