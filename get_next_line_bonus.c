/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:11:27 by ehosta            #+#    #+#             */
/*   Updated: 2024/12/16 14:08:48 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	avoid(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*ft_join_line(int nl_index, char **buffer)
{
	char	*res;
	char	*temp;

	temp = NULL;
	if (nl_index <= 0)
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
	temp = ft_substr(*buffer, nl_index, BUFFER_SIZE);
	res = *buffer;
	res[nl_index] = 0;
	*buffer = temp;
	return (res);
}

char	*ft_read_line(int fd, char **buffer, char *read_content)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*nl_ptr;

	nl_ptr = ft_strchr(*buffer, '\n');
	temp = NULL;
	bytes_read = 0;
	while (nl_ptr == NULL)
	{
		bytes_read = read(fd, read_content, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (ft_join_line(bytes_read, buffer));
		read_content[bytes_read] = 0;
		temp = ft_strjoin(*buffer, read_content);
		avoid(buffer);
		*buffer = temp;
		nl_ptr = ft_strchr(*buffer, '\n');
	}
	return (ft_join_line(nl_ptr - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_LIMIT + 1];
	char		*read_content;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_LIMIT)
		return (NULL);
	read_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_content == NULL)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	res = ft_read_line(fd, &buffer[fd], read_content);
	avoid(&read_content);
	return (res);
}
