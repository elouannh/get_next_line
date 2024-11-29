/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:43:33 by ehosta            #+#    #+#             */
/*   Updated: 2024/11/27 15:43:33 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	readbytes;
	ssize_t	bufsize;
	char	*buf;

	bufsize = ft_buffer_size(fd);
	buf = malloc(bufsize * sizeof(char));
	readbytes = read(fd, buf, 10);
	printf("size: %zd, %zd\n", bufsize, readbytes);
	return buf;
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
