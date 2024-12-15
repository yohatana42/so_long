/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:36:45 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/15 19:20:51 by yohatana         ###   ########.fr       */
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

// static int	map_charactaer_check(t_map *map)
// {
// 	int		i;
// 	int		j;
// 	char	c;

// 	j = 0;
// 	i = 0;
// 	// 1行ずつ読み込む
// 	map->width = ft_strlen(map->map_str[0]);
// 	// ついでに高さも取得する
// 	while (map->map_str[i] != NULL)
// 	{
// 		printf("i : %d str: %s\n", i, map->map_str[i]);
// 		// 1行目は壁
// 		if (i == 0 && !wall_check(map->map_str[i]))
// 			return (0);
// 		// 必要な文字の種類があれば構造体に記載
// 		while (j < map->width)
// 		{
// 			c = map->map_str[i][j];
// 			if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0')
// 			{
// 				printf("mojiha atteru\n");
// 				if (c == 'P')
// 				{
// 					map->player = map->player + 1;
// 				}
// 				if (c == 'E')
// 				{
// 					map->exit = map->exit + 1;
// 				}
// 				if (c == 'C')
// 				{
// 					map->corection = map->corection + 1;
// 				}
// 			}
// 			else
// 				return (0);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}

// 	// PからCまでのルートを探索する
// 	// 幅優先探索か深さ優先探索でｐからEまでのルートを確保する

// 	// 最後まで読んで必要な文字が足りないか確認
// 	return (1);
// }

// int	wall_check(char *line)
// {
// 	size_t	i;

// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] != WALL)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
