/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <malloc.h>

#include "../libft.h"
#include "ft_string.h"

static t_ft_string	handle_char(char code, va_list args)
{
	t_ft_string	str;

	str.len = 1;
	str.str = malloc(sizeof(char) * (str.len + 1));
	if (str.str == NULL)
		return ((t_ft_string){NULL, 0});
	str.str[0] = '%';
	if (code == 'c')
		str.str[0] = va_arg(args, int);
	str.str[1] = '\0';
	return (str);
}

static t_ft_string	handle_pointer(void *p)
{
	char		*hexa_ptr_addr;
	t_ft_string	result;

	if (p == NULL)
		return ((t_ft_string){ft_strdup("(nil)"), ft_strlen("(nil)")});
	hexa_ptr_addr = ft_ulltoa_base((uintptr_t)p, "0123456789abcdef");
	if (hexa_ptr_addr == NULL)
		return ((t_ft_string){NULL, 0});
	result.str = ft_strjoin("0x", hexa_ptr_addr);
	if (result.str == NULL)
		return (free(hexa_ptr_addr), (t_ft_string){NULL, 0});
	result.len = ft_strlen(result.str);
	free(hexa_ptr_addr);
	return (result);
}

static t_ft_string	handle_integer_base(long long l, const char *base)
{
	char	*integer_str;

	integer_str = ft_lltoa_base(l, base);
	if (integer_str == NULL)
		return ((t_ft_string){NULL, 0});
	return ((t_ft_string){integer_str, ft_strlen(integer_str)});
}

t_ft_string	handle_printf_code(char code, va_list args)
{
	const char	*tmp;

	if (code == '%' || code == 'c')
		return (handle_char(code, args));
	else if (code == 's')
	{
		tmp = va_arg(args, const char *);
		if (tmp == NULL)
			return ((t_ft_string){ft_strdup("(null)"), ft_strlen("(null)")});
		return ((t_ft_string){ft_strdup(tmp), ft_strlen(tmp)});
	}
	else if (code == 'p')
		return (handle_pointer(va_arg(args, void *)));
	else if (code == 'd' || code == 'i')
		return (handle_integer_base(va_arg(args, int), "0123456789"));
	else
	{
		if (code == 'u')
			tmp = "0123456789";
		if (code == 'x')
			tmp = "0123456789abcdef";
		if (code == 'X')
			tmp = "0123456789ABCDEF";
		return (handle_integer_base(va_arg(args, unsigned int), tmp));
	}
}
