/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:33:46 by oyayoi            #+#    #+#             */
/*   Updated: 2024/09/01 18:35:30 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	// line = NULl;
	while (1)
	{
		line = ft_getc(fd);
		if (!line)
			break ;
		printf("%s\n", line);
		// free(line);
	}
	close(fd);
	system("leaks a.out");
	return (0);
}
