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

int	ft_scan_buffer(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (i != (int)ft_strlen(str))
		return (0);
	return (1);
}

char	*ft_skip_lines(const char *str, int lines)
{
	while (lines > 0)
	{
		if (!*str)
			return (NULL);
		if (*str == '\n')
			lines--;
		str++;
	}
}
