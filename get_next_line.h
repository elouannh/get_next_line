/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:30:17 by ehosta            #+#    #+#             */
/*   Updated: 2024/11/29 09:30:17 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 1024
#endif

ssize_t	ft_strlen(const char *s);
int	ft_is_endol(const char *str);
char	*ft_increase_buf(char *buf, size_t newsize);

#endif
