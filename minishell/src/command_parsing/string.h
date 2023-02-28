/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:19:29 by aronez            #+#    #+#             */
/*   Updated: 2022/12/08 13:19:29 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>

typedef struct s_string
{
	size_t	capacity;
	size_t	length;
	char	*data;
}	t_string;

t_string	new_string(void);
void		free_string(t_string *string);
void		extend_string(t_string *string);

size_t		string_len(const t_string *string);

void		append_char_to_string(t_string *string, char c);
void		append_str_to_string(t_string *string, const char *str);
void		append_strn_to_string(t_string *string, const char *str, size_t n);

#endif //STRING_H
