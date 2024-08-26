/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:34 by oyayoi            #+#    #+#             */
/*   Updated: 2024/08/26 16:56:57 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*save;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	line = malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	if (save)
	{
		line = save;
		save = NULL;
	}
	return (line);
}
