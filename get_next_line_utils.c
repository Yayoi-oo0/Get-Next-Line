/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamotoyayoi <okamotoyayoi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:46:26 by oyayoi            #+#    #+#             */
/*   Updated: 2024/09/13 19:05:46 by okamotoyayo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
	static int	n;

	if (n == 0)
	{
		n = read(fd, buf, sizeof buf);
		if (n < 0)
			return (0);
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char) *bufp++);
	return (EOF);
}

int	ft_putc(char *str, char c)
{
	char	*newstr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	newstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!newstr)
		return (0);
	ft_memcpy(newstr, str, i);
	newstr[i] = c;
	free(newstr);
	return (1);
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
