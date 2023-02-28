/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:08:14 by aronez            #+#    #+#             */
/*   Updated: 2023/01/04 14:08:14 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <signal.h>
#include <readline/readline.h>
#include <libft.h>

#include "../signal_managing.h"

static void	new_line_on_sigint(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	ft_printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	setup_prompt_signals(void)
{
	struct sigaction	act;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGQUIT);
	act = (struct sigaction){.sa_handler = &new_line_on_sigint, .sa_flags = 0,
		.sa_mask = sigset};
	sigaction(SIGINT, &act, NULL);
	act = (struct sigaction){.sa_handler = SIG_IGN, .sa_flags = 0,
		.sa_mask = sigset};
	sigaction(SIGQUIT, &act, NULL);
}
