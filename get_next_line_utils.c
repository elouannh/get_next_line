/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:46:51 by ehosta            #+#    #+#             */
/*   Updated: 2024/11/29 09:46:51 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	if (!*s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_is_endol(const char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_increase_buf(char *buf, size_t newsize)
{
	char	*newbuf;
	size_t	i;

	newbuf = malloc((newsize + 1) * sizeof(char));
	if (!newbuf)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (buf[i])
	{
		newbuf[i] = buf[i];
		i++;
	}
	free(buf);
	return (newbuf);
}
