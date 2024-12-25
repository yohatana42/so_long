/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_route_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:40:54 by yohatana          #+#    #+#             */
/*   Updated: 2024/12/25 20:51:55 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static void	route_map_init(t_map *map);

int	map_route_search(t_map *map)
{
	int			result;
	t_collect	*object;

	result = 0;
	// PからCまでのルートを探索する
	// 探索用のマップは最初、すべて-1で埋められている
	int	**route_map;
	int	k = 0;

	route_map = (int **)ft_calloc(sizeof(int *), map->hight);

	if (!route_map)
		return (0);
	while (k < map->width)
	{
		route_map[k] = (int *)ft_calloc(sizeof(int), map->width);
		if (!route_map[k])
			return (0);
		k++;
	}
	map->route_map = route_map;
	object = *(map->c_list);
	while (object != NULL)
	{
		printf("t_collect *: %p object->next : %p\n", object, object->next);
		result = route_search_c(map, object, map->player->x, map->player->y);
		if (result == 0)
			error(map, ": No route to 'C', check map");
		object->check_flg = ON;
		object = object->next;
		// 探索用のマップを初期化する
		route_map_init(map);
	}

	// route_search(map, 'E', 'P'の場所);
	result = route_search_e(map, map->exit, map->player->x, map->player->y);
	if (result == 0)
		error(map, "No route to 'E', check map");
	return (1);
}

static void	route_map_init(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->hight)
	{
		j = 0;
		while (j < map->width)
		{
			// printf("i: %d j: %d\n", i, j);
			map->route_map[i][j] = 0;
			// printf("map->route_map[i][j]: %d\n", map->route_map[i][j]);
			j++;
		}
		i++;
	}
}

int	route_search_c(t_map *map, t_collect *object, int cur_x, int cur_y)
{
	int	result1 = 0;
	int	result2 = 0;
	int	result3 = 0;
	int	result4 = 0;

	printf("x: %d y: %d visited: %d\n", cur_x, cur_y, map->route_map[cur_y][cur_x]);

	// 探索用のマップに結果を記入する
	// 探索済みは1, 未探索は0
	if (map->route_map[cur_y][cur_x] == 1)
		return (0);
	map->route_map[cur_y][cur_x] = 1;
	// 最後のマスに来たら探索終了する
	if (cur_x < 0 || map->width < cur_x || cur_y < 0 || map->hight < cur_y)
		return (0);
	// 目的のマスにたどり着いたら終了
	if (cur_x == object->x && cur_y == object->y)
		return (1);
	if (map->map_str[cur_y][cur_x] != WALL)
	{
		if (map->map_str[cur_y][cur_x -1] != WALL)
			result1 = route_search_c(map, object, cur_x -1, cur_y);
		if (map->map_str[cur_y][cur_x +1] != WALL)
			result2 = route_search_c(map, object, cur_x +1, cur_y);
		if (map->map_str[cur_y -1][cur_x] != WALL)
			result3 = route_search_c(map, object, cur_x, cur_y -1);
		if (map->map_str[cur_y +1][cur_x] != WALL)
			result4 = route_search_c(map, object, cur_x, cur_y +1);
		if (result1 == 0 && result2 == 0 && result3 == 0 && result4 == 0)
			return (0);
		if (result1 == 1 || result2 == 1 || result3 == 1 || result4 == 1)
			return (1);
	}
	else
		return (0);
	return (1);
}

int	route_search_e(t_map *map, t_exit *object, int cur_x, int cur_y)
{
	int	result1 = 0;
	int	result2 = 0;
	int	result3 = 0;
	int	result4 = 0;

	if (map->route_map[cur_y][cur_x] == 1)
		return (0);
	map->route_map[cur_y][cur_x] = 1;
	if (cur_x < 0 || map->width < cur_x || cur_y < 0 || map->hight < cur_y)
		return (0);
	if (cur_x == object->x && cur_y == object->y)
		return (1);
	if (map->map_str[cur_y][cur_x] != WALL)
	{
		if (map->map_str[cur_y][cur_x -1] != WALL)
			result1 = route_search_e(map, object, cur_x -1, cur_y);
		if (map->map_str[cur_y][cur_x +1] != WALL)
			result2 = route_search_e(map, object, cur_x +1, cur_y);
		if (map->map_str[cur_y -1][cur_x] != WALL)
			result3 = route_search_e(map, object, cur_x, cur_y -1);
		if (map->map_str[cur_y +1][cur_x] != WALL)
			result4 = route_search_e(map, object, cur_x, cur_y +1);
		if (result1 == 0 && result2 == 0 && result3 == 0 && result4 == 0)
			return (0);
		if (result1 == 1 || result2 == 1 || result3 == 1 || result4 == 1)
			return (1);
	}
	else
		return (0);
	return (1);
}
