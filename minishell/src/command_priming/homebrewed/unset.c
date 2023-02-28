/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:03:07 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:03:07 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../../variable_registry.h"
#include "../homebrewed.h"

int	hb_unset(void *data)
{
	size_t	i;

	i = -1;
	while (++i < ((t_env_mod_data *)data)->args.size)
		remove_variable(((t_env_mod_data *)data)->variable_registry,
			((t_env_mod_data *) data)->args.strings[i]);
	return (0);
}
