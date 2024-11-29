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

ssize_t	ft_buffer_size(int fd)
{
	char	*buf;
	ssize_t	i;

	i = 0;
	buf = "";
	while (read(fd, buf, i) > 0);
	printf("[%s]\n", buf);
	return (i);
}
