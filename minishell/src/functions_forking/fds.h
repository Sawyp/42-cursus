/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:21:44 by lsanglas          #+#    #+#             */
/*   Updated: 2023/01/03 14:21:44 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDS_H
# define FDS_H

# include "../parsed_command.h"

int		setup_here_docs(t_parsed_commands *parsed_commands);
void	close_here_docs(const t_parsed_commands *parsed_commands);

#endif //FDS_H
