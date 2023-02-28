/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:32:06 by aronez            #+#    #+#             */
/*   Updated: 2022/12/08 13:32:06 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <libft.h>

#include "../string.h"

t_string	new_string(void)
{
	t_string	string;

	string.capacity = 16;
	string.data = malloc(sizeof(char) * string.capacity);
	string.data[0] = '\0';
	string.length = 1;
	return (string);
}

void	free_string(t_string *string)
{
	free(string->data);
}

void	extend_string(t_string *string)
{
	if (string->capacity >= 256)
		string->capacity += 256;
	else
		string->capacity *= 2;
	string->data = ft_realloc(string->data, sizeof(char) * string->length,
			sizeof(char) * (string->capacity - string->length));
}
