/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:46:28 by aronez            #+#    #+#             */
/*   Updated: 2022/12/08 13:46:28 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../string.h"

void	append_char_to_string(t_string *string, char c)
{
	if (string->length == string->capacity)
		extend_string(string);
	string->data[string->length - 1] = c;
	string->length += 1;
	string->data[string->length - 1] = '\0';
}

void	append_str_to_string(t_string *string, const char *str)
{
	size_t	i;

	i = -1;
	while (str[++i] != '\0')
		append_char_to_string(string, str[i]);
}

void	append_strn_to_string(t_string *string, const char *str, size_t n)
{
	size_t	i;

	i = -1;
	while (str[++i] != '\0' && i < n)
		append_char_to_string(string, str[i]);
}
