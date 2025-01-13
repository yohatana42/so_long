/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:12:48 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/13 18:17:36 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static char	**map_read(int fd);
static int	map_name_check(char *map_name);

int	validation_check(char *map_name, t_map *map)
{
	int		fd;
	char	*path;

	if (map_name_check(map_name) == OK)
	{
		path = ft_strjoin(MAP_PATH, map_name);
		if (!path)
			return (0);
		printf("path: %s\n", path);
		fd = open(path, O_RDONLY);
		printf("fd %d\n", fd);
		if (fd == -1)
			map_error(map, "open file faild");
		map->map_str = map_read(fd);
		printf("-------\n");
		for (int i =0; i < 3;i++)
			printf("%s\n", map->map_str[i]);
		printf("-------\n");
		close(fd);
		free(path);
	}
	else
		map_error(map, "map name is not <.ber> end\n");
	return (1);
}

static char	**map_read(int fd)
{
	char	**map;
	char	map_temp[MAP_MAX_LIMIT];
	size_t	byte;

	map = NULL;
	ft_bzero(map_temp, MAP_MAX_LIMIT);
	byte = read(fd, map_temp, MAP_MAX_LIMIT);
	printf("read byte : %zu\n", byte);
	map = ft_split(map_temp, '\n');
	// map = NULL;
	return (map);
}

// return 0 is NG
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
