/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:34 by oyayoi            #+#    #+#             */
/*   Updated: 2024/09/22 17:58:21 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	c;

	line = NULL;
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		line = ft_putc(line, c);
		if (c == '\n')
			break ;
	}
	line = ft_putc(line, '\0');
	return (line);
}
