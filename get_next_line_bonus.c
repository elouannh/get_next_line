/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:26:48 by prafael-          #+#    #+#             */
/*   Updated: 2024/12/11 18:00:04 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_avoid(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*ft_join_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	res = *buffer;
	res[nl_position] = 0;
	*buffer = tmp;
	return (res);
}

char	*ft_read_line(int fd, char **buffer, char *read_return)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_join_line(bytes_read, buffer));
		read_return[bytes_read] = 0;
		tmp = ft_strjoin(*buffer, read_return);
		ft_avoid(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (ft_join_line(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_LIMIT + 1];
	char		*read_return;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_LIMIT)
		return (NULL);
	read_return = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_return == NULL)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	res = ft_read_line(fd, &buffer[fd], read_return);
	ft_avoid(&read_return);
	return (res);
}
