/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:36:45 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/13 16:57:50 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	wall_check(t_map *map);
static int	count_char(t_map *map, char c, int x, int y);

int	map_check(char *map_name, t_map *map)
{
	(void)map_name;

	map->width = (int)ft_strlen(map->map_str[0]);
	map->hight = get_map_hight(map);
	if (!wall_check(map))
		return (0);
	if (map_charactaer_check(map) == OK)
	{
		printf("ok\n");
		// game start
	}
	return (1);
}

int	map_charactaer_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_str[i] != NULL)
	{
		j = 0;
		while (j < map->width)
		{
			if (count_char(map, map->map_str[i][j], j, i) == 0)
				map_error(map, "Error\n : this is not map char");
			j++;
		}
		i++;
	}
	if (map->count_p != 1 || map->count_e != 1 || map->count_c < 1)
	{
		map_error(map, "map is NOT perfect.'C' or 'P' or 'E' is NOT ");
		return (0);
	}
	printf("map_charactaer_check\n");
	// printf("P :%d C :%d E :%d\n", map->count->p, map->count->c, map->count->e);
	map_route_search(map);
	printf("map_route_seach end\n");
	return (1);
}

static int	wall_check(t_map *map)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < map->hight)
	{
		line = map->map_str[i];
		if (i == 0 || i == map->hight -1)
		{
			j = 0;
			while (line[j] != '\0')
			{
				if (line[j] != WALL)
					return (0);
				j++;
			}
		}
		if (line[0] != WALL || line[ft_strlen(line) - 1] != WALL)
			return (0);
		i++;
	}
	i = 0;
	return (1);
}

static int	count_char(t_map *map, char c, int x, int y)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != WALL && c != SPACE)
		return (0);
	if (c == 'P')
	{
		map->count_p = map->count_p + 1;
		map->player->x = x;
		map->player->y = y;
	}
	if (c == 'E')
	{
		map->count_e = map->count_e + 1;
		map->exit->x = x;
		map->exit->y = y;
	}
	if (c == 'C')
	{
		map->count_c = map->count_c + 1;
		map->c_list = add_node(create_new(x, y), map->c_list);
	}
	return (1);
}

