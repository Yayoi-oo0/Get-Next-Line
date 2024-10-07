/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyayoi <oyayoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:26 by oyayoi            #+#    #+#             */
/*   Updated: 2024/10/07 17:26:55 by oyayoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, sizeof buf);
		printf("n = %d\n", n);
		if (n < 0)
		{
			bufp = buf;
			n = 0;
			return -1;
		}
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char)*bufp++);
	return (EOF);
}

char	*ft_putc(char *str, char c)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!str && !c)
		return (NULL);
	if (!str)
	{
		newstr = (char *)malloc(sizeof(char) * 2);
		if (!newstr)
			return (NULL);
		newstr[0] = c;
		newstr[1] = '\0';
		return (newstr);
	}
	i = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, str, i);
	newstr[i] = c;
	newstr[i + 1] = '\0';
	free(str);
	return (newstr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	if (dst == NULL && src == NULL)
		return (dst);
	cpy1 = (unsigned char *)dst;
	cpy2 = (unsigned char *)src;
	while (n)
	{
		*cpy1 = *cpy2;
		cpy1++;
		cpy2++;
		n--;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
