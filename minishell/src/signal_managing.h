/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:08:42 by aronez            #+#    #+#             */
/*   Updated: 2023/01/04 12:08:42 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_MANAGING_H
# define SIGNAL_MANAGING_H

# include "signal.h"
# include "functions_forking.h"

void	setup_prompt_signals(void);
void	setup_ignoring_signals(void);
void	setup_execution_signals(void);

#endif //SIGNAL_MANAGING_H
