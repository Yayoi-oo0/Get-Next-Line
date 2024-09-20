/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:34 by oyayoi            #+#    #+#             */
/*   Updated: 2024/09/20 17:28:34 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	c;

	line = (char *)malloc(sizeof(char));
	if (!line)
		return (0);
	*line = '\0';
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		ft_putc(line, c);
		if (c == '\n')
			break ;
	}
	line = ft_putc(line, '\0');
	return (line);
}
