/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:50:38 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/23 22:03:39 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wall_check(t_map *map);
static int	count_char(t_map *map, char c, int x, int y);
// int	route_search(t_map *map, char object, int cur_x, int cur_y);

// return 1 is OK
int	map_charactaer_check(t_map *map)
{
	int	i;
	int	j;
	int result;
	t_collect	*object;

	i = 0;
	j = 0;
	result = 0;
	map->width = (int)ft_strlen(map->map_str[0]);
	map->hight = get_map_hight(map);
	if (!wall_check(map))
		return (0);

	while (map->map_str[i] != NULL)
	{
		j = 0;
		while (j < map->width)
		{
			if (!count_char(map, map->map_str[i][j], j, i))
			{
				perror("Error\n : this is not char");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (map->count->p != 1 || map->count->e != 1 || map->count->c < 1)
	{
		if (map->count->p > 1)
			error(map, "map is NOT perfect.'P' more than 1");
		if (map->count->e > 1)
			error(map, "map is NOT perfect.'E' more than 1");
		if (map->count->c < 1)
			error(map, "map is NOT perfect.'C' less than 1");
		return (0);
	}


	printf("P :%d C :%d E :%d\n", map->count->p, map->count->c, map->count->e);

	// PからCまでのルートを探索する
	object = *(map->c_list);

	// printf("c_list: %p\n", map->c_list);
	// printf("object: %p\n", object);
	// printf("object: %p object->next : %p\n", *(map->c_list), object->next);

	// ここで無限ループしてる
	// object->nextがNULLかどうか確認するべき

	while (object != NULL)
	{
		printf("t_collect *: %p object->next : %p\n", object, object->next);
		// result = route_search_c(map, object, map->player->x, map->player->y);
		// if (result == 0)
		// 	error(map, "Error\n : No route to 'C', check map");
		object->check_flg = ON;
		object = object->next;
		printf("t_collect *: %p\n", object);
	}

	// route_search(map, 'E', 'P'の場所);
	// result = route_search(map, 'E', map->player->x, map->player->y);
	// if (result == 0)
	// 	perror("Error\n : No route to 'E', check map");

	return (1);
}

static int	wall_check(t_map *map)
{
	// size_t	i;
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < map->hight)
	{
		line = map->map_str[i];
		printf("i : %d str: %s\n", i, map->map_str[i]);
		printf("map->hight :%d map->width: %d\n", map->hight, map->width);
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

// static int	count_char(t_map *map)
static int	count_char(t_map *map, char c, int x, int y)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != WALL && c != SPACE)
		return (0);
	if (c == 'P')
	{
		map->count->p = map->count->p + 1;
		map->player->x = x;
		map->player->y = y;
	}
	if (c == 'E')
	{
		map->count->e = map->count->e + 1;
		map->exit->x = x;
		map->exit->y = y;
	}
	if (c == 'C')
	{
		map->count->c = map->count->c + 1;
		map->c_list = add_node(create_new(x, y), map->c_list);
		printf("%p %p\n", map->c_list, *(map->c_list));
	}
	return (1);
}


int	get_map_hight(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_str[i] != NULL)
		i++;
	return (i);
}

// 幅優先と思いきや深さ優先であった
int	route_search_c(t_map *map, t_collect *object, int cur_x, int cur_y)
{
	int	result1;
	int	result2;
	int	result3;
	int	result4;
	int	done_flg = 0;

	int	**route_map;

	route_map = (int **)malloc(sizeof(int *) * map->hight);

	printf("x: %d y: %d\n", cur_x, cur_y);

	// 最後のマスに来たら探索終了する
	if (cur_x < 0 || map->width < cur_x || cur_y < 0 || map->hight < cur_y)
		return (0);
	if (cur_x == object->x && cur_y == object->y)
		return (1);
	// どんどこ一方向に進んでいく
	// 進めなかったら別方向にいく

	// 探索用のマップに結果を記入する
	// 探索用のマップは最初、すべて-1で埋められている
	map->route_map[cur_y][cur_x] = 0;


	if (map->map_str[cur_x -1][cur_y] == WALL)
		result1 = 0;
	else
		result1 = route_search_c(map, object, cur_x -1, cur_y);
	if (map->map_str[cur_x +1][cur_y] == WALL)
		result2 = 0;
	else if (cur_x +1 == object->x && cur_y == object->y)
		return (1);
	else
		result2 = route_search_c(map, object, cur_x +1, cur_y);
	if (map->map_str[cur_x][cur_y -1] == WALL)
		result3 = 0;
	else if (cur_x == object->x && cur_y -1 == object->y)
		return (1);
	else
		result3 = route_search_c(map, object, cur_x, cur_y -1);
	if (map->map_str[cur_x][cur_y +1] == WALL)
		result4 = 0;
	else if (cur_x == object->x && cur_y +1 == object->y)
		return (1);
	else
		result4 = route_search_c(map, object, cur_x, cur_y +1);
	if (result1 == 0 && result2 == 0 && result3 == 0 && result4 == 0)
		return (0);
	return (1);
}
