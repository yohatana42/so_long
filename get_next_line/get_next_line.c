/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:59:40 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/14 18:43:03 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static int	get_char(int fd, t_string *string_p);
static int	create_line(char read_char, t_string *string_p);
static char	*free_all(t_string *string_p);

char	*get_next_line(int fd)
{
	static t_string	string;
	t_string		*string_p;
	char			read_char;

	if (fd < 0)
		return (NULL);
	string_p = &string;
	string_p->left_line = NULL;
	while (1)
	{
		read_char = get_char(fd, string_p);
		if (read_char == -1)
			return (free_all(string_p));
		if (read_char == EOF)
			break ;
		if (create_line(read_char, string_p))
			return (free_all(string_p));
		if (read_char == '\n')
			break ;
	}
	if (create_line('\0', string_p))
		return (free_all(string_p));
	string_p->capa = 0;
	return (string_p->left_line);
}

static int	get_char(int fd, t_string *string_p)
{
	if (string_p->read_result == 0)
	{
		string_p->read_result = read(fd, string_p->buf, BUFFER_SIZE);
		string_p->read_str = string_p->buf;
	}
	if (string_p->read_result < 0)
		return (-1);
	if (--string_p->read_result >= 0)
		return ((unsigned char) *string_p->read_str++);
	else
		return (EOF);
}

static int	create_line(char read_char, t_string *string_p)
{
	char	*new_line;
	size_t	len;

	len = ft_strlen(string_p->left_line);
	if (len + 1 > string_p->capa)
	{
		if (len == 0)
			string_p->capa = BUFFER_SIZE * sizeof(char);
		string_p->capa = string_p->capa * 2;
		new_line = (char *)malloc(string_p->capa + 1);
		ft_bzero(new_line, string_p->capa + 1);
		if (!new_line)
			return (1);
		ft_memset(new_line, 0, string_p->capa + 1);
		ft_strlcpy(new_line, string_p->left_line, len);
		free(string_p->left_line);
		string_p->left_line = new_line;
	}
	string_p->left_line[len] = read_char;
	return (0);
}

static char	*free_all(t_string *string_p)
{
	if (!string_p->left_line)
		free(string_p->left_line);
	return (NULL);
}
