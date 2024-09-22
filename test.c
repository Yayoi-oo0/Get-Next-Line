/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:33:46 by oyayoi            #+#    #+#             */
/*   Updated: 2024/09/22 17:03:16 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*c;

	fd = open("test.txt", O_RDONLY);
	c = NULL;
	while (1)
	{
		c = get_next_line(fd);
		if (c == NULL)
			break ;
		printf("%s", c);
	}
	close(fd);
	system("leaks a.out");
	return (0);
}
