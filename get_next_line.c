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
	char	*buf;
	char	*temp;
	size_t	bufsize;

	bufsize = BUFFER_SIZE;
	buf = malloc((bufsize + 1) * sizeof(char));
	readbytes = read(fd, buf, BUFFER_SIZE);
	while (ft_scan_buffer(buf))
	{
		bufsize += BUFFER_SIZE;
		buf = ft_increase_buf(buf, bufsize);
		readbytes = read(fd, buf, BUFFER_SIZE);
		if (readbytes <= 0)
			break ;
	}
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
