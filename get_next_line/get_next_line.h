/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:32:33 by lsanglas          #+#    #+#             */
/*   Updated: 2021/12/14 15:32:35 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strnjoin(char **s1, const char *s2, size_t n);

char		*get_next_line(int fd);

#endif
