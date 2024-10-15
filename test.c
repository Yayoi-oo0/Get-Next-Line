/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:33:46 by oyayoi            #+#    #+#             */
/*   Updated: 2024/10/15 20:05:51 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int		fd1, fd2;
    char	*line1, *line2;

    if (argc < 3)
    {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return (1);
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening file1");
        return (1);
    }

    fd2 = open(argv[2], O_RDONLY);
    if (fd2 == -1)
    {
        perror("Error opening file2");
        close(fd1);
        return (1);
    }

    while (1)
    {
        line1 = get_next_line(fd1);
        if (line1)
        {
            printf("%s", line1);
            free(line1);
        }

        line2 = get_next_line(fd2);
        if (line2)
        {
            printf("%s", line2);
            free(line2);
        }

        if (!line1 && !line2)
            break;
    }

    close(fd1);
    close(fd2);

    return (0);
}
// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*c;

// 	if (argc == 2)
// 	{
// 		fd = 0;
// 		open(argv[1], O_RDONLY);
// 	}
// 	else
// 		fd = open("test.txt", O_RDONLY);
// 	c = NULL;
// 	while (1)
// 	{
// 		c = get_next_line(fd);
// 		if (!c)
// 			break ;
// 		printf("%s", c);
// 		free(c);
// 	}
// 	close(fd);
// 	system("leaks a.out");
// 	return (0);
// }

// hirosuzu's test
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