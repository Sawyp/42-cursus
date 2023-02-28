/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:58:29 by lsanglas          #+#    #+#             */
/*   Updated: 2022/09/12 16:58:34 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

char	**ft_split(char *s, char c);
void	ft_split_free(char **split);
char	*ft_strjoin_command(char *s1, char *s2);
char	*get_path(char *command, char **env);
int		ft_strlen(char *str);

#endif
