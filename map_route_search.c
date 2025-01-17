/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_route_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohatana <yohatana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:40:54 by yohatana          #+#    #+#             */
/*   Updated: 2025/01/17 19:47:15 by yohatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	map_route_search(t_struct_all *all)
{
	int		result;
	int		**route_map;
	int		k;

	result = 0;
	k = 0;
	route_map = (int **)ft_calloc(sizeof(int *), all->map->hight);
	if (!route_map)
		error_exit(all, "malloc error");
	while (k < all->map->hight)
	{
		route_map[k] = (int *)ft_calloc(sizeof(int), all->map->width);
		if (!route_map[k])
			error_exit(all, "malloc error");
		k++;
	}
	all->map->route_map = route_map;
	search_c(all);
	result = route_search_e(all->map, all->game->exit,
			all->game->player->x, all->game->player->y);
	if (result == 0)
		error_exit(all, "No route to 'E', check map");
	return (1);
}

void	route_map_init(t_map *map)
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
			map->route_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	route_search_e(t_map *map, t_exit *object, int cur_x, int cur_y)
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
		result = search_e_helper(map, object, cur_x, cur_y);
		return (result);
	}
	else
		return (0);
	return (1);
}

int	search_e_helper(t_map *map, t_exit *object, int cur_x, int cur_y)
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
	return (0);
}
