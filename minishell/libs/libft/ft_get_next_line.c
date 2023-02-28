/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stddef.h>
#include <unistd.h>

#include "libft.h"

#define BUFFER_SIZE 16384

typedef struct s_sub_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	start;
	ssize_t	buffer_size;
}	t_sub_buffer;

static char	*realloc_line(
		char *line,
		size_t current_length,
		size_t additional_size
)
{
	char	*new_line;
	size_t	i;

	new_line = malloc(sizeof(char) * (current_length + additional_size));
	if (new_line != NULL)
	{
		i = 0;
		while (i < current_length)
		{
			new_line[i] = line[i];
			i++;
		}
	}
	free(line);
	return (new_line);
}

static int	extend_line(
		char **line,
		size_t current_line_len,
		size_t additional_size,
		const char *buffer
)
{
	*line = realloc_line(*line, current_line_len, additional_size + 1);
	if (*line == NULL)
		return (-1);
	ft_strncpy(*line + current_line_len, buffer, additional_size);
	(*line)[current_line_len + additional_size] = '\0';
	return (0);
}

static int	extract_from_buffer(
		t_sub_buffer *sub_buffer,
		char **line,
		size_t *current_line_len)
{
	const char	*line_break;
	size_t		additional_size;
	int			return_value;
	const char	*buffer;

	buffer = sub_buffer->buffer + sub_buffer->start;
	line_break = ft_strnchr(
			buffer,
			'\n',
			sub_buffer->buffer_size - sub_buffer->start
			);
	return_value = 1;
	if (line_break == NULL)
	{
		line_break = sub_buffer->buffer + sub_buffer->buffer_size;
		return_value = 0;
	}
	else
		line_break++;
	additional_size = (line_break - sub_buffer->buffer) - sub_buffer->start;
	if (extend_line(line, *current_line_len, additional_size, buffer) < 0)
		return (free(sub_buffer->buffer), 1);
	*current_line_len += additional_size;
	sub_buffer->start = line_break - sub_buffer->buffer;
	return (return_value);
}

char	*ft_get_next_line(int fd)
{
	static t_sub_buffer	sub_buffer = {.start = 0, .buffer_size = 0};
	char				*line;
	size_t				current_line_len;

	line = NULL;
	current_line_len = 0;
	if (extract_from_buffer(&sub_buffer, &line, &current_line_len))
		return (line);
	sub_buffer.buffer_size = read(fd, sub_buffer.buffer, BUFFER_SIZE);
	if (sub_buffer.buffer_size <= 0 && current_line_len == 0)
	{
		sub_buffer = (t_sub_buffer){.start = 0, .buffer_size = 0};
		return (free(line), NULL);
	}
	sub_buffer.start = 0;
	while (sub_buffer.buffer_size > 0)
	{
		if (extract_from_buffer(&sub_buffer, &line, &current_line_len))
			return (line);
		sub_buffer.buffer_size = read(fd, sub_buffer.buffer, BUFFER_SIZE);
		sub_buffer.start = 0;
	}
	sub_buffer = (t_sub_buffer){.start = 0, .buffer_size = 0};
	return (line);
}
