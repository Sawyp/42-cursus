/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_command.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:29:26 by aronez            #+#    #+#             */
/*   Updated: 2022/12/09 15:29:26 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSED_COMMAND_H
# define PARSED_COMMAND_H

# include <stddef.h>
# include <fcntl.h>

typedef enum e_open_mode
{
	READ_ONLY = O_RDONLY,
	HERE_DOCUMENT,
	TRUNCATE = O_WRONLY | O_CREAT | O_TRUNC,
	APPEND = O_WRONLY | O_CREAT | O_APPEND
}	t_open_mode;

typedef struct s_file
{
	t_open_mode	mode;
	int			fd;
	char		*id;
}	t_file;

typedef struct s_file_list
{
	size_t	size;
	t_file	*data;
}	t_file_list;

typedef struct s_string_list
{
	size_t	size;
	char	**strings;
}	t_string_list;

typedef struct s_parsed_command
{
	char			*command_name;
	t_string_list	command_args;
	t_file_list		files;
}	t_parsed_command;

typedef struct s_parsed_command_list
{
	size_t				size;
	size_t				capacity;
	t_parsed_command	*data;
}	t_parsed_commands;

t_parsed_commands	new_parsed_command_list(void);
void				free_parsed_command_list(t_parsed_commands *list);
void				append_to_parsed_command_list(
						t_parsed_commands *parsed_commands,
						t_parsed_command command
						);

#endif //PARSED_COMMAND_H
