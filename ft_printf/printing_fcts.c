/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:03:43 by lsanglas          #+#    #+#             */
/*   Updated: 2021/12/27 13:03:45 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(long nb)
{
	int		return_value;

	return_value = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		return (ft_putnbr(-nb) + 1);
	}
	if (nb > 9)
	{
		return_value = ft_putnbr(nb / 10);
		return_value += ft_putnbr(nb % 10);
		return (return_value);
	}
	return (ft_putchar(nb + '0'));
}

int	ft_putstr(char *s)
{
	int	return_value;

	return_value = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
		return_value += write(1, s++, 1);
	return (return_value);
}

int	ft_puthex(unsigned long nb, int caps)
{
	int		return_value;
	char	*base;

	return_value = 0;
	base = "0123456789abcdef";
	if (caps)
		base = "0123456789ABCDEF";
	if (nb > 15)
		return_value += ft_puthex(nb / 16, caps);
	return_value += ft_putchar(base[nb % 16]);
	return (return_value);
}

int	ft_putptr(unsigned long ptr)
{
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_puthex(ptr, 0) + 2);
}
