/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:34 by oyayoi            #+#    #+#             */
/*   Updated: 2024/10/15 19:47:46 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	c;

	line = NULL;
	c = 0;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		if (c == -2)
			return (free(line), NULL);
		line = ft_putc(line, c);
		if (c == '\n')
			break ;
		if (!line)
			return (NULL);
	}
	return (line);
}
