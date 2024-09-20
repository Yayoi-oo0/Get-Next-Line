/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:37 by oyayoi            #+#    #+#             */
/*   Updated: 2024/09/20 17:06:03 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_getc(int fd);
char	*ft_putc(char *str, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#endif