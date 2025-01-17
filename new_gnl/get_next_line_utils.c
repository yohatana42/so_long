/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:00:10 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/14 18:42:01 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*p;

	a = c;
	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		*p = a;
		p++;
		i++;
	}
	return (b);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest));
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
