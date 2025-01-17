/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:00:00 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/14 18:43:21 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// # define ERROR -2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_string
{
	char	buf[BUFFER_SIZE];
	char	*read_str;
	int		read_result;
	char	*left_line;
	size_t	capa;
}	t_string;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
