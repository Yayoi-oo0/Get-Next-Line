/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:34 by oyayoi            #+#    #+#             */
/*   Updated: 2024/08/28 19:30:49 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n = 0;

	// char		*line;
	// static char	*save;
	if (n == 0)
	{
		n = read(fd, buf, sizeof(buf));
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
	// if (!buf)
	// 	return (NULL);
	// read(fd, buf, BUFFER_SIZE);
	// line = malloc(sizeof(char) * BUFFER_SIZE);
	// if (!line)
	// 	return (NULL);
	// if (save)
	// {
	// 	line = save;
	// 	save = NULL;
	// }
	// return (line);
}
