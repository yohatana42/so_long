/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:12:48 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 21:19:42 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	map_read(char *path, t_struct_all *all, int count_line);
static int	map_name_check(char *map_name);
static char	*last_return_to_null(char *buf);
static void	no_read(char *path, char *buf, t_struct_all *all);

int	validation_check(char *map_name, t_struct_all *all)
{
	char	*path;
	int		count_line;

	count_line = 0;
	if (map_name_check(map_name) == OK)
	{
		path = ft_strjoin(MAP_PATH, map_name);
		if (!path)
			return (0);
		count_line = get_count_line(path, all);
		if (count_line < 3)
		{
			free(path);
			return (0);
		}
		map_read(path, all, count_line);
		free(path);
	}
	else
		error_exit(all, "map name is not <.ber> end");
	return (1);
}

static void	map_read(char *path, t_struct_all *all, int count_line)
{
	char	**map_str;
	int		fd;
	char	*buf;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		error_exit(all, "open file faild");
	}
	map_str = (char **)ft_calloc(sizeof(char *), count_line + 1);
	if (!map_str)
		error_exit(all, "mallooc failed");
	i = 0;
	while (i < count_line)
	{
		buf = get_next_line(fd);
		if (ft_strlen(buf) < 1)
			no_read(path, buf, all);
		buf = last_return_to_null(buf);
		map_str[i++] = buf;
	}
	all->map->map_str = map_str;
	close(fd);
}

static void	no_read(char *path, char *buf, t_struct_all *all)
{
	free(path);
	free(buf);
	error_exit(all, "no char in file");
}

static char	*last_return_to_null(char *buf)
{
	int	j;

	j = 0;
	while (buf[j] != '\0')
	{
		if (buf[j] == '\n')
			buf[j] = '\0';
		j++;
	}
	return (buf);
}

static int	map_name_check(char *map_name)
{
	size_t	len;
	char	*pointer;

	len = ft_strlen(map_name);
	pointer = ft_strnstr(map_name, BER_EXTE, len);
	if (pointer == &map_name[len - 4])
		return (1);
	else
		return (0);
}
