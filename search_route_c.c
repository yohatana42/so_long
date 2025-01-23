/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_search_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:14:43 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 19:48:09 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	search_c(t_struct_all *all)
{
	int			result;
	t_collect	*object;

	result = 0;
	object = *(all->game->c_list);
	while (object != NULL)
	{
		object = object->next;
		route_map_init(all->map);
	}
}

int	route_search_c(t_map *map, t_collect *object, int cur_x, int cur_y)
{
	int	result;

	result = 0;
	if (map->route_map[cur_y][cur_x] == 1)
		return (0);
	map->route_map[cur_y][cur_x] = 1;
	if (cur_x < 0 || map->width < cur_x || cur_y < 0 || map->hight < cur_y)
		return (0);
	if (cur_x == object->x && cur_y == object->y)
		return (1);
	if (map->map_str[cur_y][cur_x] != WALL)
	{
		result = search_c_helper(map, object, cur_x, cur_y);
		return (result);
	}
	else
		return (0);
	return (1);
}

int	search_c_helper(t_map *map, t_collect *object, int cur_x, int cur_y)
{
	int	result1;
	int	result2;
	int	result3;
	int	result4;

	result1 = 0;
	result2 = 0;
	result3 = 0;
	result4 = 0;
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
	return (0);
}
