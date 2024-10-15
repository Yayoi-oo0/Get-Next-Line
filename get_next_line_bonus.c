/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:29:44 by oyayoi            #+#    #+#             */
/*   Updated: 2024/10/16 00:45:01 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	c;

	line = NULL;
	c = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		if (c == -2)
		{
			free(line);
			return (NULL);
		}
		line = ft_putc(line, c);
		if (!line)
			return (NULL);
		if (c == '\n')
			break ;
	}
	return (line);
}
