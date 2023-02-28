/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <lsanglas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:30:22 by lsanglas          #+#    #+#             */
/*   Updated: 2021/12/14 15:30:24 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 42
// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// char	*get_next_line(int fd);
// int	main(int ac, char av)
// {
// 	int	fd;
// 	char	*buff;

// 	for(int i = 0 ; i < 1000 ; i++)
// 	{
// 		buff = get_next_line(42);
// 		if (!buff)
// 			return (0);
// 		free(buff);
// 		buff = NULL;
// 	}

// 	// fd = open("./files/multiple_line_with_nl", O_RDONLY);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	// printf("\n+++++++++++++++++++++++++++++++++++++\n");
// 	// buff = get_next_line(fd);
// 	// buff == NULL ? printf("(null)") : printf("%s", buff);
// 	return (0);
// }

char	*get_next_line_impl(int fd, char **line);

char	*append_line(char **line, char **pb, int fd)
{
	if (*ft_strchr(*pb, '\n'))
	{
		*line = ft_strnjoin(line, *pb, ft_strlen(*pb)
				- (ft_strlen(ft_strchr(*pb, '\n')) - 1));
		*pb = ft_strchr(*pb, '\n') + 1;
		return (*line);
	}
	*line = ft_strnjoin(line, *pb, ft_strlen(*pb));
	*pb = NULL;
	return (get_next_line_impl(fd, line));
}

char	*get_next_line_impl(int fd, char **line)
{
	static char	*pb;
	static char	buff[BUFFER_SIZE + 1];
	int			read_return;

	if (pb && *pb)
	{
		*(*line) = '\0';
		return (append_line(line, &pb, fd));
	}
	read_return = read(fd, buff, BUFFER_SIZE);
	if (read_return < 0)
	{
		free(*line);
		return (NULL);
	}
	buff[read_return] = '\0';
	if (BUFFER_SIZE < 1 || fd < 0 || (read_return < 1 && !*buff))
		return (ft_strnjoin(line, "\0", 0));
	if (read_return < BUFFER_SIZE && pb && *pb)
		return (ft_strnjoin(line, pb, read_return));
	if (read_return < BUFFER_SIZE && !*ft_strchr(buff, '\n'))
		return (ft_strnjoin(line, buff, read_return));
	pb = buff;
	return (append_line(line, &pb, fd));
}

char	*get_next_line(int fd)
{
	char		*line;

	line = malloc(1);
	*line = '\0';
	return (get_next_line_impl(fd, &line));
}
