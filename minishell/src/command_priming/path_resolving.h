/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolving.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:29:41 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/12 10:29:41 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_RESOLVING_H
# define PATH_RESOLVING_H

# include "../command.h"
# include "../parsed_command.h"

int	resolve_path(t_parsed_command parsed_command,
		t_command *command, const char *path);

#endif //PATH_RESOLVING_H
