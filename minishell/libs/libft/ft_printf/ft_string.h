/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

typedef struct s_ft_string
{
	char	*str;
	size_t	len;
}	t_ft_string;

t_ft_string	ft_stringnjoin(const t_ft_string *strings, size_t count);

#endif //FT_STRING_H
