/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:02:33 by lsanglas          #+#    #+#             */
/*   Updated: 2022/12/28 16:02:33 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

#include "../../parsed_command.h"

int	is_no_new_line_arg(const char *arg)
{
	size_t	i;

	if (arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 1;
	while (arg[++i] != '\0')
	{
		if (arg[i] != 'n')
			return (0);
	}
	return (1);
}

int	hb_echo(void *data)
{
	size_t	i;
	int		newline;

	newline = 1;
	i = 0;
	while (i < ((t_string_list *)data)->size
		&& is_no_new_line_arg(((t_string_list *)data)->strings[i]))
	{
		i++;
		newline = 0;
	}
	i--;
	while (++i < ft_smax(((t_string_list *)data)->size, 1) - 1)
		ft_printf("%s ", ((t_string_list *)data)->strings[i]);
	if (i < ((t_string_list *)data)->size)
		ft_printf("%s", ((t_string_list *)data)->strings[i]);
	if (newline)
		ft_printf("\n");
	return (0);
}
