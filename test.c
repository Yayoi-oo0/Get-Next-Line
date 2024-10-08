/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:33:46 by oyayoi            #+#    #+#             */
/*   Updated: 2024/10/08 17:59:21 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*c;

	if (argc == 2)
	{
		fd = 0;
		open(argv[1], O_RDONLY);
		printf("fd: %d\n", fd);
	}
	else
		fd = open("test.txt", O_RDONLY);
	c = NULL;
	while (1)
	{
		c = get_next_line(0);
		if (!c)
			break ;
		printf("%s", c);
	}
	close(fd);
	system("leaks a.out");
	free(c);
	return (0);
}

// #include <fcntl.h>
// #include <stdio.h>

// void    loop(int fd)
// {
//     char    *ret;

//     while (1)
//     {
//         ret = get_next_line(fd);
//         printf("%s", ret);
//         if (ret == NULL)
//             break;
//         free(ret);
//     }
//     free(ret);

//     printf("\n");
// }



// int        get_fd(char *file_name)
// {
//     int fd = open(file_name, O_RDWR);
    
//     if (fd == -1)
//         return printf("Error: fd\n");

//     return fd;
// }

// int        main(int argc, char **argv)
// {
//     int        fd;
//     char    *file_name = "get_next_line.c";

//     if (argc == 2)
//         file_name = argv[1];
    
//     fd = get_fd(file_name);
//     loop(fd);

//     close(fd);
//     fd = get_fd(file_name);
//     loop(fd);
//     close(fd);
//     // system("leaks a.out");
// }