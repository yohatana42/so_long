/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:36:45 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/18 18:10:50 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static char	**map_read(int fd);
static int	map_name_check(char *map_name);
// static int	map_charactaer_check(t_map *map);

t_map	*map_check(char *map_name, t_map *map)
{
	int		fd;
	char	*path;

	if (map_name_check(map_name))
	{
		path = ft_strjoin(MAP_PATH, map_name);
		if (!path)
			return (NULL);
		printf("map path: %s\n", path);
		fd = open(path, O_RDONLY);
		printf("fd %d\n", fd);
		if (fd == -1)
			perror("open file faild");
		map->map_str = map_read(fd);

		printf("-------\n");
		for (int i =0; i < 3;i++)
			printf("%s\n", map->map_str[i]);
		printf("-------\n");

		if (map_charactaer_check(map))
		{
			printf("ok\n");
		}
		else
		{
			printf("NG\n");
		}
		close(fd);
		free(path);
	}
	else
	{
		perror("map name is not <.ber> end");
		all_free(map);
	}
	return (map);
}

static char	**map_read(int fd)
{
	char	**map;
	char	map_temp[MAP_MAX_LIMIT];
	size_t	byte;

	byte = read(fd, map_temp, MAP_MAX_LIMIT);
	printf("read byte : %zu\n", byte);
	map = ft_split(map_temp, '\n');
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

