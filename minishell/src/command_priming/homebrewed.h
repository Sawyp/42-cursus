/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homebrewed.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:01:49 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:01:49 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HOMEBREWED_H
# define HOMEBREWED_H

# include "../parsed_command.h"
# include "../variable_registry.h"

int		hb_echo(void *data);

int		hb_pwd(void *data);

typedef struct s_env_mod_data
{
	t_string_list		args;
	t_variable_registry	*variable_registry;
}	t_env_mod_data;
int		hb_export(void *data);
int		hb_unset(void *data);
int		hb_cd(void *data);

int		hb_env(void *data);

int		hb_exit(void *data);
void	free_exit_resources(void *data);

int		hb_no_op(void *data);

#endif //HOMEBREWED_H
