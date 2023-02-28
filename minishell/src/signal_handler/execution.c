/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:11:33 by aronez            #+#    #+#             */
/*   Updated: 2023/01/04 14:11:33 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>

void	setup_execution_signals(void)
{
	struct sigaction	act;
	sigset_t			sigset;

	sigemptyset(&sigset);
	act = (struct sigaction){.sa_handler = SIG_DFL, .sa_flags = 0,
		.sa_mask = sigset};
	sigaction(SIGQUIT, &act, NULL);
	act = (struct sigaction){.sa_handler = SIG_DFL, .sa_flags = 0,
		.sa_mask = sigset};
	sigaction(SIGINT, &act, NULL);
}
