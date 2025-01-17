/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:12:48 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 20:09:08 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// static int	get_count_line(char *path, t_struct_all *all);
static void	map_read(char *path, t_struct_all *all, int count_line);
static int	map_name_check(char *map_name);
static char	*last_return_to_null(char *buf);

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
		map_read(path, all, count_line);
		free(path);
	}
	else
		error_exit(all, "map name is not <.ber> end");
	return (1);
}

// static int	get_count_line(char *path, t_struct_all *all)
// {
// 	int		count_line;
// 	int		fd;
// 	char	str[BUF_SIZE];
// 	int		result;
// 	int		i;

// 	count_line = 1;
// 	i = 0;
// 	ft_bzero(str, BUF_SIZE);
// 	fd = open(path, O_RDONLY);
// 	while (1)
// 	{
// 		result = read(fd, str, BUF_SIZE);
// 		if (result < 0)
// 			free_path(path, all, "open file faild");
// 		else if (result == 0)
// 			break ;
// 		while (str[i] != '\0')
// 		{
// 			if (str[i] == '\n' && str[i + 1] != '\0')
// 				count_line++;
// 			i++;
// 		}
// 	}
// 	close(fd);
// 	return (count_line);
// }

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
		buf = last_return_to_null(buf);
		map_str[i] = buf;
		i++;
	}
	all->map->map_str = map_str;
	close(fd);
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

// void	free_path(char *path, t_struct_all *all, char *str)
// {
// 	free(path);
// 	error_exit(all, str);
// }

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
