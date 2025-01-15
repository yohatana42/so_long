/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:12:48 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/15 14:57:22 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// static char	**map_read(int fd);
static int	get_count_line(char *path, t_struct_all *all);
static void	map_read(char *path, t_struct_all *all, int count_line);
static int	map_name_check(char *map_name);

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
		printf("count_line %d\n", count_line);
		map_read(path, all, count_line);
		free(path);
	}
	else
		error_exit(all, "map name is not <.ber> end\n");
	return (1);
}

static int	get_count_line(char *path, t_struct_all *all)
{
	int		count_line;
	int		fd;
	char	str[BUF_SIZE];
	int		result;
	int		i;

	count_line = 1;
	result = 0;
	i = 0;
	ft_bzero(str, BUF_SIZE);
	fd = open(path, O_RDONLY);
	while (1)
	{
		result = read(fd, str, BUF_SIZE);
		printf("read result %d\n", result);
		if (result < 0)
		{
			close(fd);
			error_exit(all, "read error");
		}
		else if (result == 0)
			break ;
		while (str[i] != '\0')
		{
			// printf("str[i] %c\n", str[i]);
			if (str[i] == '\n' && str[i + 1] != '\0')
				count_line++;
			i++;
		}
	}
	close(fd);
	printf("count_line %d\n", count_line);
	return (count_line);
}

static void	map_read(char *path, t_struct_all *all, int count_line)
{
	char	**map_str;
	int		fd;
	char	*buf;
	int		i;
	int		j;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit(all, "open file faild");
	map_str = (char **)ft_calloc(sizeof(char *), count_line + 1);
	if (!map_str)
		error_exit(all, "mallooc failed");
	i = 0;
	while (i < count_line)
	{
		buf = get_next_line(fd);
		j = 0;
		while (buf[j] != '\0')
		{
			if (buf[j] == '\n')
				buf[j] = '\0';
			j++;
		}
		map_str[i] = buf;
		i++;
	}
	all->map->map_str = map_str;
	close(fd);
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
