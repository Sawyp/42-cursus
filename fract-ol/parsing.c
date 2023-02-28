/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:45:31 by lsanglas          #+#    #+#             */
/*   Updated: 2022/07/11 12:54:28 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

double	get_magnitude(char *s)
{
	double	magnitude;

	magnitude = 0.01;
	if (*s == '0')
		return (1);
	while (*s && *s++ != '.')
		magnitude *= 10;
	return (magnitude);
}

double	atod(char *s)
{
	double	magnitude;
	double	value;
	double	sign;

	sign = 1;
	if (*s == '-' && ++s)
		sign = -1;
	magnitude = get_magnitude(s);
	value = (*s - 48) * magnitude;
	while (*++s)
	{
		if (*s == '.')
			++s;
		magnitude /= 10;
		value += (*s - 48) * magnitude;
	}
	return (value * sign);
}

int	parse(t_data *data, int ac, char **av)
{
	if (ac < 2 || (*av[1] != '0' && *av[1] != '1')
		|| (*av[1] == '1' && ac != 4))
	{
		write(1, "Please try again using implemented parameters.\n", 47);
		write(1, "Available parameters are :\n", 27);
		write(1, "	-0 to render the Mandlebrot set.\n", 35);
		write(1, "	-1 followed by the two parameters ", 35);
		write(1, "a and b to render a Julia set.\n", 31);
		if (ac > 1 && *av[1] == '1' && ac != 4)
		{
			write(1, "\nYou did not enter the right", 28);
			write(1, " amount of parameters for the Julia set.\n", 41);
		}
		return (0);
	}
	if (*av[1] == '1')
		data->julia_parameters = (t_pixel){atod(av[2]), atod(av[3]), 0};
	return (1);
}
