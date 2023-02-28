/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:30:44 by lsanglas          #+#    #+#             */
/*   Updated: 2021/12/27 12:30:47 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int		return_value;
	char	c;

	return_value = 0;
	if (nb > 9)
		return_value += ft_putnbr(nb / 10);
	c = nb % 10 + 48;
	return_value += write(1, &c, 1);
	return (return_value);
}

static int	ft_helper(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			return_value;

	return_value = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			return_value += ft_helper(*++str, args);
		else
			return_value += write(1, str, 1);
		++str;
	}
	va_end(args);
	return (return_value);
}

// #include <stdio.h>
// #include <values.h>
// int	main(int ac, char **av)
// {
// 	printf("\n%d\n", ft_printf("%d", INT_MIN));
// 	printf("\n%d\n", printf("%d", INT_MIN));
// 	return (0);
// }
