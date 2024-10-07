/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:34 by oyayoi            #+#    #+#             */
/*   Updated: 2024/10/07 18:03:14 by okamotoyayo      ###   ########.fr       */
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
		{
			free(line);
			return (NULL);
		}
		line = ft_putc(line, c);
		if (c == '\n')
			break ;
	}
	return (line);
}
