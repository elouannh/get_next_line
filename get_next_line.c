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
	ssize_t		readbytes;
	static char	buf[BUFFER_SIZE + 1];

	readbytes = read(fd, buf, BUFFER_SIZE);
	while (!ft_is_endol(buf))
	{
		readbytes = read(fd, buf, BUFFER_SIZE);
	}
	return (buf);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
