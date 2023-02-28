/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_priming.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:16:41 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/09 11:16:41 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_PRIMING_H
# define COMMAND_PRIMING_H

# include <stddef.h>

# include "variable_registry.h"

# include "command.h"
# include "parsed_command.h"

typedef struct s_hahaha
{
	int	*stop;
	int	previous_return_code;
}	t_hahaha;

int	prime_command(t_parsed_command *parsed_command, t_hahaha hahaha,
		t_variable_registry *variable_registry, t_command *command);

#endif //COMMAND_PRIMING_H
